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
    Camera(ProjectionType p, float n, float f) :Camera() { projectionType = p; near = n; far = f; }
    virtual ~Camera() {};
    
    ProjectionType projectionType = Perspective;
    float near = 1;
    float far = 100;
};

#endif /* Camera_h */
