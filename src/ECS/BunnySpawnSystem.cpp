//
//  BunnySpawnSystem.cpp
//  SimpleGame
//
//  Created by Tyler Dahl on 1/20/17.
//
//

#include <stdio.h>

#include "BunnySpawnSystem.h"


void BunnySpawnSystem::update(World &world) {
    for (int i = 0; i < MAX_ENTITIES; i++) {
        int entity = world.entity[i];
        
    }
}

int BunnySpawnSystem::numBunnies(World &world) {
	return 0;
}

int BunnySpawnSystem::spawnBunny(World &world) {
	//Vars
	int randX;
	int randZ;
	int randVelocityMag = rand() % 10 + 1;
	vec3 randVelocityDir = vec3(((double)rand() / (RAND_MAX)) + 1, ((double)rand() / (RAND_MAX)) + 1, ((double)rand() / (RAND_MAX)) + 1);
	vec3 randPosition;
	bool positionClear = false;
	int bunny = EntityFactory::createSheep(world);
	float floatX[MAX_ENTITIES];
	float floatZ[MAX_ENTITIES];

	//collect positions
	for (int i = 0; i < MAX_ENTITIES; i++) {
		randPosition = world.position[i].value;
		floatX[i] = randPosition.x;
		floatZ[i] = randPosition.z;
	}

	//check if positions found
	while (!positionClear)
	{
		randX = rand() % 100 - 50;
		randZ = rand() % 100 - 50;
		
		bool xFound = false;
		bool zFound = false;
		
		//check through arrays
		for (int j = 0; j < MAX_ENTITIES; j++) {
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


	//Reconcile collisions
	//TBD

	if (bunny != -1)
	{
        world.position[bunny].value = vec3(randX, 0, randZ);
        vec3 vel = normalize(vec3(((rand() % 10) - 5) / 10.0, 0, ((rand() % 10) - 5) / 10.0));
        world.velocity[bunny].value += vel;
        world.velocity[bunny].value.x /= 10;
        world.velocity[bunny].value.z /= 10;
	}

	return bunny;
}
