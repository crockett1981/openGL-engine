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

void get_view_matrix(mat4 destination);
float fov_back(void);
void init_camera(vec3 position, vec3 up, float yaw, float pitch);
void process_keyboard(enum camera_movement direction, float delta_time);
void process_mouse_movement(float x_offset, float y_offset, bool constrain_pitch);
void process_mouse_scroll(float y_offset);

#endif //ENGINE_CAMERA_H
