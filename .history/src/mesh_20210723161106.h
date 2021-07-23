#pragma once

#include "shader.h"

class Mesh {
private:
    unsigned int VAO, VBO;

public:
    Mesh(float *vertices){
        glGenVertexArrays(1, &VAO);
        glGenBuffers(1, &VBO);
        glBindVertexArray(VAO);

        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glBufferData(GL_ARRAY_BUFFER, sizeof(float) * 9, vertices, GL_STATIC_DRAW);

        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
        glEnableVertexAttribArray(0);

        glBindBuffer(GL_ARRAY_BUFFER, 0); 
        glBindVertexArray(0); 
    }

    ~Mesh(){
        glDeleteVertexArrays(1, &VAO);
        glDeleteBuffers(1, &VBO);
    }

    void draw(Shader& shader){
        glBindVertexArray(VAO);
        shader.use();
        glDrawArrays(GL_TRIANGLES, 0, 3);
    }
};