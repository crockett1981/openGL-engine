#include <stdio.h>
#include "engine/engine.h"

int main(void) {

    if(!engine_init("OpenGL", 800, 600))
        return -1;

    init_camera((vec3){ 0.0f, 0.0f, 3.0f}, (vec3){ 0.0f, 1.0f, 0.0f}, -90.0f, 0.0f);

    while(!window_close()) {

        keyboard_handling();

        update_screen();
    }

    destroy_engine();

    return 0;
}
