//
//  BunnySpawnSystem.h
//  SimpleGame
//
//  Created by Tyler Dahl on 1/20/17.
//
//

#ifndef BunnySpawnSystem_h
#define BunnySpawnSystem_h

#include "World.h"
#include "EntityFactory.h"
#include <algorithm>

class BunnySpawnSystem {
public:
    void update(World &world);
	int spawnBunny(World &world);
private:
    int numBunnies(World &world);
};

#endif /* BunnySpawnSystem_h */
