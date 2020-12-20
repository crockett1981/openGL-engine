//
// Created by holmes on 24/10/2020.
//

#include "mouse.h"

void mouse_handling(SDL_MouseMotionEvent* event) {
	process_mouse_movement((float)event->xrel, (float)-event->yrel, true);
}