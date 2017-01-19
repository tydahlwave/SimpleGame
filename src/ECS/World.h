//
//  World.h
//  SimpleGame
//
//  Created by Tyler Dahl on 1/18/17.
//
//

#ifndef World_h
#define World_h

#include "PositionComponent.h"
#include "VelocityComponent.h"
#include "AccelerationComponent.h"
#include "HealthComponent.h"
#include "EntityTypeComponent.h"

static const int MAX_ENTITIES = 1;

class World {
public:
    static int entity[MAX_ENTITIES];
    static PositionComponent position[MAX_ENTITIES];
    static VelocityComponent velocity[MAX_ENTITIES];
    static AccelerationComponent acceleration[MAX_ENTITIES];
    static HealthComponent health[MAX_ENTITIES];
    static EntityTypeComponent entityType[MAX_ENTITIES];
    
    static int createEntity();
    static void removeEntity(unsigned int id);
    static void removeAllEntities();
private:
    void test();
};

// Initialize static arrays
int World::entity[MAX_ENTITIES] = {};
PositionComponent World::position[MAX_ENTITIES] = {};
VelocityComponent World::velocity[MAX_ENTITIES] = {};
AccelerationComponent World::acceleration[MAX_ENTITIES] = {};
HealthComponent World::health[MAX_ENTITIES] = {};
EntityTypeComponent World::entityType[MAX_ENTITIES] = {};

#endif /* World_h */
