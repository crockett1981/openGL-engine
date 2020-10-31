#include <stdio.h>
#include "engine/engine.h"

int main(void) {

    if(!engine_init("OpenGL", 800, 600))
        return -1;

    cube_struct* test_cube = malloc(sizeof(*test_cube));
    if (test_cube) {
        test_cube->texture_path = "../res/texture/wood.png";
        test_cube->shader.vertex_path = "../res/shaders/vertex_shader.txt";
        test_cube->shader.fragment_path = "../res/shaders/fragment_shader.txt";
    }

    init_cube(test_cube);

    init_camera((vec3){ 0.0f, 0.0f, 3.0f}, (vec3){ 0.0f, 1.0f, 0.0f}, -90.0f, 0.0f);

    while(!window_close()) {

        keyboard_handling();

        update_screen();
    }
    
    free(test_cube);
    test_cube = NULL;

    destroy_engine();

    return 0;
}
