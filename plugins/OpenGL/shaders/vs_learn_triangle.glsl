#version 430 core
layout (location = 0) in vec3 aPos;
layout (std140, binding = 1) buffer ObjectsBlock {
    int type;
    vec3 args[];
} objectsBlock;

void main()
{
    // gl_Position is a special variable used to store the final position,
    // outputed by the vertex shader.
    gl_Position = vec4(objectsBlock.args[0].x, objectsBlock.args[0].y, objectsBlock.args[0].z, 1.0);
}
