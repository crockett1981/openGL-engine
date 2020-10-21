//
// Created by holmes on 20/10/2020.
//

#include "update.h"



void update_screen(void) {

    main_systems mainSystems;

    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    SDL_GL_SwapWindow(mainSystems.window);
}
