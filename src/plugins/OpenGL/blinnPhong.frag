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

layout (std430, binding = 1) buffer ObjBlock {
    Triangle objects[];
} objBlock;

layout(std430, binding = 2) buffer LightBlock {
    Light lights[];
} lightBlock;


// BLINN-PHONG SHADING VERSION OF THE FUNCTION; DO NOT USE ALONGSIDE ANOTHER SHADER
// IMPLEMENTING THE SAME FUNCTION
vec4 getColorFromLight(vec3 lightDir, vec3 normal, vec3 lightColor, vec3 viewDir, int objIndex)
{
    float diffuse = max(dot(normal, lightDir), 0.0);
    vec3 halfwayDir = normalize(lightDir + viewDir);
    float specular = pow(max(dot(normal, halfwayDir), 0.0), 1.0); // TODO get the shininess from the material
    float attenuation = 1.0 / (1.0 + 0.1 * pow(length(lightDir), 2.0));
    return vec4(lightColor * (diffuse + specular) * attenuation, 1.0);
}
