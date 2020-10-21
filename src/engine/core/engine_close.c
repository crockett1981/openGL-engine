//
// Created by holmes on 17/10/2020.
//

#include "engine_close.h"



void engine_close(void) {

    main_systems mainSystems;

    SDL_GL_DeleteContext(mainSystems.glContext);
    SDL_DestroyWindow(mainSystems.window);
    SDL_Quit();
}
