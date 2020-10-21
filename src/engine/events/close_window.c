//
// Created by holmes on 20/10/2020.
//

#include "close_window.h"

bool window_close(void) {

    SDL_Event event = { 0 };

    while(SDL_PollEvent(&event) != 0) {
        switch(event.type) {
            case SDL_QUIT:
                return true;
        }
    }

    return false;
}