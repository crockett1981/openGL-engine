//
// Created by holmes on 19/10/2020.
//

#ifndef ENGINE_TEXTURE_H
#define ENGINE_TEXTURE_H

#include <stdbool.h>
#include <GL/glew.h>
#include <SDL.h>
#include "util.h"

GLuint load_texture(const char* file_name, bool alpha);

#endif //ENGINE_TEXTURE_H
