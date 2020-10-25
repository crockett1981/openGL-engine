//
// Created by holmes on 24/10/2020.
//

#ifndef ENGINE_CAMERA_H
#define ENGINE_CAMERA_H

#include <cglm/cglm.h>

enum camera_movement {
    FORWARD, BACKWARD, LEFT, RIGHT
};

struct camera_settings {
    float sensitivity;
    float movement_speed;
    float zoom;
    vec3 position;
    vec3 up_world;
    float yaw;
    float pitch;
    vec3 front;
    vec3 right;
    vec3 up;
};

void init_camera(vec3 position, vec3 up, float yaw, float pitch);

#endif //ENGINE_CAMERA_H
