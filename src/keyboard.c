//
// Created by holmes on 20/10/2020.
//

#include "keyboard.h"

void keyboard_handling(void) {
    const Uint8* keystate = SDL_GetKeyboardState(NULL);

    if(keystate[SDL_SCANCODE_W])
        printf("W\n");

    if(keystate[SDL_SCANCODE_S])
        printf("S\n");

    if(keystate[SDL_SCANCODE_A])
        printf("A\n");

    if(keystate[SDL_SCANCODE_D])
        printf("D\n");
}