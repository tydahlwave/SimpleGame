//
//  CollisionSystem.cpp
//  SimpleGame
//
//  Created by Tyler Dahl on 1/21/17.
//
//

#include <stdio.h>

#include "CollisionSystem.h"
#include "../BoundingBoxComponent.h"
#include <vector>
#include <string>
#include <iostream>

static const int COLLISION_MASK = (COMP_POSITION | COMP_ENTITY_TYPE);

void CollisionSystem::update(World &world, RenderSystem &renderSystem) {
    vector<int> entities;
    for (int entity = 0; entity < MAX_ENTITIES; entity++) {
        int entityMask = world.entity[entity];
        if ((entityMask & COLLISION_MASK) == COLLISION_MASK) {
            entities.push_back(entity);
        }
    }
    checkCollisions(world, renderSystem, entities);
    checkCameraCollision(world, renderSystem, entities);
}

void CollisionSystem::checkCollisions(World &world, RenderSystem &renderSystem, vector<int> entities) {
    for (int i = 0; i < entities.size(); i++) {
        checkCollision(world, renderSystem, entities, i);
    }
}

void CollisionSystem::checkCollision(World &world, RenderSystem &renderSystem, vector<int> entities, int curIndex) {
    int entity1 = entities[curIndex];
    string entityName1 = world.entityType[entity1].type;
    BoundingBoxComponent *bb1 = renderSystem.shapes[entityName1]->getBoundingBoxWithTransform(world.transform[entity1].getMatrix(world.position[entity1].value));
    for (int i = curIndex+1; i < entities.size(); i++) {
        int entity2 = entities[i];
        string entityName2 = world.entityType[entity2].type;
        BoundingBoxComponent *bb2 = renderSystem.shapes[entityName2]->getBoundingBoxWithTransform(world.transform[entity2].getMatrix(world.position[entity2].value));
        
        // If collision
        if ((bb1->min.x <= bb2->max.x && bb1->max.x >= bb2->min.x) &&
            (bb1->min.y <= bb2->max.y && bb1->max.y >= bb2->min.y) &&
            (bb1->min.z <= bb2->max.z && bb1->max.z >= bb2->min.z)) {
            if (entityName1.compare("rect") == 0) {
                if (entityName2.compare("bunny") == 0) {
                    world.acceleration[entity2].value.y = 0;
                    world.velocity[entity2].value.y = 0;
                    world.position[entity2].value.y = world.position[entity1].value.y + world.transform[entity2].scale.y * 0.98; //bunny height
                }
            } else if (entityName1.compare("bunny") == 0) {
                if (entityName2.compare("rect") == 0) {
                    world.acceleration[entity1].value.y = 0;
                    world.velocity[entity1].value.y = world.position[entity2].value.y + world.transform[entity1].scale.y * 0.98; //bunny height
                } else if (entityName2.compare("bunny") == 0) {
                    std::cout << "Bunny collision" << std::endl;
                }
            }
        }
    }
}

void CollisionSystem::checkCameraCollision(World &world, RenderSystem &renderSystem, vector<int> entities) {
    for (int i = 0; i < entities.size(); i++) {
        int entity = entities[i];
        string entityName = world.entityType[entity].type;
        BoundingBoxComponent *bb = renderSystem.shapes[entityName]->getBoundingBoxWithTransform(world.transform[entity].getMatrix(world.position[entity].value));
        
        // If collision
        if ((world.camera.pos.x >= bb->min.x && world.camera.pos.x <= bb->max.x) &&
            (world.camera.pos.y >= bb->min.y && world.camera.pos.y <= bb->max.y) &&
            (world.camera.pos.z >= bb->min.z && world.camera.pos.z <= bb->max.z)) {
            // If collided with bunny, remove its velocity component
            if (entityName.compare("bunny")) {
                world.entity[entity] &= ~COMP_VELOCITY;
            }
        }
    }
}
