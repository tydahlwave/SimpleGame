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
        
        float floatX[maxEntities];
        float floatZ[maxEntities];
        vec3 randPosition;
        GameObject obj;
        bool positionClear = false;
        int randX;
        int randZ;
        
        
        //collect positions
        int i = 0;
        for(auto &obj : world->GetGameObjects()){
            randPosition = obj->transform->position;
            floatX[i] = randPosition.x;
            floatZ[i] = randPosition.z;
            i++;
        }
        
        
        //check if positions found
        while (!positionClear)
        {
            randX = rand() % 100 - 50;
            randZ = rand() % 100 - 50;
            
            bool xFound = false;
            bool zFound = false;
            
            //check through arrays
            for (int j = 0; j < maxEntities; j++) {
                if (floatX[j] == randX) {
                    xFound = true;
                }
                if (floatZ[j] == randZ) {
                    zFound = true;
                }
            }
            
            if (!(xFound && zFound)) {
                positionClear = true;
                randPosition = vec3(randX, 0, randZ);
            }
        }

        bunny->transform->position = randPosition;
        rigidBody->velocity -= vel;
        rigidBody->useGravity = true;
        bunny->transform->rotation += vec3(0, (float)-(randomAngle), 0);
        bunnies.push_back(bunny);
    }
}
