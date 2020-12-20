//
// Created by holmes on 18/10/2020.
//

#include "shader.h"

static void error_handler(GLuint object, enum shader_type shaderType) {
    int success;
    char info_log[512];

    switch (shaderType) {
        case VERTEX:
            glGetShaderiv(object, GL_COMPILE_STATUS, &success);
            if(!success) {
                glGetShaderInfoLog(object, 512, NULL, info_log);
                SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Error in compiling vertex shader: %s\n", info_log);
            } else {
                SDL_Log("Vertex shader loaded\n");
            }
            break;
        case FRAGMENT:
            glGetShaderiv(object, GL_COMPILE_STATUS, &success);
            if(!success) {
                glGetShaderInfoLog(object, 512, NULL, info_log);
                SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Error in compiling fragment shader: %s\n", info_log);
            } else {
                SDL_Log("Fragment shader loaded\n");
            }
            break;
        case PROGRAM:
            glGetProgramiv(object, GL_LINK_STATUS, &success);
            if(!success) {
                glGetProgramInfoLog(object, 512, NULL, info_log);
                SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Shader linking error: %s\n", info_log);
            } else {
                SDL_Log("Program loaded\n");
            }
            break;

        default:
            printf("Unknown type\n");
    }
}

GLuint load_shader(const GLchar *vertex_path, const GLchar *fragment_path) {

    GLuint shader_program;

    GLuint vertex_shader;
    GLuint fragment_shader;

    GLchar* vertex_shader_source = (GLchar*)load_file(vertex_path);
    if (vertex_shader_source == NULL)
        exit(0);

    GLchar* fragment_shader_source = (GLchar*)load_file(fragment_path);
    if (fragment_shader_source == NULL)
        exit(0);

    vertex_shader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertex_shader, 1, (const GLchar *const *) &vertex_shader_source, NULL);
    glCompileShader(vertex_shader);
    error_handler(vertex_shader, VERTEX);

    fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragment_shader, 1, (const GLchar *const *) &fragment_shader_source, NULL);
    glCompileShader(fragment_shader);
    error_handler(fragment_shader, FRAGMENT);

    shader_program = glCreateProgram();

    glAttachShader(shader_program, vertex_shader);
    glAttachShader(shader_program, fragment_shader);
    glLinkProgram(shader_program);
    error_handler(shader_program, PROGRAM);

    glDeleteShader(vertex_shader);
    glDeleteShader(fragment_shader);

    return shader_program;
}
