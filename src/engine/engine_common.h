//
// Created by holmes on 17/10/2020.
//

#ifndef ENGINE_ENGINE_COMMON_H
#define ENGINE_ENGINE_COMMON_H

#include <SDL2/SDL.h>
#include <GL/glew.h>

typedef struct {
    SDL_Window *window;
    SDL_GLContext glContext;
} main_systems;

#endif //ENGINE_ENGINE_COMMON_H
