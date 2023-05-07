#version 430 core

struct Triangle {
    vec3 p1;
    vec3 p2;
    vec3 p3;
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

// SHADER SPECIFIC VARIABLES
uniform vec3 focalPoint;
in vec3 rayDir;
out vec4 FragColor;

vec4 traceRay(vec3 focalPoint, vec3 rayDir, int reflectDepth);

// IMPL
void main() {
    FragColor = vec4(0.0f, 0.1f, 0.1f, 1.0f);

    FragColor = traceRay(focalPoint, rayDir, 3);
}
