//
//  EntityFactory.h
//  SimpleGame
//
//  Created by Tyler Dahl on 1/18/17.
//
//

#ifndef EntityFactory_h
#define EntityFactory_h

#include "World.h"

class EntityFactory {
public:
    static int createPlayer(World &world);
    static int createSheep(World &world);
    static int createGround(World &world);
};

#endif /* EntityFactory_h */
