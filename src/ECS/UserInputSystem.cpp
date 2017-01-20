//
//  UserInputSystem.cpp
//  SimpleGame
//
//  Created by Tyler Dahl on 1/19/17.
//
//

#include <stdio.h>

#include "UserInputSystem.h"

static const int USER_INPUT_MASK = COMP_USER_INPUT;

void UserInputSystem::update(World &world) {
    for (int entity = 0; entity < MAX_ENTITIES; entity++) {
        int entityMask = world.entity[entity];
        if ((entityMask & USER_INPUT_MASK) == USER_INPUT_MASK) {
            
        }
    }
}
