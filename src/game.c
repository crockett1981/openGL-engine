//
// Created by holmes on 12/12/2020.
//

#include "game.h"

mesh_t cube = { 0 };

void game_init(void) {
    /* Init models */
    cube.shader = load_shader("../res/shaders/vertex_shader.txt", "../res/shaders/fragment_shader.txt");
    cube.texture = load_texture("../res/textures/default.png", true);
    memcpy(cube.position, (vec3){0.0f, 0.0f, 0.0f}, sizeof(vec3));
    load_obj_file(&cube, "../res/models/cube.obj");
    prepare_model(&cube);

    /* Init camera */
    init_camera((vec3){ 0.0f, 0.0f, 3.0f}, (vec3){ 0.0f, 1.0f, 0.0f}, -90.0f, 0.0f);
}

void game_process_input(float delta_time) {
    const Uint8* keystate = SDL_GetKeyboardState(NULL);
    
    if (keystate[SDL_SCANCODE_W]) {
        process_keyboard(FORWARD, delta_time);
    }

    if (keystate[SDL_SCANCODE_S]) {
        process_keyboard(BACKWARD, delta_time);
    }

    if (keystate[SDL_SCANCODE_A]) {
        process_keyboard(LEFT, delta_time);;
    }

    if (keystate[SDL_SCANCODE_D]) {
        process_keyboard(RIGHT, delta_time);
    }
}

void game_update(float delta_time) {

}

void game_render(void) {
    render_model(&cube);
}

void destroy_game(void) {
    destroy_model(&cube);
}
