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

#include "MatrixStack.h"
#include "glm/glm.hpp"

using namespace glm;

class Camera {
public:
    Camera(vec3 p, vec3 l, vec3 u) :pos(p), lookAt(l), up(u) {};
    virtual ~Camera() {}
    
    vec3 pos;
    vec3 lookAt;
    vec3 up;
    
    shared_ptr<MatrixStack> getMatrix();
};

#endif /* Camera_h */
