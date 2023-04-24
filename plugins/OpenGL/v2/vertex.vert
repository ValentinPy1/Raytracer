#version 430 core

struct Object3D {
    vec3 position;
    vec3 rotation;
};

struct Light {
    vec3 position;
    vec3 color;
    float radius;
};

layout (location = 0) in vec2 aPos;

layout (std430, binding = 1) buffer ObjBlock {
    Object3D objects[];
} objBlock;

layout(std430, binding = 2) buffer LightBlock {
    Light lights[];
} lightBlock;


uniform vec3 focalPoint;

out vec3 rayDir;

void main()
{
    // gl_Position is a special variable used to store the final position,
    // outputed by the vertex shader.
    rayDir = normalize(vec3(aPos.xy, 0.0f) - focalPoint);
    gl_Position = vec4(aPos.x, aPos.y, 0.0f, 1.0f);
}
