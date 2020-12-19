//
// Created by holmes on 24/10/2020.
//

#include <SDL_log.h>
#include "camera.h"

#define DEFAULT_SPEED 0.01f
#define DEFAULT_SENSITIVITY 0.1f
#define DEFAULT_ZOOM 45.0f

struct camera_settings cameraSettings = { 0 };

void get_view_matrix(mat4 destination) {
    vec3 temp;
    glm_vec3_add(cameraSettings.position, cameraSettings.front, temp);
    glm_lookat(cameraSettings.position, temp, cameraSettings.up, destination);
}

float fov_back(void) {
    return cameraSettings.zoom;
}

void update_camera_vectors(void) {
    vec3 front = {cosf(glm_rad(cameraSettings.yaw)) * cosf(glm_rad(cameraSettings.pitch)), sinf(glm_rad(cameraSettings.pitch)), sinf(glm_rad(cameraSettings.yaw)) * cosf(glm_rad(cameraSettings.pitch))};

    glm_vec3_normalize(front);
    glm_vec3_copy(front, cameraSettings.front);

    vec3 right_temp;
    vec3 up_temp;

    glm_vec3_cross(cameraSettings.front, cameraSettings.up_world, right_temp);
    glm_vec3_normalize(right_temp);
    glm_vec3_copy(right_temp, cameraSettings.right);

    glm_vec3_cross(cameraSettings.right, cameraSettings.front, up_temp);
    glm_vec3_normalize(up_temp);
    glm_vec3_copy(up_temp, cameraSettings.up);
}

void process_keyboard(enum camera_movement direction, float delta_time) {
    float velocity = cameraSettings.movement_speed * delta_time;
    vec3 velocity_vec = {velocity, velocity, velocity};
    vec3 t;

    switch (direction) {

        case FORWARD:
            glm_vec3_mulv(cameraSettings.front, velocity_vec, t);
            glm_vec3_add(cameraSettings.position, t, cameraSettings.position);
            break;
        case BACKWARD:
            glm_vec3_mulv(cameraSettings.front, velocity_vec, t);
            glm_vec3_sub(cameraSettings.position, t, cameraSettings.position);
            break;
        case LEFT:
            glm_vec3_mulv(cameraSettings.right, velocity_vec, t);
            glm_vec3_sub(cameraSettings.position, t, cameraSettings.position);
            break;
        case RIGHT:
            glm_vec3_mulv(cameraSettings.right, velocity_vec, t);
            glm_vec3_add(cameraSettings.position, t, cameraSettings.position);
            break;

        default:
            ;
    }
}

void process_mouse_movement(float x_offset, float y_offset, bool constrain_pitch) {
    x_offset *= cameraSettings.sensitivity;
    y_offset *= cameraSettings.sensitivity;

    cameraSettings.yaw += x_offset;
    cameraSettings.pitch += y_offset;

    if(constrain_pitch) {
        if(cameraSettings.pitch > 89.0f)
            cameraSettings.pitch = 89.0f;
        if(cameraSettings.pitch < -89.0f)
            cameraSettings.pitch = -89.0f;
    }

    update_camera_vectors();
}

void process_mouse_scroll(float y_offset) {
    if(cameraSettings.zoom >= 1.0f && cameraSettings.zoom <= 45.0f)
        cameraSettings.zoom -= y_offset;
    if(cameraSettings.zoom <= 1.0f)
        cameraSettings.zoom = 1.0f;
    if(cameraSettings.zoom >= 45.0f)
        cameraSettings.zoom = 45.0f;
}

void init_camera(vec3 position, vec3 up, float yaw, float pitch) {

    SDL_Log("Camera initialization\n");

    cameraSettings.movement_speed = DEFAULT_SPEED;
    cameraSettings.sensitivity = DEFAULT_SENSITIVITY;
    cameraSettings.zoom = DEFAULT_ZOOM;

    glm_vec3_copy(position, cameraSettings.position);
    glm_vec3_copy(up, cameraSettings.up_world);

    cameraSettings.yaw = yaw;
    cameraSettings.pitch = pitch;

    update_camera_vectors();
}
