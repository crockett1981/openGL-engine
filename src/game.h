//
// Created by holmes on 12/12/2020.
//

#ifndef ENGINE_GAME_H
#define ENGINE_GAME_H

#include <GL/glew.h>
#include <cglm/cglm.h>
#include "engine.h"



void game_init(void);
void game_process_input(float delta_time);
void game_update(float delta_time);
void game_render(void);


#endif //ENGINE_GAME_H
