//
// Created by holmes on 18/10/2020.
//

#ifndef ENGINE_SHADER_H
#define ENGINE_SHADER_H

#include <stdbool.h>
#include <stdio.h>
#include <SDL.h>
#include <GL/glew.h>

enum shader_type {
    VERTEX, FRAGMENT, PROGRAM
};

struct shader {
    GLuint* shader_program;
    GLchar* vertex_path;
    GLchar* fragment_path;
};

bool compile_shader(GLuint* shader_program, const GLchar* vertex_path, const GLchar* fragment_path);

#endif //ENGINE_SHADER_H
