//
// Created by holmes on 12/12/2020.
//

#ifndef ENGINE_GAME_H
#define ENGINE_GAME_H

#include <GL/glew.h>
#include <cglm/cglm.h>
#include "engine/engine.h"

typedef struct vector_3 {
    float x;
    float y;
    float z;
} vector_3;

typedef struct mesh_t {
    GLuint shader;
    GLuint texture;

    vector_3 position;
} mesh_t;

void game_init(void);
void game_process_input(float delta_time);
void game_update(float delta_time);
void game_render(void);


#endif //ENGINE_GAME_H
