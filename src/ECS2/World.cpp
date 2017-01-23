//
//  World.cpp
//  SimpleGame
//
//  Created by Tyler Dahl on 1/22/17.
//
//

#include "World.h"
#include "EntityFactory.h"

World::World() {
    EntityFactory::createMainCamera(this);
}

std::vector<GameObject*> World::GetGameObjects() {
    return gameObjects;
}
