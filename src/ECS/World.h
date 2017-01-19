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
#include "ShaderTypeComponent.h"
#include "TransformComponent.h"
#include "UserInputComponent.h"

static const int MAX_ENTITIES = 1;

enum Component { // Max of 32 components
    COMP_POSITION       = 0,
    COMP_VELOCITY       = 1 << 0,
    COMP_HEALTH         = 1 << 1,
    COMP_RENDER         = 1 << 2,
    COMP_ENTITY_TYPE    = 1 << 3,
    COMP_SHADER_TYPE    = 1 << 4,
    COMP_TRANSFORM      = 1 << 5,
    COMP_USER_INPUT     = 1 << 6
};

class World {
public:
    static int entity[MAX_ENTITIES];
    static PositionComponent position[MAX_ENTITIES];
    static VelocityComponent velocity[MAX_ENTITIES];
    static AccelerationComponent acceleration[MAX_ENTITIES];
    static HealthComponent health[MAX_ENTITIES];
    static EntityTypeComponent entityType[MAX_ENTITIES];
    static ShaderTypeComponent shaderType[MAX_ENTITIES];
    static TransformComponent transform[MAX_ENTITIES];
    static UserInputComponent userInput[MAX_ENTITIES];
    
    static int createEntity();
    static void removeEntity(unsigned int id);
    static void removeAllEntities();
private:
    void test();
};

#endif /* World_h */
