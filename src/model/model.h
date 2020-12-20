//
// Created by holmes on 12/12/2020.
//

#ifndef ENGINE_MODEL_H
#define ENGINE_MODEL_H

#include <stdio.h>
#include <stdlib.h>
#include <SDL.h>
#include <cglm/cglm.h>
#include <GL/glew.h>
#include "../util.h"

typedef struct mesh_t {
    GLuint shader;
    GLuint texture;

    vec3* vertices;
    vec2* texture_coordinates;
    vec3* normals;
    int count;

    GLuint vao;
    GLuint vertices_vbo, texture_vbo, normals_vbo;

    vec3 position;

    float cube_vertices[180];

} mesh_t;

int load_obj_file(mesh_t *mesh, const char *file_name);
int load_cube(mesh_t* mesh, const char* file_name);

#endif //ENGINE_MODEL_H
