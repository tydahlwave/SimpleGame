//
//  GameObject.cpp
//  SimpleGame
//
//  Created by Tyler Dahl on 1/22/17.
//
//

#include <iostream>

#include "GameObject.h"
#include "Collider.h"
#include "Camera.h"
#include "MeshRenderer.h"

GameObject::GameObject() {
    name = "GameObject";
    AddComponent("Transform"); // The transform component is required
}

GameObject::GameObject(std::string name) {
    this->name = name;
    AddComponent("Transform"); // The transform component is required
}

GameObject::GameObject(std::string name, std::vector<std::string> componentNames)
: GameObject(name) {
    for (std::string componentName : componentNames) {
        AddComponent(componentName);
    }
}

Component *GameObject::AddComponent(std::string name) {
    if (!components[name]) {
        Component *component;
        if (name.compare("Transform") == 0) {
            transform = new Transform();
            component = (Component*)transform;
        } else if (name.compare("Collider") == 0) {
            component = (Component*) new Collider();
        } else if (name.compare("Camera") == 0) {
            component = (Component*) new Camera();
        } else if (name.compare("MeshRenderer") == 0) {
            component = (Component*) new MeshRenderer();
        } else {
            component = nullptr;
            std::cout << name << " component does not exist." << std::endl;
        }
        components[name] = component;
    } else {
        std::cout << name << " component has already been added." << std::endl;
    }
    return nullptr;
}

Component *GameObject::GetComponent(std::string name) {
    return components[name];
}
