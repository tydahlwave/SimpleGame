//
//  World.cpp
//  SimpleGame
//
//  Created by Tyler Dahl on 1/18/17.
//
//

#include <stdio.h>

#include "World.h"

World::World()
:camera(vec3(0, 0, 0), vec3(0, 0, -1), vec3(0, 1, 0), vec3(0, 0, 0)) {

}

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
