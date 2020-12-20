//
// Created by holmes on 20/10/2020.
//

#include "event.h"

SDL_Event event = { 0 };

bool window_close(void) {

    while(SDL_PollEvent(&event) != 0) {
        switch(event.type) {
            case SDL_QUIT:
                return true;
            case SDL_MOUSEMOTION:
                mouse_handling(&event.motion);
                break;
        }
    }

    return false;
}