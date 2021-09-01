//
// Created by jocacoca on 1.9.21..
//

#ifndef PROJECT_BASE_CONSTS_H
#define PROJECT_BASE_CONSTS_H
int width = 800;
int height = 600;
const char *title = "Naruto";

//vertices indices and other things

float groundVertices[] = {
            //Position                  //Color                  //Tex Cords
        -0.5f, 0.5f, -0.5f,       0.7f, 1.0f, 1.0f, 1.0f,        1.0f, 1.0f,    //Top Left
        -0.5f, -0.5f, -0.5f,      1.0f, 0.7f, 1.0f, 1.0f,        1.0f, 0.0f,    //Bottom left
        0.5f, 0.5f, -0.5f,       1.0f, 1.0f, 0.7f, 1.0f,        0.0f, 0.0f,    //Top Right
        0.5f, -0.5f, -0.5f,        1.0f, 1.0f, 1.0f, 1.0f,        0.0f, 1.0f     //Bottom Right
};

unsigned int groundIndices[] = {
        1, 2, 3,
        0, 1, 3
};



#endif //PROJECT_BASE_CONSTS_H
