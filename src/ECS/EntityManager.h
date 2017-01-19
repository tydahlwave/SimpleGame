//
//  EntityManager.h
//  SimpleGame
//
//  Created by Tyler Dahl on 1/18/17.
//
//

#ifndef EntityManager_h
#define EntityManager_h

#include <vector>

#include "Entity.h"
#include "HealthComponent.h"

static const int MAX_ENTITIES = 100;

enum Component { // Max of 32 components
    COMP_POSITION   = 0,
    COMP_VELOCITY   = 1 << 0,
    COMP_HEALTH     = 1 << 1,
    COMP_RENDER     = 1 << 2
};

class EntityManager {
public:
    EntityManager() {}
    virtual ~EntityManager() {}
    
//    void setComponentForEntity(int eId, int compId);
//    void removeComponentForEntity(int eId, int compId);
//    bool hasComponentForEntity(int eId, int compId);

    int entityMask[MAX_ENTITIES];
    HealthComponent healthComps[MAX_ENTITIES];
};

#endif /* EntityManager_h */
