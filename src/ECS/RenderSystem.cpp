//
//  RenderSystem.cpp
//  SimpleGame
//
//  Created by Tyler Dahl on 1/19/17.
//
//

#include <stdio.h>

#include "RenderSystem.h"
#include "World.h"
#include "../MatrixStack.h"
#include "../Program.h"
#include "../Camera.h"

// value_ptr for glm
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>

using namespace glm;

static const string RESOURCE_DIR = "../../resources/";
static const int RENDER_MASK = (COMP_POSITION | COMP_ENTITY_TYPE | COMP_SHADER_TYPE);

void RenderSystem::loadShape(string filename) {
    shared_ptr<Shape> shape = make_shared<Shape>();
    shape->loadMesh(RESOURCE_DIR + filename + ".obj");
    shape->resize();
    shape->init();
    shapes[filename] = shape;
}

void RenderSystem::render(ShaderSystem &shaderSystem, Window &window) {
    glViewport(0, 0, window.getWidth(), window.getHeight());
    // Clear framebuffer.
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    for (int entity = 0; entity < MAX_ENTITIES; entity++) {
        int entityMask = World::entity[entity];
        if ((entityMask & RENDER_MASK) == RENDER_MASK) {
//            ShaderManager::beginNormalShading();
            shared_ptr<Shape> shape = shapes[World::entityType[entity].type];
            shared_ptr<Program> shader = shaderSystem.getShaderByName(World::shaderType[entity].type);
            drawShape(entity, window, shape, shader);
        }
    }
}

void applyPerspectiveMatrix(Window &window, const shared_ptr<Program> prog) {
    auto P = make_shared<MatrixStack>();
    float aspect = window.getWidth()/window.getHeight();
    P->perspective(45.0f, aspect, 0.01f, 100.0f);
    glUniformMatrix4fv(prog->getUniform("P"), 1, GL_FALSE, value_ptr(P->topMatrix()));
}

void applyCameraMatrix(Camera &camera, const shared_ptr<Program> prog) {
    auto V = make_shared<MatrixStack>();
    V->lookAt(camera.pos, camera.lookAt, camera.up);
    glUniformMatrix4fv(prog->getUniform("V"), 1, GL_FALSE, value_ptr(V->topMatrix()));
}

void applyTransformMatrix(MatrixStack &transforms, const shared_ptr<Program> prog) {
    glUniformMatrix4fv(prog->getUniform("M"), 1, GL_FALSE, value_ptr(transforms.topMatrix()));
}

void RenderSystem::drawShape(int entity, Window &window, const shared_ptr<Shape> shape, const shared_ptr<Program> shader) {
    shader->bind();
    
    Camera camera;
    camera.pos = vec3(0, 0, 0);
    camera.lookAt = vec3(0, 0, 1);
    camera.up = vec3(0, 1, 0);
    
    applyPerspectiveMatrix(window, shader);
    applyCameraMatrix(camera, shader);
    applyTransformMatrix(World::transform[entity].transforms, shader);
    
    shape->draw(shader);
    
    shader->unbind();
}
