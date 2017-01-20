////
////  new_main2.cpp
////  SimpleGame
////
////  Created by Tyler Dahl on 1/19/17.
////
////
//
//#include <iostream>
//#define GLEW_STATIC
//#include <GL/glew.h>
//#include <GLFW/glfw3.h>
//
//#include "../GLSL.h"
//#include "../Program.h"
//#include "../MatrixStack.h"
//#include "../Shape.h"
//#include "../Window.h"
//#include "RenderSystem.h"
//#include "ShaderSystem.h"
//#include "EntityFactory.h"
//
//// value_ptr for glm
//#include <glm/gtc/type_ptr.hpp>
//#include <glm/gtc/matrix_transform.hpp>
//
//using namespace std;
//using namespace glm;
//
//#define LEFT 0
//#define RIGHT 1
//#define CAMERA_SPEED 0.2
//#define CAMERA_STOPPED_THRESHOLD 0.1
//#define NUM_MODELS 10
//
//typedef struct {
//    vec3 pos;
//    vec3 color;
//} PointLight;
//
//typedef struct {
//    vec3 dir;
//    vec3 color;
//} DirectionalLight;
//
//typedef struct {
//    vec3 pos;
//    vec3 lookAt;
//    vec3 up;
//    float velW;
//    float velU;
//} Camera2;
//
//string RESOURCE_DIR = "../../resources/"; // Where the resources are loaded from
////shared_ptr<Program> phongProg;
////shared_ptr<Program> groundProg;
////shared_ptr<Shape> bunny;
////shared_ptr<Shape> sphere;
////shared_ptr<Shape> cube;
////shared_ptr<Shape> robot;
////shared_ptr<Shape> ground;
//
//GLuint VertexArrayID;
//GLuint groundBuffer;
//GLuint groundNormalsBuffer;
//static const GLfloat g_ground_buffer_data[] = {
//    -1.0, 0.0, -1.0,
//    -1.0, 0.0, 1.0,
//    1.0, 0.0, 1.0,
//    -1.0, 0.0, -1.0,
//    1.0, 0.0, 1.0,
//    1.0, 0.0, -1.0
//};
//static const GLfloat g_ground_normals_buffer_data[] = {
//    0.0, 1.0, 0.0,
//    0.0, 1.0, 0.0,
//    0.0, 1.0, 0.0,
//    0.0, 1.0, 0.0,
//    0.0, 1.0, 0.0,
//    0.0, 1.0, 0.0
//};
//
//DirectionalLight sun;
//PointLight light;
//Camera2 camera;
//
//int g_width, g_height;
//float lightPosOffset = 0;
//float alpha = 0;
//float beta = -M_PI/2;
//float t = 0;
//
//// Initialize seeds for the game
//// int globalRand = rand();
//int treeGenRand = rand();
//int treePosRand = rand();
//
////static void error_callback(int error, const char *description) {
////    cerr << description << endl;
////}
////
////static void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods) {
////    if (action == GLFW_PRESS) {
////        if (key == GLFW_KEY_ESCAPE) {
////            glfwSetWindowShouldClose(window, GL_TRUE);
////        } else if (key == GLFW_KEY_SPACE) {
////            // globalRand = rand();
////            treeGenRand = rand();
////        } else if (key == GLFW_KEY_W) {
////            camera.velW = -CAMERA_SPEED;
////        } else if (key == GLFW_KEY_S) {
////            camera.velW = CAMERA_SPEED;
////        } else if (key == GLFW_KEY_A) {
////            camera.velU = -CAMERA_SPEED;
////        } else if (key == GLFW_KEY_D) {
////            camera.velU = CAMERA_SPEED;
////        }
////    } else if (action == GLFW_RELEASE) {
////        if (key == GLFW_KEY_W) {
////            if (camera.velW < -CAMERA_STOPPED_THRESHOLD) {
////                camera.velW = 0;
////            } else {
////                camera.velW = CAMERA_SPEED;
////            }
////        } else if (key == GLFW_KEY_S) {
////            if (camera.velW > CAMERA_STOPPED_THRESHOLD) {
////                camera.velW = 0;
////            } else {
////                camera.velW = -CAMERA_SPEED;
////            }
////        } else if (key == GLFW_KEY_A) {
////            if (camera.velU < -CAMERA_STOPPED_THRESHOLD) {
////                camera.velU = 0;
////            } else {
////                camera.velU = CAMERA_SPEED;
////            }
////        } else if (key == GLFW_KEY_D) {
////            if (camera.velU > CAMERA_STOPPED_THRESHOLD) {
////                camera.velU = 0;
////            } else {
////                camera.velU = -CAMERA_SPEED;
////            }
////        }
////    }
////}
////
////// static void mouse_callback(GLFWwindow *window, int button, int action, int mods) {
//////    double posX, posY;
//////    if (action == GLFW_PRESS) {
//////       glfwGetCursorPos(window, &posX, &posY);
//////       cout << "Pos X " << posX <<  " Pos Y " << posY << endl;
////// 	}
////// }
////
////static void mouse_move_callback(GLFWwindow *window, double posX, double posY) {
////    
////    // Get current window size.
////    int width, height;
////    glfwGetWindowSize(window, &width, &height);
////    
////    // Compute new alpha and beta for the camera lookat point
////    double alpha2 = alpha + ((posY + height/2.0) / height * M_PI*16/18) - M_PI*8/18;
////    double beta2 = beta + ((posX + width/2.0) / width * M_PI*2) - M_PI;
////    
////    // Constrain the view (up and down constrained to (-80,80) degrees)
////    if (alpha2 > M_PI*8/18) alpha2 = M_PI*8/18;
////    if (alpha2 < -M_PI*8/18) alpha2 = -M_PI*8/18;
////    
////    // Compute camera lookat point
////    camera.lookAt[0] = camera.pos[0] + cos(alpha2) * cos(beta2);
////    camera.lookAt[1] = camera.pos[1] + -sin(alpha2);
////    camera.lookAt[2] = camera.pos[2] + cos(alpha2) * cos(M_PI/2 - beta2);
////}
////
////static void resize_callback(GLFWwindow *window, int width, int height) {
////    g_width = width;
////    g_height = height;
////    glViewport(0, 0, width, height);
////}
//
//static void init(RenderSystem &renderSystem, ShaderSystem &shaderSystem)
//{
//    GLSL::checkVersion();
//    
//    // Set background color.
//    glClearColor(.12f, .34f, .56f, 1.0f);
//    // Enable z-buffer test.
//    glEnable(GL_DEPTH_TEST);
//    
//    renderSystem.loadShape("bunny");
//    renderSystem.loadShape("sphere");
//    renderSystem.loadShape("cube");
//    renderSystem.loadShape("intact_robot");
//    renderSystem.loadShape("rect");
//    shaderSystem.loadPhong();
//    shaderSystem.loadGround();
//
////    // Initialize mesh.
////    bunny = make_shared<Shape>();
////    bunny->loadMesh(RESOURCE_DIR + "bunny.obj");
////    bunny->resize();
////    bunny->init();
////    
////    // Initialize mesh.
////    sphere = make_shared<Shape>();
////    sphere->loadMesh(RESOURCE_DIR + "sphere.obj");
////    sphere->resize();
////    sphere->init();
////    
////    // Initialize mesh.
////    cube = make_shared<Shape>();
////    cube->loadMesh(RESOURCE_DIR + "cube.obj");
////    cube->resize();
////    cube->init();
////    
////    // Initialize mesh.
////    robot = make_shared<Shape>();
////    robot->loadMesh(RESOURCE_DIR + "intact_robot.obj");
////    robot->resize();
////    robot->init();
////    
////    // Initialize mesh.
////    ground = make_shared<Shape>();
////    ground->loadMesh(RESOURCE_DIR + "rect.obj");
////    ground->resize();
////    ground->init();
////    
////    // Initialize the GLSL program.
////    phongProg = make_shared<Program>();
////    phongProg->setVerbose(true);
////    phongProg->setShaderNames(RESOURCE_DIR + "phong_vert.glsl", RESOURCE_DIR + "phong_frag.glsl");
////    phongProg->init();
////    phongProg->addUniform("P");
////    phongProg->addUniform("M");
////    phongProg->addUniform("V");
////    phongProg->addAttribute("vertPos");
////    phongProg->addAttribute("vertNor");
////    phongProg->addUniform("lightPos");
////    phongProg->addUniform("lightColor");
////    phongProg->addUniform("sunDir");
////    phongProg->addUniform("sunColor");
////    phongProg->addUniform("matDiffuseColor");
////    phongProg->addUniform("matSpecularColor");
////    phongProg->addUniform("matAmbientColor");
////    phongProg->addUniform("matShine");
////    
////    // Initialize the GLSL program.
////    groundProg = make_shared<Program>();
////    groundProg->setVerbose(true);
////    groundProg->setShaderNames(RESOURCE_DIR + "ground_vert.glsl", RESOURCE_DIR + "ground_frag.glsl");
////    groundProg->init();
////    groundProg->addUniform("P");
////    groundProg->addUniform("M");
////    groundProg->addUniform("V");
////    groundProg->addAttribute("vertPos");
////    groundProg->addAttribute("vertNor");
////    groundProg->addUniform("lightPos");
////    groundProg->addUniform("lightColor");
////    groundProg->addUniform("sunDir");
////    groundProg->addUniform("sunColor");
////    groundProg->addUniform("matDiffuseColor");
////    groundProg->addUniform("matSpecularColor");
////    groundProg->addUniform("matAmbientColor");
////    groundProg->addUniform("matShine");
//}
//
////helper function to set materials
//void SetMaterial(int i, const shared_ptr<Program> prog) {
//    switch (i) {
//        case 0: // Shiny Blue Plastic
//            glUniform3f(prog->getUniform("matAmbientColor"), 0.02, 0.04, 0.2);
//            glUniform3f(prog->getUniform("matDiffuseColor"), 0.0, 0.16, 0.9);
//            glUniform3f(prog->getUniform("matSpecularColor"), 0.14f, 0.2f, 0.8f);
//            glUniform1f(prog->getUniform("matShine"), 120.0f);
//            break;
//        case 1: // Pearl
//            glUniform3f(prog->getUniform("matAmbientColor"), 0.25, 0.20725, 0.20725);
//            glUniform3f(prog->getUniform("matDiffuseColor"), 1.0, 0.829, 0.829);
//            glUniform3f(prog->getUniform("matSpecularColor"), 0.296648f, 0.296648, 0.296648);
//            glUniform1f(prog->getUniform("matShine"), 11.264f);
//            break;
//        case 2: // Brass
//            glUniform3f(prog->getUniform("matAmbientColor"), 0.3294, 0.2235, 0.02745);
//            glUniform3f(prog->getUniform("matDiffuseColor"), 0.7804, 0.5686, 0.11373);
//            glUniform3f(prog->getUniform("matSpecularColor"), 0.9922f, 0.941176f, 0.80784f);
//            glUniform1f(prog->getUniform("matShine"), 27.9f);
//            break;
//        case 3: // Copper
//            glUniform3f(prog->getUniform("matAmbientColor"), 0.1913, 0.0735, 0.0225);
//            glUniform3f(prog->getUniform("matDiffuseColor"), 0.7038, 0.27048, 0.0828);
//            glUniform3f(prog->getUniform("matSpecularColor"), 0.257f, 0.1376f, 0.08601f);
//            glUniform1f(prog->getUniform("matShine"), 12.8f);
//            break;
//        case 4: // Bronze
//            glUniform3f(prog->getUniform("matAmbientColor"), 0.2125f, 0.1275f, 0.054f);
//            glUniform3f(prog->getUniform("matDiffuseColor"), 0.714f, 0.4284f, 0.18144f);
//            glUniform3f(prog->getUniform("matSpecularColor"), 0.393548f, 0.271906f, 0.166721f);
//            glUniform1f(prog->getUniform("matShine"), 25.6f);
//            break;
//        case 5: // Ruby
//            glUniform3f(prog->getUniform("matAmbientColor"), 0.1745f, 0.01175f, 0.01175f);
//            glUniform3f(prog->getUniform("matDiffuseColor"), 0.61424f, 0.04136f, 0.04136f);
//            glUniform3f(prog->getUniform("matSpecularColor"), 0.727811f, 0.626959f, 0.626959f);
//            glUniform1f(prog->getUniform("matShine"), 76.8f);
//            break;
//        case 6: // Emerald
//            glUniform3f(prog->getUniform("matAmbientColor"), 0.0215f, 0.1745f, 0.0215f);
//            glUniform3f(prog->getUniform("matDiffuseColor"), 0.07568f, 0.61424f, 0.07568f);
//            glUniform3f(prog->getUniform("matSpecularColor"), 0.633f, 0.727811f, 0.633f);
//            glUniform1f(prog->getUniform("matShine"), 76.8f);
//            break;
//        case 7: // Polished Gold
//            glUniform3f(prog->getUniform("matAmbientColor"), 0.24725f, 0.2245f, 0.0645f);
//            glUniform3f(prog->getUniform("matDiffuseColor"), 0.34615f, 0.3143f, 0.0903f);
//            glUniform3f(prog->getUniform("matSpecularColor"), 0.797357f, 0.723991f, 0.208006f);
//            glUniform1f(prog->getUniform("matShine"), 83.2f);
//            break;
//    }
//}
//
//void drawShapeWithShaderProgram(const shared_ptr<Shape> shape, const shared_ptr<Program> prog) {
//    auto V = make_shared<MatrixStack>();
//    V->pushMatrix();
//    V->lookAt(camera.pos, camera.lookAt, camera.up);
//    glUniformMatrix4fv(prog->getUniform("V"), 1, GL_FALSE, value_ptr(V->topMatrix()));
//    shape->draw(prog);
//    V->popMatrix();
//}
//
//void drawShape(const shared_ptr<Shape> shape, const shared_ptr<Program> prog, const shared_ptr<MatrixStack> P, const shared_ptr<MatrixStack> M,
//               float xPos, float yPos, float zPos, int material) {
//    prog->bind();
//    glUniformMatrix4fv(prog->getUniform("P"), 1, GL_FALSE, value_ptr(P->topMatrix()));
//    glUniform3f(prog->getUniform("lightPos"), light.pos[0] + lightPosOffset, light.pos[1], light.pos[2]);
//    glUniform3f(prog->getUniform("lightColor"), light.color[0], light.color[1], light.color[2]);
//    glUniform3f(prog->getUniform("sunDir"), sun.dir[0], sun.dir[1], sun.dir[2]);
//    glUniform3f(prog->getUniform("sunColor"), sun.color[0], sun.color[1], sun.color[2]);
//    SetMaterial(material, prog);
//    
//    // Draw mesh
//    M->pushMatrix();
//    M->translate(vec3(xPos, yPos, zPos));
//    M->rotate(rand(), vec3(0, 1, 0));
//    
//    glUniformMatrix4fv(prog->getUniform("M"), 1, GL_FALSE, value_ptr(M->topMatrix()));
//    drawShapeWithShaderProgram(shape, prog);
//    M->popMatrix();
//    prog->unbind();
//}
//
//void applyPerspectiveMatrix2(Window &window, const shared_ptr<Program> prog) {
//    auto P = make_shared<MatrixStack>();
//    float aspect = window.getWidth()/(float)window.getHeight();
//    P->perspective(45.0f, aspect, 0.01f, 100.0f);
//    glUniformMatrix4fv(prog->getUniform("P"), 1, GL_FALSE, value_ptr(P->topMatrix()));
//}
//
//void applyCameraMatrix2(World &world, const shared_ptr<Program> prog) {
//    auto V = make_shared<MatrixStack>();
//    V->lookAt(world.camera.pos, world.camera.lookAt, world.camera.up);
//    glUniformMatrix4fv(prog->getUniform("V"), 1, GL_FALSE, value_ptr(V->topMatrix()));
//}
//
//void applyTransformMatrix2(MatrixStack transforms, const shared_ptr<Program> prog) {
//    glUniformMatrix4fv(prog->getUniform("M"), 1, GL_FALSE, value_ptr(transforms.topMatrix()));
//}
//
//void drawGround(World &world, Window &window, const shared_ptr<Shape> shape, const shared_ptr<Program> prog, const shared_ptr<MatrixStack> P, const shared_ptr<MatrixStack> M,
//               float xPos, float yPos, float zPos, int material) {
//    prog->bind();
//    glUniformMatrix4fv(prog->getUniform("P"), 1, GL_FALSE, value_ptr(P->topMatrix()));
//    glUniform3f(prog->getUniform("lightPos"), light.pos[0] + lightPosOffset, light.pos[1], light.pos[2]);
//    glUniform3f(prog->getUniform("lightColor"), light.color[0], light.color[1], light.color[2]);
//    glUniform3f(prog->getUniform("sunDir"), sun.dir[0], sun.dir[1], sun.dir[2]);
//    glUniform3f(prog->getUniform("sunColor"), sun.color[0], sun.color[1], sun.color[2]);
//    SetMaterial(material, prog);
//    
////    // Draw mesh
////    M->pushMatrix();
////    M->translate(vec3(xPos, yPos, zPos));
//////    M->rotate(rand(), vec3(0, 1, 0));
////    M->scale(50);
////    
////    glUniformMatrix4fv(prog->getUniform("M"), 1, GL_FALSE, value_ptr(M->topMatrix()));
////    drawShapeWithShaderProgram(shape, prog);
////    M->popMatrix();
//    
//    applyPerspectiveMatrix2(window, prog);
//    applyCameraMatrix2(world, prog);
//    applyTransformMatrix2(world.transform[0].transforms, prog);
//    
//    shape->draw(prog);
//    
//    prog->unbind();
//}
//
//static void render(World &world, Window &window, RenderSystem &renderSystem, ShaderSystem &shaderSystem) {
//    // Get current frame buffer size.
////    int width, height;
////    glfwGetFramebufferSize(window, &width, &height);
//    int width = window.getWidth();
//    int height = window.getHeight();
//    glViewport(0, 0, width, height);
//    
//    // Clear framebuffer.
//    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//    
//    //Use the matrix stack for Lab 6
//    float aspect = width/(float)height;
//    
//    // Create the matrix stacks - please leave these alone for now
//    auto P = make_shared<MatrixStack>();
//    auto M = make_shared<MatrixStack>();
//    
//    // Begin matrix transforms
//    P->pushMatrix();
//    // Apply perspective projection.
//    P->perspective(45.0f, aspect, 0.01f, 100.0f);
//    
//    // Draw the ground
////    drawGround(P, M);
//    drawGround(world, window, renderSystem.shapes["rect"], shaderSystem.getShaderByName("ground"), P, M, 0, -1, 0, 2);
//    
//    // Copy tree random seeds so we generate the same trees
//    int tempTreeGenRand = treeGenRand;
//    int tempTreePosRand = treePosRand;
//    // Draw 10 random trees
//    for (int i = 0; i < NUM_MODELS; i++) {
//        // Generate the random tree positions;
//        srand(tempTreePosRand);
//        float posX = rand() / (float)RAND_MAX * 15 - 7.5;
//        float posZ = rand() / (float)RAND_MAX * 15 - 7.5;
//        float randomRotation = rand();
//        tempTreePosRand = rand(); // Store the random seed for later use
//        // Generate the random trees
//        srand(tempTreeGenRand);
////        renderLSystemTree(createLSystemTreeString("0", 5), randomRotation, phongProg, P, M, posX, -1, posZ, 4);
//        tempTreeGenRand = rand(); // Store the random seed for later use
//    }
//    // Draw 10 random robots
//    for (int i = 0; i < NUM_MODELS; i++) {
//        float posX = rand() / (float)RAND_MAX * 15 - 7.5;
//        float posZ = rand() / (float)RAND_MAX * 15 - 7.5;
//        float material = rand() % 8;
//        drawShape(renderSystem.shapes["intact_robot"], shaderSystem.getShaderByName("phong"), P, M, posX, -0.3, posZ, material);
//    }
//    
//    P->popMatrix();
//    t += 0.01;
//    sun.dir[0] = cos(t);
//    sun.dir[1] = sin(t);
//    sun.dir[2] = cos(t);
//}
//
//static void updateCamera() {
//    vec3 gaze = camera.lookAt - camera.pos;
//    vec3 w = normalize(-gaze);
//    vec3 u = normalize(cross(camera.up, w));
//    if (abs(camera.velW) > CAMERA_STOPPED_THRESHOLD) {
//        camera.pos += camera.velW * w;
//        camera.lookAt += camera.velW * w;
//    }
//    if (abs(camera.velU) > CAMERA_STOPPED_THRESHOLD) {
//        camera.pos += camera.velU * u;
//        camera.lookAt += camera.velU * u;
//    }
//}
//
//void initValues() {
//    // Initialize light sources
//    light.pos = vec3(0, 0, 0);
//    light.color = vec3(1, 1, 1);
//    sun.dir = normalize(vec3(5, 5, 5));
//    sun.color = vec3(253/255.0, 184/255.0, 19/255.0);
//    
//    // Initialize camera
//    camera.pos = vec3(0, 0, 0);
//    camera.lookAt = vec3(0, 0, -1);
//    camera.up = vec3(0, 1, 0);
//}
//
//void initEntities(World &world) {
//    EntityFactory::createGround(world);
//}
//
//int main(int argc, char **argv)
//{
//    if (argc < 2) {
//        cout << "Using ../resources/ as the default resources directory." << endl;
//        cout << "Please specify an argument if you wish to change the resources directory." << endl;
//    } else {
//        RESOURCE_DIR = argv[1] + string("/");
//    }
//    
//    World world;
//    Window window(&world);
//    RenderSystem renderSystem;
//    ShaderSystem shaderSystem;
//    
//    // Initialize things
//    initValues();
//    window.initialize();
//    initEntities(world);
//    
//    // Initialize scene. Note geometry initialized in init now
//    init(renderSystem, shaderSystem);
//    
//    // Loop until the user closes the window.
//    while(!window.shouldClose()) {
//        // Render scene.
//        render(world, window, renderSystem, shaderSystem);
//        // Update camera;
//        updateCamera();
//        // Swap front and back buffers.
//        window.swapBuffers();
//        // Poll for and process events.
//        window.pollEvents();
//    }
//    // Quit program.
//    window.terminate();
//    return 0;
//}
