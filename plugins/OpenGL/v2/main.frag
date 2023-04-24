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
};

layout (std430, binding = 1) buffer ObjBlock {
    Object3D objects[];
} objBlock;

layout(std430, binding = 2) buffer LightBlock {
    Light lights[];
} lightBlock;

// SHADER SPECIFIC VARIABLES
uniform vec3 focalPoint;
in vec3 rayDir;
out vec4 FragColor;

// FUNCION DEFINITIONS
vec4 applyLight(Light light, float t, int objIndex, vec3 dir, vec3 orig);
Intersection findClosestIntersection();

// IMPL
void main() {
    FragColor = vec4(0.0f, 0.1f, 0.1f, 1.0f);

    Intersection inter = findClosestIntersection();
    if (inter.t > 0) {
        FragColor = vec4(1.0f, 0.0f, 0.0f, 1.0f);
        FragColor = applyLight(lightBlock.lights[0], inter.t, inter.objIndex, rayDir, focalPoint); // TODO OBJ INDEX?
    }
}
