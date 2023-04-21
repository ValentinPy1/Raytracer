#version 430 core
layout (location = 0) in vec3 aPos;
layout (std140, binding = 1) buffer ObjectsBlock {
    int type;
    vec3 args[];
} objectsBlock;
uniform vec3 focalPoint;
out vec3 rayDir;


void main()
{
    // gl_Position is a special variable used to store the final position,
    // outputed by the vertex shader.
    rayDir = normalize(aPos - focalPoint);
    gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);
}
