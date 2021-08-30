#include <iostream>
#include <stdlib.h>
#include <string>
#include "../include/rg/Error.h"
#include "../include/rg/callbacks.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>

int width = 800;
int height = 600;
const char *title = "Naruto";


int main(){
    glfwInit();
    //OpenGl 3.3 core
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR,3);
    glfwWindowHint(GLFW_OPENGL_PROFILE,GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window = glfwCreateWindow(width,height,title, nullptr, nullptr);
    if(window== nullptr){
        glfwTerminate();
        exit(EXIT_FAILURE);
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window,resizeWindowCallback);
    glfwSetKeyCallback(window,keyCallback);
    if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)){
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    while(!glfwWindowShouldClose(window)){
        glfwPollEvents();
        update_window(window);
        glfwSwapBuffers(window);
    }




    exit(EXIT_SUCCESS);
}