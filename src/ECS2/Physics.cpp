//
//  Physics.cpp
//  SimpleGame
//
//  Created by Tyler Dahl on 1/22/17.
//
//

#include "Physics.h"
#include "RigidBody.h"
#include "Collider.h"

void Physics::Update(World &world) {
    for (GameObject *gameObject : world.GetGameObjects()) {
        RigidBody *rigidBody = (RigidBody*)gameObject->GetComponent("RigidBody");
        Collider *collider = (Collider*)gameObject->GetComponent("Collider");
        if (rigidBody && rigidBody->useGravity) {
            glm::vec3 accel = rigidBody->acceleration;
            glm::vec3 vel = rigidBody->velocity;
            rigidBody->acceleration += gravity;
            rigidBody->velocity += accel;
            gameObject->transform->position += vel;
        }
    }
}
