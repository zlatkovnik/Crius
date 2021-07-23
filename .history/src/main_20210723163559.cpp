#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>

#include "shader.h"
#include "mesh.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow *window);

// settings
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

int main()
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

    // glfw window creation
    // --------------------
    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    {
        float vertices[] = {
            -0.5f, -0.5f, 0.0f, // left  
            0.5f, -0.5f, 0.0f, // right 
            0.0f,  0.5f, 0.0f  // top   
        }; 

        Mesh cube(vertices);

        Shader basicShader("./src/res/shaders/basic.vert", "./src/res/shaders/basic.frag");

        while (!glfwWindowShouldClose(window))
        {
            //Input
            processInput(window);

            //Render
            glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT);


            glm::mat4 model = glm::mat4(1.0f);
            // model = glm::rotate(model, glm::radians(90.0f), glm::vec3(0.0f, 0.0f, 1.0f));

            glm::mat4 view = glm::mat4(1.0f);
            // view = glm::lookAt(glm::vec3(0.0f, 0.0f, 3.0f), 
  		    //     glm::vec3(0.0f, 0.0f, 0.0f), 
  		    //     glm::vec3(0.0f, 1.0f, 0.0f));

            glm::mat4 projection = glm::perspective(
                glm::radians(45.0f),
                 (float)SCR_WIDTH / (float)SCR_HEIGHT,
                 0.01f,
                 1000.0f
                 )


            glm::mat4 mvp = projection * view * model;
            basicShader.setMat4("mvp", mvp);

            cube.draw(basicShader);

            //Swap poll
            glfwSwapBuffers(window);
            glfwPollEvents();
        }
    }
    glfwTerminate();
    return 0;
}


void processInput(GLFWwindow *window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}