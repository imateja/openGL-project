#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
#include <iostream>
#include "../include/rg/Shader.h"
#include "../include/rg/Error.h"
#include "../include/rg/callbacks.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <string>
#include <glad/glad.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <rg/Error.h>
#include <common.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "../include/rg/consts.h"
#include "../include/rg/Texture2D.h"

int main(){
    //Init
    glfwInit();
    //OpenGl 3.3 core
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR,3);
    glfwWindowHint(GLFW_OPENGL_PROFILE,GLFW_OPENGL_CORE_PROFILE);
    //Creating window
    GLFWwindow* window = glfwCreateWindow(width,height,title, nullptr, nullptr);
    if(window== nullptr){
        glfwTerminate();
        exit(EXIT_FAILURE);
    }
    glfwMakeContextCurrent(window);
    //Setting callbacks
    glfwSetFramebufferSizeCallback(window,resizeWindowCallback);
    glfwSetKeyCallback(window,keyCallback);
    if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)){
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    Shader groundShader = Shader("resources/shaders/groundVertexShader.vs",
                                 "resources/shaders/groundFragmentShader.fs");
    unsigned int GroundVAO,GroundVBO,GroundEBO;
    glGenVertexArrays(1,&GroundVAO);
    glGenBuffers(1,&GroundVBO);
    glGenBuffers(1,&GroundEBO);

    glBindVertexArray(GroundVAO);
    glBindBuffer(GL_ARRAY_BUFFER,GroundVBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,GroundEBO);

    glBufferData(GL_ARRAY_BUFFER,sizeof(groundVertices),groundVertices,GL_STATIC_DRAW);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER,sizeof(groundIndices),groundIndices,GL_STATIC_DRAW);

    glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,9*sizeof(float),(void*)0);
    glVertexAttribPointer(1,3,GL_FLOAT,GL_FALSE,9*sizeof(float),(void*)(3*sizeof(float)));
    glVertexAttribPointer(2,3,GL_FLOAT,GL_FALSE,9*sizeof(float),(void*)(7*sizeof(float)));

    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);
    glEnableVertexAttribArray(2);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

    unsigned int GroundTex = loadTexture("resources/textures/grass_tex.jpg");

    //Rendering loop
    while(!glfwWindowShouldClose(window)){
        glfwPollEvents();
        update_window(window);
        groundShader.use();

        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D,GroundTex);

        glBindVertexArray(GroundVAO);
        glDrawElements(GL_TRIANGLES,6,GL_UNSIGNED_INT,0);

        //glUseProgram(shaderProgram);
        glfwSwapBuffers(window);
    }





    exit(EXIT_SUCCESS);
}