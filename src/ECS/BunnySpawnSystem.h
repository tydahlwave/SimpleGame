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

class BunnySpawnSystem {
public:
    void update(World &world);
private:
    int numBunnies(World &world);
};

#endif /* BunnySpawnSystem_h */
