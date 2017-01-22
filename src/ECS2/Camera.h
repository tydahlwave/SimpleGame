//
//  Camera.h
//  SimpleGame
//
//  Created by Tyler Dahl on 1/22/17.
//
//

#ifndef Camera_h
#define Camera_h

#include "Component.h"

enum ProjectionType {
    Orthographic,
    Perspective
};

class Camera : public Component {
public:
    Camera() { name = "Camera"; };
    virtual ~Camera() {};
    
    ProjectionType projectionType;
    float near = 1;
    float far = 100;
};

#endif /* Camera_h */
