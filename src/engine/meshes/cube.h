//
// Created by holmes on 25/10/2020.
//

#ifndef ENGINE_CUBE_H
#define ENGINE_CUBE_H

#include <GL/glew.h>
#include <cglm/cglm.h>
#include "../render/shader.h"
#include "../render/texture.h"

typedef struct cube {
    vec3 position;

    const char* texture_path;
    GLuint* texture;

    struct shader* shader;

    GLuint vao;
    GLuint vbo;
} cube_struct;

bool init_cube(cube_struct *cube);

#endif //ENGINE_CUBE_H
