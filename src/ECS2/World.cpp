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

std::vector<std::shared_ptr<GameObject>> World::GetGameObjects() {
    return gameObjects;
}
