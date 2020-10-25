#include <stdio.h>
#include <stdbool.h>
#include <SDL.h>
#include <GL/glew.h>

struct main_systems {
	SDL_Window* window;
	SDL_GLContext glContext;
};

bool engine_init(const char* window_name, unsigned short screen_width, unsigned short screen_height);
void update_screen(void);
void destroy_engine(void);