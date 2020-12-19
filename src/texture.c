//
// Created by holmes on 19/10/2020.
//

#include "texture.h"
#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

GLuint load_texture(const char* file_name, bool alpha) {

    GLuint texture;

    int width, height, nr_channels;
    unsigned int internal_format, image_format;

    if(alpha) {
        internal_format = GL_RGBA;
        image_format = GL_RGBA;
    }

    stbi_set_flip_vertically_on_load(true);

    unsigned char* data = stbi_load(file_name, &width, &height, &nr_channels, 0);

    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);
    glTexImage2D(GL_TEXTURE_2D, 0, internal_format, width, height, 0, image_format, GL_UNSIGNED_BYTE, data);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    glBindTexture(GL_TEXTURE_2D, 0);

    stbi_image_free(data);

    return texture;
}
