//
//  RenderSystem.cpp
//  SimpleGame
//
//  Created by Tyler Dahl on 1/19/17.
//
//

#include <stdio.h>

#include "RenderSystem.h"
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

void RenderSystem::render(World &world, ShaderSystem &shaderSystem, Window &window) {
    glViewport(0, 0, window.getWidth(), window.getHeight());
    // Clear framebuffer.
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    for (int entity = 0; entity < MAX_ENTITIES; entity++) {
        int entityMask = world.entity[entity];
        if ((entityMask & RENDER_MASK) == RENDER_MASK) {
//            ShaderManager::beginNormalShading();
            shared_ptr<Shape> shape = shapes[world.entityType[entity].type];
            shared_ptr<Program> shader = shaderSystem.getShaderByName(world.shaderType[entity].type);
            drawShape(world, entity, window, shape, shader);
        }
    }
}

void applyPerspectiveMatrix(Window &window, const shared_ptr<Program> prog) {
    auto P = make_shared<MatrixStack>();
    float aspect = window.getWidth()/window.getHeight();
    P->perspective(45.0f, aspect, 0.01f, 100.0f);
    glUniformMatrix4fv(prog->getUniform("P"), 1, GL_FALSE, value_ptr(P->topMatrix()));
}

void applyCameraMatrix(World &world, const shared_ptr<Program> prog) {
    auto V = make_shared<MatrixStack>();
    V->lookAt(world.camera.pos, world.camera.lookAt, world.camera.up);
    glUniformMatrix4fv(prog->getUniform("V"), 1, GL_FALSE, value_ptr(V->topMatrix()));
}

void applyTransformMatrix(MatrixStack &transforms, const shared_ptr<Program> prog) {
    glUniformMatrix4fv(prog->getUniform("M"), 1, GL_FALSE, value_ptr(transforms.topMatrix()));
}

void RenderSystem::drawShape(World &world, int entity, Window &window, const shared_ptr<Shape> shape, const shared_ptr<Program> shader) {
    shader->bind();
    
//    Camera camera;
//    Camera::pos = vec3(0, 0, 0);
//    Camera::lookAt = vec3(0, 0, 1);
//    Camera::up = vec3(0, 1, 0);
    
    glUniform3f(shader->getUniform("matAmbientColor"), 0.3294, 0.2235, 0.02745);
    glUniform3f(shader->getUniform("matDiffuseColor"), 0.7804, 0.5686, 0.11373);
    glUniform3f(shader->getUniform("matSpecularColor"), 0.9922f, 0.941176f, 0.80784f);
    glUniform1f(shader->getUniform("matShine"), 27.9f);
    glUniform3f(shader->getUniform("lightPos"), 5, 5, 5);
    glUniform3f(shader->getUniform("lightColor"), 1, 1, 1);
    glUniform3f(shader->getUniform("sunDir"), 0, 1, 0);
    glUniform3f(shader->getUniform("sunColor"), 1, 1, 1);
    
    applyPerspectiveMatrix(window, shader);
    applyCameraMatrix(world, shader);
    applyTransformMatrix(world.transform[entity].transforms, shader);
    
    shape->draw(shader);
    
    shader->unbind();
}
