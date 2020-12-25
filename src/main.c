#include <stdio.h>
#include "engine.h"
#include "game.h"

int main(void) {

    if(engine_init("OpenGL", 800, 600) != 0)
        return -1;

    game_init();

    /* Timer */
    double delta_time = 0;
    Uint64 NOW = SDL_GetPerformanceCounter();
    Uint64 LAST = 0;

    while(!window_close()) {
        /* Delta time */
        LAST = NOW;
        NOW = SDL_GetPerformanceCounter();
        delta_time = ((double)(NOW - LAST) * 1000 / (double)SDL_GetPerformanceFrequency());

        /* Input handle */
        game_process_input((float)delta_time);

        /* Update game state */
        game_update((float)delta_time);

        /* Render */
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glClearColor(0xFF, 0xFF, 0xFF, 0xFF);

        game_render();

        update_screen();
    }
    destroy_game();
    destroy_engine();

    return 0;
}