//
//  PhysicsSystem.cpp
//  SimpleGame
//
//  Created by Tyler Dahl on 1/21/17.
//
//

#include <stdio.h>

#include "PhysicsSystem.h"

static const int PHYSICS_MASK = (COMP_POSITION | COMP_VELOCITY | COMP_ACCELERATION);

static const float GRAVITY = -0.01;

void PhysicsSystem::update(World &world) {
    for (int entity = 0; entity < MAX_ENTITIES; entity++) {
        int entityMask = world.entity[entity];
        if ((entityMask & PHYSICS_MASK) == PHYSICS_MASK) {
            vec3 acc = world.acceleration[entity].value;
            vec3 vel = world.velocity[entity].value;
            world.acceleration[entity].value.y += GRAVITY;
            world.velocity[entity].value += acc;
            world.position[entity].value += vel;
        }
    }
}
