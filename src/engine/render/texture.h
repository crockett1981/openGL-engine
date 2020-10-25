//
// Created by holmes on 19/10/2020.
//

#ifndef ENGINE_TEXTURE_H
#define ENGINE_TEXTURE_H

#include <stdbool.h>
#include <GL/glew.h>
#include <SDL.h>
#include <png.h>

bool load_texture(GLuint* texture, const char* file_name);

#endif //ENGINE_TEXTURE_H
