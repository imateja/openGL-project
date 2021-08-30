//
// Created by jocacoca on 30.8.21..
//
#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include <iostream>
#ifndef PROJECT_BASE_CALLBACKS_H
#define PROJECT_BASE_CALLBACKS_H

void resizeWindowCallback(GLFWwindow* window,int width,int height){
    glViewport(0,0,width,height);
}
void update_window(GLFWwindow* window){
}
void keyCallback(GLFWwindow* window,int key,int scancode,int action,int mode){
    if(key == GLFW_KEY_R && action == GLFW_PRESS){
        std::cerr<<"R"<<std::endl;
    }
    if(key == GLFW_KEY_G && action == GLFW_PRESS){
        std::cerr<<"G"<<std::endl;
    }
    if(key == GLFW_KEY_B && action == GLFW_PRESS){
        std::cerr<<"B"<<std::endl;
    }
    if(key == GLFW_KEY_ESCAPE && action == GLFW_PRESS){
        glfwSetWindowShouldClose(window, true);
    }
}


#endif //PROJECT_BASE_CALLBACKS_H
