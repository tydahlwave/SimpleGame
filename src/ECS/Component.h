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

class Object {
public:
    string name = "Object";
};

class Color {
public:
    vec4 value; // r, g, b, a
};

class World {
public:
    
    AddComponentToEntity();
};



class GameObject : Object {
public:
    GameObject();
    GameObject(string name);
    GameObject(string name, );
    virtual ~GameObject() {};
    
    World *world;
    Transform *transform;
    
    Component *AddComponent(string name);
    Component *GetComponent(string name);
    vector<Component> GetComponents(string name);
};





class Component : Object {
public:
    GameObject *gameObject;
};

class Transform : Component {
public:
    vec3 position = vec3(0, 0, 0);
    vec3 rotation = vec3(0, 0, 0);
    vec3 scale = vec3(1, 1, 1);
};

class Material : Component {
public:
    Color *color;
    Texture *texture;
};

class Collider : Component {
public:
    RigidBody *rigidBody; // The rigidbody of the gameobject the component is attached to
};

enum ProjectionType { Orthographic, Perspective };
class Camera : Component {
public:
    ProjectionType projectionType;
    float near = 1;
    float far = 100;
};

class MeshRenderer : Component {
public:
    
};


////struct PositionComponent {
////    
////};
////
////struct VelocityComponent {
////    
////};
////
////struct AccelerationComponent {
////    
////};
//
//enum EntityType {
//    Player,
//    Sheep,
//    Tree,
//    Wolf,
//    Bunny
//};
//
//struct EntityTypeComponent {
//    
//};
//
//struct MovementComponent {
//    glm::vec3 pos;
//    glm::vec3 vel;
//    glm::vec3 acc;
//};
//
//struct HealthComponent {
//    int curHp;
//    int maxHp;
//};
//
//struct UserInputComponent {
//    bool isJumping;
//    bool isRunning;
//    vec2 moveDir;
//    vec2 mousePos;
//};
//
////struct MeshComponent {
////    
////};
////
////struct ShaderComponent {
////    
////};
//
//struct AppearanceComponent {
//    string meshName;
//    string shaderName;
//};

#endif /* Component_h */
