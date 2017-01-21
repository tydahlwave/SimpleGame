//
//  World.h
//  SimpleGame
//
//  Created by Tyler Dahl on 1/18/17.
//
//

#ifndef World_h
#define World_h

#include <vector>

#include "PositionComponent.h"
#include "VelocityComponent.h"
#include "AccelerationComponent.h"
#include "HealthComponent.h"
#include "EntityTypeComponent.h"
#include "ShaderTypeComponent.h"
#include "TransformComponent.h"
#include "UserInputComponent.h"
#include "../Camera.h"

static const int MAX_ENTITIES = 10;

enum Component { // Max of 32 components
    COMP_POSITION       = 0,
    COMP_VELOCITY       = 1 << 0,
    COMP_HEALTH         = 1 << 1,
    COMP_RENDER         = 1 << 2,
    COMP_ENTITY_TYPE    = 1 << 3,
    COMP_SHADER_TYPE    = 1 << 4,
    COMP_TRANSFORM      = 1 << 5,
    COMP_USER_INPUT     = 1 << 6,
    COMP_ACCELERATION   = 1 << 7
};

class World {
public:
    World();
    virtual ~World() {}
    
    int entity[MAX_ENTITIES] = {};
    PositionComponent position[MAX_ENTITIES] = {};
    VelocityComponent velocity[MAX_ENTITIES] = {};
    AccelerationComponent acceleration[MAX_ENTITIES] = {};
    HealthComponent health[MAX_ENTITIES] = {};
    EntityTypeComponent entityType[MAX_ENTITIES] = {};
    ShaderTypeComponent shaderType[MAX_ENTITIES] = {};
    TransformComponent transform[MAX_ENTITIES] = {};
    UserInputComponent userInput[MAX_ENTITIES] = {};
    
    Camera camera;
    
    int createEntity();
    void removeEntity(unsigned int id);
    void removeAllEntities();
private:
};

//Camera camera();

#endif /* World_h */
