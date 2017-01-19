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

void RenderSystem::render(Window &window, const shared_ptr<Program> prog) {
    glViewport(0, 0, window.getWidth(), window.getHeight());
    // Clear framebuffer.
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    for (int i = 0; i < MAX_ENTITIES; i++) {
        int entity = World::entity[i];
        if ((entity & RENDER_MASK) == RENDER_MASK) {
//            ShaderManager::beginNormalShading();
            shared_ptr<Shape> shape = shapes[World::entityType[entity].type];
            
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

void drawShape(int entity, Window &window, const shared_ptr<Shape> shape, const shared_ptr<Program> prog) {
    prog->bind();
    applyPerspectiveMatrix(window, prog);
    applyCameraMatrix(camera, prog);
    applyTransformMatrix(transform, prog);
    
//    glUniform3f(prog->getUniform("lightPos"), light.pos[0] + lightPosOffset, light.pos[1], light.pos[2]);
//    glUniform3f(prog->getUniform("lightColor"), light.color[0], light.color[1], light.color[2]);
//    glUniform3f(prog->getUniform("sunDir"), sun.dir[0], sun.dir[1], sun.dir[2]);
//    glUniform3f(prog->getUniform("sunColor"), sun.color[0], sun.color[1], sun.color[2]);
//    SetMaterial(material, prog);
    
    PositionComponent position = World::position[entity];
    
    // Draw mesh
    auto M = make_shared<MatrixStack>();
    M->pushMatrix();
    M->translate(vec3(position.x, position.y, position.z));
        M->rotate(rand(), vec3(0, 1, 0));
        
        glUniformMatrix4fv(prog->getUniform("M"), 1, GL_FALSE, value_ptr(M->topMatrix()));
            shape->draw(prog);
    M->popMatrix();
    prog->unbind();
}
