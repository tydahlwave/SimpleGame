//
//  UserInputSystem.h
//  SimpleGame
//
//  Created by Tyler Dahl on 1/19/17.
//
//

#ifndef UserInputSystem_h
#define UserInputSystem_h

#include "World.h"

class UserInputSystem {
public:
    UserInputSystem() {}
    virtual ~UserInputSystem() {}
    
    void update(World &world);
};

#endif /* UserInputSystem_h */
