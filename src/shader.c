//
// Created by holmes on 18/10/2020.
//

#include "shader.h"

static bool load_file(const GLchar* file_path, GLchar** shader_type) {

    FILE *file = fopen(file_path, "rb");
    if(file == NULL) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "File %s not found\n", file_path);
        return false;
    }

    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    fseek(file, 0, SEEK_SET);

    *shader_type = malloc(file_size + 1);
    if(*shader_type == NULL) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Allocation error\n");
        return false;
    }

    fread(*shader_type, file_size, 1, file);
    if(feof(file)) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Unexpected end of file\n");
        return false;
    }

    fclose(file);

    (*shader_type)[file_size] = 0;

    return true;
}

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

    GLchar* vertex_shader_source = NULL;
    GLchar* fragment_shader_source = NULL;

    if(!load_file(vertex_path, &vertex_shader_source)) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Failed to load file\n");
        return false;
    }

    if(!load_file(fragment_path, &fragment_shader_source)) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Failed to load file\n");
        return false;
    }

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
