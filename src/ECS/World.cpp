//
//  World.cpp
//  SimpleGame
//
//  Created by Tyler Dahl on 1/18/17.
//
//

#include <stdio.h>

#include "World.h"

// Initialize static arrays
int World::entity[MAX_ENTITIES] = {};
PositionComponent World::position[MAX_ENTITIES] = {};
VelocityComponent World::velocity[MAX_ENTITIES] = {};
AccelerationComponent World::acceleration[MAX_ENTITIES] = {};
HealthComponent World::health[MAX_ENTITIES] = {};
EntityTypeComponent World::entityType[MAX_ENTITIES] = {};
ShaderTypeComponent World::shaderType[MAX_ENTITIES] = {};
TransformComponent World::transform[MAX_ENTITIES] = {};

int World::createEntity() {
    for (int i = 0; i < MAX_ENTITIES; i++) {
        if (entity[i] == 0) {
            return i;
        }
    }
    printf("Maximum number of entites reached. Cannot create new entity.");
    return -1;
}

void World::removeEntity(unsigned int id) {
    if (id >= MAX_ENTITIES) {
        printf("Cannot remove entity %d.\nMaximum number of entites is %d.", id, MAX_ENTITIES);
    } else {
        entity[id] = 0;
    }
}

void World::removeAllEntities() {
    for (int i = 0; i < MAX_ENTITIES; i++) {
        entity[i] = 0;
    }
}
