//
// Created by holmes on 14/12/2020.
//

#ifndef ENGINE_DRAW_MODEL_H
#define ENGINE_DRAW_MODEL_H

#include "engine.h"
#include <GL/glew.h>
#include "camera.h"

void prepare_model(mesh_t* mesh);
void render_model(mesh_t* mesh);
void destroy_model(mesh_t* mesh);

#endif //ENGINE_DRAW_MODEL_H
