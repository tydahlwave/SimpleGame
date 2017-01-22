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
    Physics();
    virtual ~Physics() {};
    
    void update(World &world);
};

#endif /* Physics_h */
