#include <stdio.h>
#include "engine/engine.h"

int main(void) {

    GLuint shader_program;
    GLuint texture;

    if(!engine_init("OpenGL", 800, 600))
        return -1;

    if(!compile_shader(&shader_program, "res/shaders/vertex_shader.txt", "res/shaders/fragment_shader.txt"))
        return -1;

    if(!load_texture(&texture, "res/texture/wood.png"))
        return -1;

    while(!window_close()) {
        update_screen();
    }

    engine_close();

    return 0;
}
