#include <stdio.h>
#include "engine.h"
#include "game.h"

int main(void) {

    if(engine_init("OpenGL", 800, 600) != 0)
        return -1;

    game_init();

    /* Timer */
    int32_t tick_interval = 1000 / 10;
    uint32_t last_update_time = 0;
    int32_t delta_time = 0;

    while(!window_close()) {
        /* Delta time */
        uint32_t current_time = SDL_GetTicks();
        delta_time = current_time - last_update_time;

        int32_t time_to_sleep = tick_interval - delta_time;
        if(time_to_sleep > 0)
            SDL_Delay(time_to_sleep);

        /* Input handle */
        game_process_input(delta_time);

        /* Update game state */
        game_update(delta_time);

        last_update_time = current_time;

        /* Render */
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glClearColor(0xFF, 0xFF, 0xFF, 0xFF);

        game_render();

        update_screen();
    }

    destroy_engine();

    return 0;
}
