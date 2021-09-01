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
#include "../include/rg/consts.h"
//setting width height and title



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


    //Rendering loop
    while(!glfwWindowShouldClose(window)){
        glfwPollEvents();
        update_window(window);
        //glUseProgram(shaderProgram);
        glfwSwapBuffers(window);
    }





    exit(EXIT_SUCCESS);
}