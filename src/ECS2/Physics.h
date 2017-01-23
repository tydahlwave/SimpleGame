//
//  Physics.h
//  SimpleGame
//
//  Created by Tyler Dahl on 1/22/17.
//
//

#ifndef Physics_h
#define Physics_h

#include "World.h"

class Physics {
public:
    Physics() {};
    virtual ~Physics() {};
    
    glm::vec3 gravity = glm::vec3(0, -0.01, 0);
    
    void Update(World &world);
};

#endif /* Physics_h */
