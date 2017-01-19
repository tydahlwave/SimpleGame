//
//  UserInputComponent.h
//  SimpleGame
//
//  Created by Tyler Dahl on 1/19/17.
//
//

#ifndef UserInputComponent_h
#define UserInputComponent_h

#include "glm/glm.hpp"

using namespace glm;

class UserInputComponent {
public:
    bool isJumping;
    bool isRunning;
    vec2 moveDir;
    vec2 mousePos;
};

#endif /* UserInputComponent_h */
