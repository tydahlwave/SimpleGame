//
//  BunnySpawnSystem.cpp
//  SimpleGame
//
//  Created by Tyler Dahl on 1/24/17.
//
//

#include "BunnySpawnSystem.h"
#include "EntityFactory.h"
#include "RigidBody.h"

void BunnySpawnSystem::Update(long frameTime, World *world) {
    if (bunnies.size() >= maxEntities) return;
    
    elapsedTime += frameTime;
    if (elapsedTime > spawnRate) {
        elapsedTime = 0;
        GameObject *bunny = EntityFactory::createBunny(world);
        int randomAngle = rand() % 360;
        float velX = cos(randomAngle);
        float velY = sin(randomAngle);
        glm::vec3 vel = normalize(glm::vec3(velX, 0, velY)) / glm::vec3(20, 20, 20);
        RigidBody *rigidBody = (RigidBody*)bunny->GetComponent("RigidBody");
        rigidBody->velocity -= vel;
        rigidBody->useGravity = true;
        bunny->transform->rotation += vec3(0, (float)-(randomAngle), 0);
        bunnies.push_back(bunny);
    }
}
