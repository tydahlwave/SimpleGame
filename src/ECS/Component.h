//
//  Component.h
//  SimpleGame
//
//  Created by Tyler Dahl on 1/21/17.
//
//

#ifndef Component_h
#define Component_h

#include "glm/glm.hpp"

//struct PositionComponent {
//    
//};
//
//struct VelocityComponent {
//    
//};
//
//struct AccelerationComponent {
//    
//};

enum EntityType {
    Player,
    Sheep,
    Tree,
    Wolf,
    Bunny
};

struct EntityTypeComponent {
    
};

struct MovementComponent {
    glm::vec3 pos;
    glm::vec3 vel;
    glm::vec3 acc;
};

struct HealthComponent {
    int curHp;
    int maxHp;
};

struct UserInputComponent {
    bool isJumping;
    bool isRunning;
    vec2 moveDir;
    vec2 mousePos;
};

//struct MeshComponent {
//    
//};
//
//struct ShaderComponent {
//    
//};

struct AppearanceComponent {
    string meshName;
    string shaderName;
};

struct

#endif /* Component_h */
