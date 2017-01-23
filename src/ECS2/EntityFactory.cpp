//
//  EntityFactory.cpp
//  SimpleGame
//
//  Created by Tyler Dahl on 1/22/17.
//
//

#include "EntityFactory.h"
#include "Transform.h"
#include "Collider.h"
#include "Camera.h"
#include "MeshRenderer.h"

GameObject *EntityFactory::createMainCamera(World *world) {
    GameObject *gameObject = new GameObject("MainCamera");
    gameObject->AddComponent("Camera");
    gameObject->AddComponent("BoxCollider");
    gameObject->world = world;
    return gameObject;
}

GameObject *EntityFactory::createBunny(World *world) {
    GameObject *gameObject = new GameObject("Bunny");
    gameObject->AddComponent("BoxCollider");
    MeshRenderer *meshRenderer = (MeshRenderer*) gameObject->AddComponent("MeshRenderer");
//    meshRenderer->mesh;
    gameObject->world = world;
    return gameObject;
}

GameObject *EntityFactory::createGround(World *world) {
    GameObject *gameObject = new GameObject("Ground");
    gameObject->AddComponent("BoxCollider");
    gameObject->AddComponent("MeshRenderer");
    gameObject->world = world;
    return gameObject;
}

GameObject *EntityFactory::createBarrier(World *world) {
    GameObject *gameObject = new GameObject("Barrier");
    gameObject->AddComponent("BoxCollider");
    gameObject->world = world;
    return gameObject;
}
