//
//  Camera.h
//  SimpleGame
//
//  Created by Tyler Dahl on 1/19/17.
//
//

#ifndef Camera_h
#define Camera_h

#include <memory>

#include "glm/glm.hpp"

#define CAMERA_STOPPED_THRESHOLD 0.1

class Camera {
public:
    Camera(glm::vec3 p, glm::vec3 l, glm::vec3 u, glm::vec3 v) :pos(p), lookAt(l), up(u), vel(v) {};
    virtual ~Camera() {}
    
    glm::vec3 pos;
    glm::vec3 lookAt;
    glm::vec3 up;
    glm::vec3 vel; // u, v, w
    
    const glm::mat4 &getMatrix();
    void update();
};

#endif /* Camera_h */
