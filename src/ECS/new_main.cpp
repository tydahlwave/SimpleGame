//
//  new_main.cpp
//  SimpleGame
//
//  Created by Tyler Dahl on 1/18/17.
//
//

#include <stdio.h>
#include <memory>

#include "../GLSL.h"
#include "../Window.h"
#include "../Program.h"
#include "../Shape.h"
#include "RenderSystem.h"
#include "ShaderSystem.h"
//#include "EntityManager.h"
#include "EntityFactory.h"
#include "World.h"

// value_ptr for glm
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>

using namespace std;
using namespace glm;

#define CAMERA_STOPPED_THRESHOLD 0.1

string RESOURCE_DIR = "../../resources/"; // Where the resources are loaded from

static void init(RenderSystem &renderer, ShaderSystem &shader)
{
    GLSL::checkVersion();
    
    // Set background color.
    glClearColor(.12f, .34f, .56f, 1.0f);
    // Enable z-buffer test.
    glEnable(GL_DEPTH_TEST);
    
    renderer.loadShape("bunny");
    renderer.loadShape("rect");
    shader.loadPhong();
    shader.loadGround();
}

void initGameObjects(World &world) {
    EntityFactory::createGround(world);
    EntityFactory::createSheep(world);
}

void doSomething(World &world, Window &window, RenderSystem &renderSystem, ShaderSystem &shaderSystem) {
    float aspect = window.getWidth()/(float)window.getHeight();
    auto shape = renderSystem.shapes["bunny"];
    auto prog = shaderSystem.getShaderByName("ground");

    // Create the matrix stacks - please leave these alone for now
    auto P = make_shared<MatrixStack>();
    auto M = make_shared<MatrixStack>();

    // Begin matrix transforms
    P->pushMatrix();
    // Apply perspective projection.
    P->perspective(45.0f, aspect, 0.01f, 100.0f);

    prog->bind();
    glUniformMatrix4fv(prog->getUniform("P"), 1, GL_FALSE, value_ptr(P->topMatrix()));
    glUniform3f(prog->getUniform("lightPos"), 0, 0, 0);
    glUniform3f(prog->getUniform("lightColor"), 1, 1, 1);
    glUniform3f(prog->getUniform("sunDir"), 1, 1, 1);
    glUniform3f(prog->getUniform("sunColor"), 1, 1, 1);
    glUniform3f(prog->getUniform("matAmbientColor"), 0.02, 0.04, 0.2);
    glUniform3f(prog->getUniform("matDiffuseColor"), 0.0, 0.16, 0.9);
    glUniform3f(prog->getUniform("matSpecularColor"), 0.14f, 0.2f, 0.8f);
    glUniform1f(prog->getUniform("matShine"), 120.0f);

    // Draw mesh
    M->pushMatrix();
        M->translate(vec3(0, 0, 0));
//        M->rotate(rand(), Vector3f(0, 1, 0));

        glUniformMatrix4fv(prog->getUniform("M"), 1, GL_FALSE, value_ptr(M->topMatrix()));
        auto V = make_shared<MatrixStack>();
        V->pushMatrix();
            V->lookAt(world.camera.pos, world.camera.lookAt, world.camera.up);
            glUniformMatrix4fv(prog->getUniform("V"), 1, GL_FALSE, value_ptr(V->topMatrix()));
            shape->draw(prog);
        V->popMatrix();
    M->popMatrix();
    prog->unbind();
}

static void updateCamera(World &world) {
   vec3 gaze = world.camera.lookAt - world.camera.pos;
   vec3 w = normalize(-gaze);
   vec3 u = normalize(cross(world.camera.up, w));
   if (abs(world.camera.vel[2]) > CAMERA_STOPPED_THRESHOLD) {
      world.camera.pos += world.camera.vel[2] * w;
      world.camera.lookAt += world.camera.vel[2] * w;
   }
   if (abs(world.camera.vel[0]) > CAMERA_STOPPED_THRESHOLD) {
      world.camera.pos += world.camera.vel[0] * u;
      world.camera.lookAt += world.camera.vel[0] * u;
   }
}

int main(int argc, char **argv) {
    RenderSystem renderSystem;
    ShaderSystem shaderSystem;
    World world;
    Window window(&world);
//    Graphics graphics = new Graphics();
    
    // Initialization
    window.initialize();
    initGameObjects(world);
    
    // Initialize scene. Note geometry initialized in init now
    init(renderSystem, shaderSystem);
    
    // Game loop
    while (!window.shouldClose()) {
        // Update objects
//        for (GameObject* obj : gameObjects) {
//            obj.update();
//        }
        doSomething(world, window, renderSystem, shaderSystem);
        // Render scene.
        renderSystem.render(world, shaderSystem, window);
        // Update camera;
        updateCamera(world);
        
        // Swap front and back buffers.
        window.swapBuffers();
        // Poll for and process events.
        window.pollEvents();
    }
    
    // Clean up
    window.terminate();
    return 0;
}
