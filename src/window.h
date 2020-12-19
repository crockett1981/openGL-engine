#include <stdio.h>
#include <SDL.h>
#include <GL/glew.h>

int engine_init(const char* window_name, unsigned short screen_width, unsigned short screen_height);
void update_screen(void);
void destroy_engine(void);