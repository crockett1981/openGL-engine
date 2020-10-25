//
// Created by holmes on 19/10/2020.
//

#include "texture.h"

bool load_texture(GLuint *texture, const char *file_name) {

    unsigned char header[8] = { 0 };

    unsigned int width, height;
    size_t row_bytes;

    png_byte* data = NULL;
    png_bytepp row_pointers = NULL;

    png_structp png_struct = { 0 };
    png_infop png_info = { 0 };
    png_infop png_end_info = { 0 };

    FILE *file = fopen(file_name, "rb");
    if(file == NULL) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "File %s not found\n", file_name);
        return false;
    }

    fread(header, 1, 8, file);

    if(png_sig_cmp(header, 0, 8)) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "The file is not recognized as png\n");
        fclose(file);
        return false;
    }

    png_struct = png_create_read_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
    if(png_struct == NULL) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Failed to create read struct\n");
        fclose(file);
        return false;
    }

    png_info = png_create_info_struct(png_struct);
    if(png_info == NULL) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Failed to create info struct\n");
        png_destroy_read_struct(&png_struct, NULL, NULL);
        fclose(file);
        return false;
    }

    png_end_info = png_create_info_struct(png_struct);
    if(png_info == NULL) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Failed to create end info struct\n");
        png_destroy_read_struct(&png_struct, NULL, NULL);
        fclose(file);
        return false;
    }

    if(setjmp(png_jmpbuf(png_struct))) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "An error occurred during initialization of io\n");
        png_destroy_read_struct(&png_struct, &png_info, &png_end_info);
        fclose(file);
        return false;
    }

    png_init_io(png_struct, file);

    png_set_sig_bytes(png_struct, 8);

    png_read_info(png_struct, png_info);

    width = png_get_image_width(png_struct, png_info);
    height = png_get_image_height(png_struct, png_info);

    png_read_update_info(png_struct, png_info);

    row_bytes = png_get_rowbytes(png_struct, png_info);
    data = (png_bytep) malloc(row_bytes * height * sizeof(png_byte));
    if(data == NULL) {
        png_destroy_read_struct(&png_struct, &png_info, &png_end_info);
        fclose(file);
        return false;
    }

    row_pointers = (png_bytep*) malloc(sizeof(png_bytep) * height);
    if(row_pointers == NULL) {
        png_destroy_read_struct(&png_struct, &png_info, &png_end_info);
        free(data);
        data = NULL;
        fclose(file);
        return false;
    }

    for(unsigned int i = 0; i < height; ++i)
        row_pointers[height - 1 - i] = data + i * row_bytes;

    png_read_image(png_struct, row_pointers);

    glGenTextures(1, texture);
    glBindTexture(GL_TEXTURE_2D, *texture);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
    glGenerateMipmap(GL_TEXTURE_2D);

    png_destroy_read_struct(&png_struct, &png_info, &png_end_info);

    free(data);
    data = NULL;

    if(row_pointers != NULL) {
        free(row_pointers);
        row_pointers = NULL;
    }

    fclose(file);

    return true;
}
