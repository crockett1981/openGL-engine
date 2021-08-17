#include "window.h"

SDL_Window* window = NULL;
SDL_GLContext glContext = NULL;

int engine_init(const char* window_name, unsigned short screen_width, unsigned short screen_height) {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        SDL_Log("Failed to initialize SDL: %s\n", SDL_GetError());
        return -1;
    }

    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_ACCELERATED_VISUAL, 1);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);

    window = SDL_CreateWindow(window_name, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, screen_width, screen_height, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);
    if (window == NULL) {
        SDL_Log("Failed to create window: %s\n", SDL_GetError());
        return -1;
    }

    glContext = SDL_GL_CreateContext(window);
    if (glContext == NULL) {
        SDL_Log("Failed to create OpenGL context: %s\n", SDL_GetError());
        return -1;
    }

    glewExperimental = GL_TRUE;
    GLenum error = glewInit();
    if (GLEW_OK != error) {
        SDL_Log("Failed to initialize GLEW: %s\n", glewGetErrorString(error));
        return -1;
    }

    SDL_Log("Using GLEW %s\n", glewGetString(GLEW_VERSION));

    printf("\nOpenGL version: %s\n", glGetString(GL_VERSION));
    printf("GLSL version: %s\n", glGetString(GL_SHADING_LANGUAGE_VERSION));
    printf("Vendor: %s\n", glGetString(GL_VENDOR));
    printf("Rendering device: %s\n\n", glGetString(GL_RENDERER));

    SDL_SetRelativeMouseMode(SDL_TRUE);
    SDL_ShowCursor(0);

    glViewport(0, 0, screen_width, screen_height);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    return 0;
}

void update_screen(void) {
    SDL_GL_SwapWindow(window);
}

void destroy_engine(void) {
    SDL_GL_DeleteContext(glContext);
    SDL_DestroyWindow(window);
    SDL_Quit();
}