//
//  CollisionSystem.h
//  SimpleGame
//
//  Created by Tyler Dahl on 1/21/17.
//
//

#ifndef CollisionSystem_h
#define CollisionSystem_h

#include "World.h"
#include "RenderSystem.h"

class CollisionSystem {
public:
    void update(World &world, RenderSystem &renderSystem);
private:
    void checkCollisions(World &world, RenderSystem &renderSystem, vector<int> entities);
    void checkCollision(World &world, RenderSystem &renderSystem, vector<int> entities, int curIndex);
    void checkCameraCollision(World &world, RenderSystem &renderSystem, vector<int> entities);
};

#endif /* CollisionSystem_h */
