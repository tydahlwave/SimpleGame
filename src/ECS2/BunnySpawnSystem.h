//
//  BunnySpawnSystem.h
//  SimpleGame
//
//  Created by Tyler Dahl on 1/24/17.
//
//

#ifndef BunnySpawnSystem_h
#define BunnySpawnSystem_h

#include "World.h"

class BunnySpawnSystem {
public:
    BunnySpawnSystem() {};
    virtual ~BunnySpawnSystem() {};
    
    void Update(long frameTime, World *world);
private:
    int maxEntities = 20;
    long elapsedTime = 0;
    long spawnRate = 2000; // 2 second per spawn
    std::vector<GameObject*> bunnies;
};

#endif /* BunnySpawnSystem_h */
