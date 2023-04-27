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

layout (std430, binding = 1) buffer ObjBlock {
    Object3D objects[];
} objBlock;

layout(std430, binding = 2) buffer LightBlock {
    Light lights[];
} lightBlock;

vec4 getColorFromLight(vec3 lightDir, vec3 normal, vec3 lightColor, vec3 viewDir, int objIndex);

// Returns the color value of the point after applying lighting using the BlinnPhong Algorithm
// assums that the object is a sphere for now
vec4 applyLight(Light light, float t, int objIndex, vec3 dir, vec3 orig) {
    vec3 intersection = orig + t * dir;
    vec3 normal = normalize(intersection - objBlock.objects[objIndex].position); // TODO: this is only for spheres
    vec3 lightDir = normalize(light.position - intersection);
    vec3 viewDir = normalize(dir);

    // TODO SHADOWS
    vec4 color = getColorFromLight(lightDir, normal, light.color, viewDir, objIndex);
    return color;
}
