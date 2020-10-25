//
// Created by holmes on 24/10/2020.
//

#include <SDL_log.h>
#include "camera.h"

#define DEFAULT_SPEED 0.01f
#define DEFAULT_SENSITIVITY 0.1f
#define DEFAULT_ZOOM 45.0f

struct camera_settings cameraSettings = { 0 };

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
