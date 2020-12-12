//
// Created by holmes on 12/12/2020.
//

#include "game.h"

mesh_t cube = { 0 };

void game_init(void) {
    /* Init models */
    cube.shader = load_shader("../res/shaders/vertex.txt", "../res/shaders/fragment.txt");
    cube.texture = load_texture("../res/textures/default.png", true);
    cube.position = (vector_3){ 0.0f, 0.0f, 0.0f };
    load_model(&cube, "../res/models/cube.obj");
}

void game_process_input(float delta_time) {

}

void game_update(float delta_time) {

}

void game_render(void) {
    draw_object(&cube);
}
