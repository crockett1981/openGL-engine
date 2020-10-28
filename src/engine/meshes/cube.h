//
// Created by holmes on 25/10/2020.
//

#ifndef ENGINE_CUBE_H
#define ENGINE_CUBE_H

#include <GL/glew.h>
#include <cglm/cglm.h>
#include "../render/shader.h"
#include "../render/texture.h"

typedef struct cube_struct {
	vec3 position;
	vec3 scale;

	const char* texture_path;
	GLuint* texture;

	GLuint vao;
	GLuint vbo;

	shader shader;
} cube_struct;

bool init_cube(cube_struct *cube);

#endif //ENGINE_CUBE_H
