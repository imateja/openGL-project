#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec4 aCol;
layout (location = 2) in vec2 aTexCoord;

out vec4 out_color;
out vec2 tex_coord;

void main(){
    gl_Position = vec4(aPos.x,aPos.y,0.0,1.0);
    out_color = aCol;
    tex_coord = vec2(aTexCoord.x,aTexCoord.y);
}