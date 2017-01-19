//
//  EntityFactory.cpp
//  SimpleGame
//
//  Created by Tyler Dahl on 1/18/17.
//
//

#include <stdio.h>

#include "EntityFactory.h"
#include "World.h"

int EntityFactory::createPlayer() {
    int player = World::createEntity();
    World::entity[player] = (COMP_POSITION | COMP_VELOCITY | COMP_TRANSFORM | COMP_ENTITY_TYPE | COMP_SHADER_TYPE);
    
    World::position[player].value = vec3(0, 0, 0);
    World::velocity[player].value = vec3(0, 0, 0);
    World::transform[player].transforms.reset();
    World::entityType[player].type = "bunny";
    World::shaderType[player].type = "phong";
    
    return player;
}

int EntityFactory::createSheep() {
    int sheep = World::createEntity();
    World::entity[sheep] = (COMP_POSITION | COMP_VELOCITY | COMP_TRANSFORM | COMP_ENTITY_TYPE | COMP_SHADER_TYPE);
    
    World::position[sheep].value = vec3(0, 0, 0);
    World::velocity[sheep].value = vec3(0, 0, 0);
    World::transform[sheep].transforms.reset();
    World::entityType[sheep].type = "bunny";
    World::shaderType[sheep].type = "phong";
    
    return sheep;
}
