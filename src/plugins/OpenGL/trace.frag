#version 430 core

struct Sphere {
    vec3 center;
    float radius;
};

struct Object3D {
    vec3 position;
    vec3 rotation;
};

struct Light {
    vec3 position;
    vec3 color;
    float radius;
};

struct Intersection {
    float t;
    int objIndex;
    vec3 normal;
};

layout (std430, binding = 1) buffer ObjBlock {
    Object3D objects[];
} objBlock;

layout(std430, binding = 2) buffer LightBlock {
    Light lights[];
} lightBlock;


// FUNCION DEFINITIONS
/**
* These functions are prototypes for functions that will be defined in other files.
* This allows the user to choose which implementation to use for each function.
*/
vec4 applyLight(Light light, float t, int objIndex, vec3 dir, vec3 orig);
Intersection findClosestIntersection(vec3 dir, vec3 orig);
vec4 blendMultiply(vec4 c1, vec4 c2);
vec4 blendAdd(vec4 c1, vec4 c2);
// vec4 getReflectionColor(vec3 dir, vec3 orig, vec3 normal, int objIndex, int depth);

vec4 traceRay(vec3 orig, vec3 dir, int reflectDepth) {
    vec4 finalColor = vec4(0.0f, 0.0f, 0.0f, 1.0f);
    int oldObjIndex = -1;

    for (int rec = 0; rec < reflectDepth; rec++) {

        Intersection inter = findClosestIntersection(dir, orig);
        while (inter.objIndex == oldObjIndex) {
            orig = orig + (inter.t + 0.01f) * dir;
            float t = inter.t;
            inter = findClosestIntersection(dir, orig);
            if (inter.t <= 0) {
                return finalColor;
            }
            inter.t += t;
            oldObjIndex = inter.objIndex;
        }

        if (inter.t <= 0) {
            return finalColor;
        }

        vec4 color = vec4(0.0f, 0.2f, 0.0f, 1.0f); // TODO: base color from material
        if (inter.objIndex == 1) {
            color = vec4(0.0f, 0.0f, 0.2f, 1.0f);
        }

        color = blendAdd(color, applyLight(lightBlock.lights[0], inter.t, inter.objIndex, dir, orig));
        orig = orig + (inter.t) * dir;
        dir = reflect(dir, inter.normal);
        finalColor = blendAdd(finalColor, 0.3 * color);
    }
    return finalColor;
}
