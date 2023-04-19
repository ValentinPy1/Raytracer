float vertices[] = {
    -0.5f, -0.5f, 0.0f,
     0.5f, -0.5f, 0.0f,
     0.0f,  0.5f, 0.0f
};

// The VBO containing the 3 vertices
unsigned int VBO;
glGenBuffers(1, &VBO); // Generate one buffer and store the ID in VBO


/*
Bind the VBO to the GL_ARRAY_BUFFER target.
GL_ARRAY_BUFFER is a buffer type, for a vertex buffer.
Until we bind a different buffer to GL_ARRAY_BUFFER, all buffer calls
will be used to configure the currently bound buffer, which is VBO.
*/
glBindBuffer(GL_ARRAY_BUFFER, VBO);

/*
The fourth parameter specifies how we want the graphics card to manage the given data. This can take 3 forms:

GL_STREAM_DRAW: the data is set only once and used by the GPU at most a few times.
GL_STATIC_DRAW: the data is set only once and used many times.
GL_DYNAMIC_DRAW: the data is changed a lot and used many times.
*/
glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
