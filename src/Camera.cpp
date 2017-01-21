//
//  Camera.cpp
//  SimpleGame
//
//  Created by Tyler Dahl on 1/20/17.
//
//

#include <stdio.h>

#include "Camera.h"
#include "MatrixStack.h"

const glm::mat4 &Camera::getMatrix() {
    auto V = std::make_shared<MatrixStack>();
    V->lookAt(pos, lookAt, up);
    return V->topMatrix();
}

void Camera::update() {
    glm::vec3 gaze = lookAt - pos;
    glm::vec3 w = normalize(-gaze);
    glm::vec3 u = normalize(cross(up, w));
    if (abs(vel[2]) > CAMERA_STOPPED_THRESHOLD) {
        pos += vel[2] * w;
        lookAt += vel[2] * w;
    }
    if (abs(vel[0]) > CAMERA_STOPPED_THRESHOLD) {
        pos += vel[0] * u;
        lookAt += vel[0] * u;
    }
}
