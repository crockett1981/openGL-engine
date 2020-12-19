//
// Created by holmes on 12/12/2020.
//

#include "game.h"

mesh_t cube = { 0 };

GLuint shader;

void game_init(void) {

    shader = load_shader("../res/shaders/vertex.txt", "../res/shaders/fragment.txt");

    /* Init models */
    cube.shader = load_shader("../res/shaders/vertex.txt", "../res/shaders/fragment.txt");
    cube.texture = load_texture("../res/textures/default.png", true);
    glm_vec3_copy((vec3){0.0f, 0.0f, 0.0f}, cube.position);
    load_obj_file(&cube, "../res/models/cube.obj");
    prepare_model(&cube);

    /* Init camera */
    init_camera((vec3){ 0.0f, 0.0f, 3.0f}, (vec3){ 0.0f, 1.0f, 0.0f}, -90.0f, 0.0f);
}

void game_process_input(float delta_time) {

}

void game_update(float delta_time) {

}

void game_render(void) {
    render_model(&cube);
}
