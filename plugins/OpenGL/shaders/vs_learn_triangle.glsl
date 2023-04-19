#version 330 core
layout (location = 0) in vec3 aPos;

void main()
{
    // gl_Position is a special variable used to store the final position,
    // outputed by the vertex shader.
    gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);
}
