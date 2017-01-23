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
    GameObject *gameObject = world->CreateGameObject("MainCamera");
    gameObject->AddComponent("Camera");
    gameObject->AddComponent("BoxCollider");
    return gameObject;
}

GameObject *EntityFactory::createBunny(World *world) {
    GameObject *gameObject = world->CreateGameObject("Bunny");
    gameObject->AddComponent("BoxCollider");
    MeshRenderer *meshRenderer = (MeshRenderer*) gameObject->AddComponent("MeshRenderer");
    meshRenderer->mesh = Mesh::bunny;
    meshRenderer->shader = Shader::phong;
    meshRenderer->material = Material::emerald;
    return gameObject;
}

GameObject *EntityFactory::createGround(World *world) {
    GameObject *gameObject = world->CreateGameObject("Ground");
    gameObject->AddComponent("BoxCollider");
    MeshRenderer *meshRenderer = (MeshRenderer*) gameObject->AddComponent("MeshRenderer");
    meshRenderer->mesh = Mesh::plane;
    meshRenderer->shader = Shader::phong;
    meshRenderer->material = Material::bronze;
    return gameObject;
}

GameObject *EntityFactory::createBarrier(World *world) {
    GameObject *gameObject = world->CreateGameObject("Barrier");
    gameObject->AddComponent("BoxCollider");
    return gameObject;
}