//
// Created by holmes on 14/12/2020.
//

#include "draw_model.h"

void prepare_model(mesh_t *mesh) {

    glGenVertexArrays(1, &mesh->vao);
    glGenBuffers(1, &mesh->vertices_vbo);
    glGenBuffers(1, &mesh->texture_vbo);
    glGenBuffers(1, &mesh->normals_vbo);

    glBindVertexArray(mesh->vao);
    glBindBuffer(GL_ARRAY_BUFFER, mesh->vertices_vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vec3) * mesh->count, mesh->vertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ARRAY_BUFFER, mesh->texture_vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vec2) * mesh->count, mesh->texture_coordinates, GL_STATIC_DRAW);

    glBindBuffer(GL_ARRAY_BUFFER, mesh->normals_vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vec3) * mesh->count, mesh->normals, GL_STATIC_DRAW);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);

    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, NULL);

    glEnableVertexAttribArray(2);
    glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 0, NULL);

    glBindVertexArray(0);

    free(mesh->vertices);
    mesh->vertices = NULL;
    free(mesh->texture_coordinates);
    mesh->texture_coordinates = NULL;
    free(mesh->normals);
    mesh->normals = NULL;
}

void render_model(mesh_t *mesh) {

    /* Model */
    mat4 model = GLM_MAT4_IDENTITY_INIT;

    glm_translate(model, mesh->position);
    glm_rotate(model, glm_rad(45.0f), (vec3){0.0f, 0.0f, 1.0f});
    glm_scale(model, (vec3){10.0f, 10.0f, 10.0f});

    glUniformMatrix4fv(glGetUniformLocation(mesh->shader, "model"), 1, GL_FALSE, &model[0][0]);

    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, mesh->texture);

    glBindVertexArray(mesh->vao);
    glDrawArrays(GL_TRIANGLES, 0, mesh->count);
    glBindVertexArray(0);
}

void destroy_model(mesh_t *mesh) {

}
