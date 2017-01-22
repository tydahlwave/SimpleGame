//
//  World.h
//  SimpleGame
//
//  Created by Tyler Dahl on 1/22/17.
//
//

#ifndef World_h
#define World_h

#include <vector>

#include "GameObject.h"

class GameObject;

class World {
public:
    World();
    virtual ~World() {};
    
    std::vector<std::shared_ptr<GameObject>> GetGameObjects();
private:
    std::vector<std::shared_ptr<GameObject>> gameObjects;
};

#endif /* World_h */
