//#include <iostream>
//#define GLEW_STATIC
//#include <GL/glew.h>
//#include <GLFW/glfw3.h>
//
//#include "GLSL.h"
//#include "Program.h"
//#include "MatrixStack.h"
//#include "Shape.h"
//
//using namespace std;
//using namespace Eigen;
//
//#define LEFT 0
//#define RIGHT 1
//#define CAMERA_SPEED 0.2
//#define CAMERA_STOPPED_THRESHOLD 0.1
//#define NUM_MODELS 10
//
//typedef struct {
//   Vector3f pos;
//   Vector3f color;
//} PointLight;
//
//typedef struct {
//   Vector3f dir;
//   Vector3f color;
//} DirectionalLight;
//
//typedef struct {
//   Vector3f pos;
//   Vector3f lookAt;
//   Vector3f up;
//   float velW;
//   float velU;
//} Camera;
//
//GLFWwindow *window; // Main application window
//string RESOURCE_DIR = "../../resources/"; // Where the resources are loaded from
//shared_ptr<Program> phongProg;
//shared_ptr<Program> groundProg;
//shared_ptr<Shape> bunny;
//shared_ptr<Shape> sphere;
//shared_ptr<Shape> cube;
//shared_ptr<Shape> robot;
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
//Camera camera;
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
//static void error_callback(int error, const char *description) {
//	cerr << description << endl;
//}
//
//static void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods) {
//   if (action == GLFW_PRESS) {
//   	if (key == GLFW_KEY_ESCAPE) {
//   		glfwSetWindowShouldClose(window, GL_TRUE);
//   	} else if (key == GLFW_KEY_SPACE) {
//         // globalRand = rand();
//         treeGenRand = rand();
//      } else if (key == GLFW_KEY_W) {
//         camera.velW = -CAMERA_SPEED;
//      } else if (key == GLFW_KEY_S) {
//         camera.velW = CAMERA_SPEED;
//      } else if (key == GLFW_KEY_A) {
//         camera.velU = -CAMERA_SPEED;
//      } else if (key == GLFW_KEY_D) {
//         camera.velU = CAMERA_SPEED;
//      }
//   } else if (action == GLFW_RELEASE) {
//      if (key == GLFW_KEY_W) {
//         if (camera.velW < -CAMERA_STOPPED_THRESHOLD) {
//            camera.velW = 0;
//         } else {
//            camera.velW = CAMERA_SPEED;
//         }
//      } else if (key == GLFW_KEY_S) {
//         if (camera.velW > CAMERA_STOPPED_THRESHOLD) {
//            camera.velW = 0;
//         } else {
//            camera.velW = -CAMERA_SPEED;
//         }
//      } else if (key == GLFW_KEY_A) {
//         if (camera.velU < -CAMERA_STOPPED_THRESHOLD) {
//            camera.velU = 0;
//         } else {
//            camera.velU = CAMERA_SPEED;
//         }
//      } else if (key == GLFW_KEY_D) {
//         if (camera.velU > CAMERA_STOPPED_THRESHOLD) {
//            camera.velU = 0;
//         } else {
//            camera.velU = -CAMERA_SPEED;
//         }
//      }
//   }
//}
//
//// static void mouse_callback(GLFWwindow *window, int button, int action, int mods) {
////    double posX, posY;
////    if (action == GLFW_PRESS) {
////       glfwGetCursorPos(window, &posX, &posY);
////       cout << "Pos X " << posX <<  " Pos Y " << posY << endl;
//// 	}
//// }
//
//static void mouse_move_callback(GLFWwindow *window, double posX, double posY) {
//
//   // Get current window size.
//   int width, height;
//   glfwGetWindowSize(window, &width, &height);
//
//   // Compute new alpha and beta for the camera lookat point
//   double alpha2 = alpha + ((posY + height/2.0) / height * M_PI*16/18) - M_PI*8/18;
//   double beta2 = beta + ((posX + width/2.0) / width * M_PI*2) - M_PI;
//
//   // Constrain the view (up and down constrained to (-80,80) degrees)
//   if (alpha2 > M_PI*8/18) alpha2 = M_PI*8/18;
//   if (alpha2 < -M_PI*8/18) alpha2 = -M_PI*8/18;
//
//   // Compute camera lookat point
//   camera.lookAt[0] = camera.pos[0] + cos(alpha2) * cos(beta2);
//   camera.lookAt[1] = camera.pos[1] + -sin(alpha2);
//   camera.lookAt[2] = camera.pos[2] + cos(alpha2) * cos(M_PI/2 - beta2);
//}
//
//static void resize_callback(GLFWwindow *window, int width, int height) {
//   g_width = width;
//   g_height = height;
//   glViewport(0, 0, width, height);
//}
//
//static void init()
//{
//	GLSL::checkVersion();
//
//	// Set background color.
//	glClearColor(.12f, .34f, .56f, 1.0f);
//	// Enable z-buffer test.
//	glEnable(GL_DEPTH_TEST);
//
//	// Initialize mesh.
//	bunny = make_shared<Shape>();
//	bunny->loadMesh(RESOURCE_DIR + "bunny.obj");
//	bunny->resize();
//	bunny->init();
//
//   // Initialize mesh.
//   sphere = make_shared<Shape>();
//   sphere->loadMesh(RESOURCE_DIR + "sphere.obj");
//   sphere->resize();
//   sphere->init();
//
//   // Initialize mesh.
//   cube = make_shared<Shape>();
//   cube->loadMesh(RESOURCE_DIR + "cube.obj");
//   cube->resize();
//   cube->init();
//
//   // Initialize mesh.
//   robot = make_shared<Shape>();
//   robot->loadMesh(RESOURCE_DIR + "intact_robot.obj");
//   robot->resize();
//   robot->init();
//
//   // Initialize the GLSL program.
//   phongProg = make_shared<Program>();
//   phongProg->setVerbose(true);
//   phongProg->setShaderNames(RESOURCE_DIR + "phong_vert.glsl", RESOURCE_DIR + "phong_frag.glsl");
//   phongProg->init();
//   phongProg->addUniform("P");
//   phongProg->addUniform("M");
//   phongProg->addUniform("V");
//   phongProg->addAttribute("vertPos");
//   phongProg->addAttribute("vertNor");
//   phongProg->addUniform("lightPos");
//   phongProg->addUniform("lightColor");
//   phongProg->addUniform("sunDir");
//   phongProg->addUniform("sunColor");
//   phongProg->addUniform("matDiffuseColor");
//   phongProg->addUniform("matSpecularColor");
//   phongProg->addUniform("matAmbientColor");
//   phongProg->addUniform("matShine");
//
//   // Initialize the GLSL program.
//   groundProg = make_shared<Program>();
//   groundProg->setVerbose(true);
//   groundProg->setShaderNames(RESOURCE_DIR + "ground_vert.glsl", RESOURCE_DIR + "ground_frag.glsl");
//   groundProg->init();
//   groundProg->addUniform("P");
//   groundProg->addUniform("M");
//   groundProg->addUniform("V");
//   groundProg->addAttribute("vertPos");
//   groundProg->addAttribute("vertNor");
//   groundProg->addUniform("lightPos");
//   groundProg->addUniform("lightColor");
//   groundProg->addUniform("sunDir");
//   groundProg->addUniform("sunColor");
//   groundProg->addUniform("matDiffuseColor");
//   groundProg->addUniform("matSpecularColor");
//   groundProg->addUniform("matAmbientColor");
//   groundProg->addUniform("matShine");
//}
//
//static void initGeom() {
//   // Initialize the vertex array object
//   glGenVertexArrays(1, &VertexArrayID);
//   glBindVertexArray(VertexArrayID);
//
//   // Send the ground position array to the GPU
//   glGenBuffers(1, &groundBuffer);
//   glBindBuffer(GL_ARRAY_BUFFER, groundBuffer);
//   glBufferData(GL_ARRAY_BUFFER, sizeof(g_ground_buffer_data), g_ground_buffer_data, GL_DYNAMIC_DRAW);
//
//   // Send the ground normal array to the GPU
//   glGenBuffers(1, &groundNormalsBuffer);
//   glBindBuffer(GL_ARRAY_BUFFER, groundNormalsBuffer);
//   glBufferData(GL_ARRAY_BUFFER, sizeof(g_ground_normals_buffer_data), g_ground_normals_buffer_data, GL_DYNAMIC_DRAW);
//}
//
////helper function to set materials
//void SetMaterial(int i, const shared_ptr<Program> prog) {
//   switch (i) {
//    case 0: // Shiny Blue Plastic
//      glUniform3f(prog->getUniform("matAmbientColor"), 0.02, 0.04, 0.2);
//      glUniform3f(prog->getUniform("matDiffuseColor"), 0.0, 0.16, 0.9);
//      glUniform3f(prog->getUniform("matSpecularColor"), 0.14f, 0.2f, 0.8f);
//      glUniform1f(prog->getUniform("matShine"), 120.0f);
//      break;
//    case 1: // Pearl
//      glUniform3f(prog->getUniform("matAmbientColor"), 0.25, 0.20725, 0.20725);
//      glUniform3f(prog->getUniform("matDiffuseColor"), 1.0, 0.829, 0.829);
//      glUniform3f(prog->getUniform("matSpecularColor"), 0.296648f, 0.296648, 0.296648);
//      glUniform1f(prog->getUniform("matShine"), 11.264f);
//      break;
//    case 2: // Brass
//      glUniform3f(prog->getUniform("matAmbientColor"), 0.3294, 0.2235, 0.02745);
//      glUniform3f(prog->getUniform("matDiffuseColor"), 0.7804, 0.5686, 0.11373);
//      glUniform3f(prog->getUniform("matSpecularColor"), 0.9922f, 0.941176f, 0.80784f);
//      glUniform1f(prog->getUniform("matShine"), 27.9f);
//      break;
//    case 3: // Copper
//      glUniform3f(prog->getUniform("matAmbientColor"), 0.1913, 0.0735, 0.0225);
//      glUniform3f(prog->getUniform("matDiffuseColor"), 0.7038, 0.27048, 0.0828);
//      glUniform3f(prog->getUniform("matSpecularColor"), 0.257f, 0.1376f, 0.08601f);
//      glUniform1f(prog->getUniform("matShine"), 12.8f);
//      break;
//    case 4: // Bronze
//      glUniform3f(prog->getUniform("matAmbientColor"), 0.2125f, 0.1275f, 0.054f);
//      glUniform3f(prog->getUniform("matDiffuseColor"), 0.714f, 0.4284f, 0.18144f);
//      glUniform3f(prog->getUniform("matSpecularColor"), 0.393548f, 0.271906f, 0.166721f);
//      glUniform1f(prog->getUniform("matShine"), 25.6f);
//      break;
//    case 5: // Ruby
//      glUniform3f(prog->getUniform("matAmbientColor"), 0.1745f, 0.01175f, 0.01175f);
//      glUniform3f(prog->getUniform("matDiffuseColor"), 0.61424f, 0.04136f, 0.04136f);
//      glUniform3f(prog->getUniform("matSpecularColor"), 0.727811f, 0.626959f, 0.626959f);
//      glUniform1f(prog->getUniform("matShine"), 76.8f);
//      break;
//    case 6: // Emerald
//      glUniform3f(prog->getUniform("matAmbientColor"), 0.0215f, 0.1745f, 0.0215f);
//      glUniform3f(prog->getUniform("matDiffuseColor"), 0.07568f, 0.61424f, 0.07568f);
//      glUniform3f(prog->getUniform("matSpecularColor"), 0.633f, 0.727811f, 0.633f);
//      glUniform1f(prog->getUniform("matShine"), 76.8f);
//      break;
//    case 7: // Polished Gold
//      glUniform3f(prog->getUniform("matAmbientColor"), 0.24725f, 0.2245f, 0.0645f);
//      glUniform3f(prog->getUniform("matDiffuseColor"), 0.34615f, 0.3143f, 0.0903f);
//      glUniform3f(prog->getUniform("matSpecularColor"), 0.797357f, 0.723991f, 0.208006f);
//      glUniform1f(prog->getUniform("matShine"), 83.2f);
//      break;
//   }
//}
//
//void drawGround(const shared_ptr<MatrixStack> P, const shared_ptr<MatrixStack> M) {
//   // Bind the rectangle GLSL program
//   groundProg->bind();
//   auto V = make_shared<MatrixStack>();
//   glUniformMatrix4fv(groundProg->getUniform("P"), 1, GL_FALSE, P->topMatrix().data());
//   glUniform3f(groundProg->getUniform("lightPos"), light.pos[0] + lightPosOffset, light.pos[1], light.pos[2]);
//   glUniform3f(groundProg->getUniform("lightColor"), light.color[0], light.color[1], light.color[2]);
//   glUniform3f(groundProg->getUniform("sunDir"), sun.dir[0], sun.dir[1], sun.dir[2]);
//   glUniform3f(groundProg->getUniform("sunColor"), sun.color[0], sun.color[1], sun.color[2]);
//   SetMaterial(4, groundProg);
//    
//   M->pushMatrix();
//      M->translate(Vector3f(0, -1, 0));
//      M->scale(Vector3f(1000, 1000, 1000));
//
//      glUniformMatrix4fv(groundProg->getUniform("M"), 1, GL_FALSE, M->topMatrix().data());
//      V->pushMatrix();
//         V->lookAt(camera.pos, camera.lookAt, camera.up);
//         glUniformMatrix4fv(groundProg->getUniform("V"), 1, GL_FALSE, V->topMatrix().data());
//         
//         glBindVertexArray(VertexArrayID);
//         glEnableVertexAttribArray(groundProg->getAttribute("vertPos"));
//         glBindBuffer(GL_ARRAY_BUFFER, groundBuffer);
//         glVertexAttribPointer(groundProg->getAttribute("vertPos"), 3, GL_FLOAT, GL_FALSE, 0, (void*) 0);
//         glEnableVertexAttribArray(groundProg->getAttribute("vertNor"));
//         glBindBuffer(GL_ARRAY_BUFFER, groundBuffer);
//         glVertexAttribPointer(groundProg->getAttribute("vertNor"), 3, GL_FLOAT, GL_FALSE, 0, (void*) 0);
//         
//         glDrawArrays(GL_TRIANGLES, 0, 6);
//         
//         glDisableVertexAttribArray(groundProg->getAttribute("vertNor"));
//         glDisableVertexAttribArray(groundProg->getAttribute("vertPos"));
//      V->popMatrix();
//   M->popMatrix();
//   groundProg->unbind();
//}
//
//void drawShapeWithShaderProgram(const shared_ptr<Shape> shape, const shared_ptr<Program> prog) {
//   auto V = make_shared<MatrixStack>();
//   V->pushMatrix();
//      V->lookAt(camera.pos, camera.lookAt, camera.up);
//      glUniformMatrix4fv(prog->getUniform("V"), 1, GL_FALSE, V->topMatrix().data());
//      shape->draw(prog);
//   V->popMatrix();
//}
//
//void drawShape(const shared_ptr<Shape> shape, const shared_ptr<Program> prog, const shared_ptr<MatrixStack> P, const shared_ptr<MatrixStack> M, 
//   float xPos, float yPos, float zPos, int material) {
//   prog->bind();
//   glUniformMatrix4fv(prog->getUniform("P"), 1, GL_FALSE, P->topMatrix().data());
//   glUniform3f(prog->getUniform("lightPos"), light.pos[0] + lightPosOffset, light.pos[1], light.pos[2]);
//   glUniform3f(prog->getUniform("lightColor"), light.color[0], light.color[1], light.color[2]);
//   glUniform3f(prog->getUniform("sunDir"), sun.dir[0], sun.dir[1], sun.dir[2]);
//   glUniform3f(prog->getUniform("sunColor"), sun.color[0], sun.color[1], sun.color[2]);
//   SetMaterial(material, prog);
//
//   // Draw mesh 
//   M->pushMatrix();
//      M->translate(Vector3f(xPos, yPos, zPos));
//      M->rotate(rand(), Vector3f(0, 1, 0));
//
//      glUniformMatrix4fv(prog->getUniform("M"), 1, GL_FALSE, M->topMatrix().data());
//      drawShapeWithShaderProgram(shape, prog);
//   M->popMatrix();
//   prog->unbind();
//}
//
//string createLSystemTreeString(string input, int generations) {
//   /*
//   Variables:
//      0 = draw line segment with leaf
//      1 = draw line segment
//   Constants:
//      [ = push, rotate left DEGREES and scale
//      ] = pop, rotate right DEGREES and scale
//   Axiom: (what to start with)
//      0
//   Rules:
//      0 -> 1[0]0
//   */
//   if (generations == 0) return input;
//   string output = "";
//
//   for (int i = 0; i < input.length(); i++) {
//      char c = input[i];
//      if (c == '0') {
//         output += "1[0]0";
//      } else {
//         output += c;
//      }
//   }
//
//   return createLSystemTreeString(output, generations - 1);
//}
//
//// Use a specific seed to generate a random value while preserving 
//// the current random value pattern
//// int getRandomFromSeed(int *seed) {
////    // Get the next random number in the current random value sequence
////    // (this will cause the current sequence to never actually use this value,
////    //  but that is a small price to pay)
////    int tempSeed = rand();
////    // Seed the random generator to get a value from a different random value sequence
////    srand(*seed);
////    int value = rand();
////    *seed = value;
////    // Reset the random value sequence to the path it was taking
////    srand(tempSeed);
////    // Return the random value
////    return value;
//// }
//
//void renderLSystemTree(string treeString, int randomRotation, const shared_ptr<Program> prog, const shared_ptr<MatrixStack> P, const shared_ptr<MatrixStack> M,
//   float xPos, float yPos, float zPos, int material) {
//   prog->bind();
//   glUniformMatrix4fv(prog->getUniform("P"), 1, GL_FALSE, P->topMatrix().data());
//   glUniform3f(prog->getUniform("lightPos"), light.pos[0] + lightPosOffset, light.pos[1], light.pos[2]);
//   glUniform3f(prog->getUniform("lightColor"), light.color[0], light.color[1], light.color[2]);
//   glUniform3f(prog->getUniform("sunDir"), sun.dir[0], sun.dir[1], sun.dir[2]);
//   glUniform3f(prog->getUniform("sunColor"), sun.color[0], sun.color[1], sun.color[2]);
//   float scale = 2.0/3;
//   float newScale = 1.0;
//   float sizeX = 0.4;
//   float sizeY = 1.0;
//   // float sizeZ = 0.4;
//   int leafColor = rand() % 8;
//
//   M->pushMatrix();
//      M->translate(Vector3f(xPos, yPos, zPos));
//      M->rotate(randomRotation, Vector3f(0, 1, 0));
//   for (int i = 0; i < treeString.length(); i++) {
//      char c = treeString[i];
//      switch (c) {
//         case '0':
//            M->translate(Vector3f(0.0, (sizeY*newScale)/2, 0.0));
//            // Draw leaf
//            M->pushMatrix();
//               SetMaterial(leafColor, prog);
//               M->translate(Vector3f(0.0, (sizeY*newScale)/2, 0.0));
//               M->scale(Vector3f(0.4*newScale, 0.4*newScale, 0.4*newScale));
//               glUniformMatrix4fv(prog->getUniform("M"), 1, GL_FALSE, M->topMatrix().data());
//               drawShapeWithShaderProgram(sphere, prog);
//            M->popMatrix();
//            // Draw branch
//            M->pushMatrix();
//               SetMaterial(material, prog);
//               M->scale(Vector3f(0.2*newScale, 0.5*newScale, 0.2*newScale));
//               glUniformMatrix4fv(prog->getUniform("M"), 1, GL_FALSE, M->topMatrix().data());
//               drawShapeWithShaderProgram(cube, prog);
//            M->popMatrix();
//            break;
//         case '1':
//            M->translate(Vector3f(0.0, (sizeY*newScale)/2, 0.0));
//            // Draw trunk
//            M->pushMatrix();
//               SetMaterial(material, prog);
//               M->scale(Vector3f(0.2*newScale, 0.5*newScale, 0.2*newScale));
//               glUniformMatrix4fv(prog->getUniform("M"), 1, GL_FALSE, M->topMatrix().data());
//               drawShapeWithShaderProgram(cube, prog);
//            M->popMatrix();
//            break;
//         case '[':
//            newScale *= scale;
//            M->translate(Vector3f(0.0, (sizeY*newScale/scale)/2, 0.0));
//            M->pushMatrix();
//            M->translate(Vector3f(-1.0/6*(sizeX*newScale/scale), -1.0/6*(sizeX*newScale/scale), 0));
//            M->rotate(rand() % 40 + 5, Vector3f(0.0, 0.0, 1.0));
//            // M->scale(Vector3f(0.8, 0.8, 0.8));
//            break;
//         case ']':
//            // For each time that ']' is followed by "1[", decrease the scale
//            for (int increment = 1; i+increment < treeString.length(); increment+=2) {
//               if (treeString[i+increment] == '1') {
//                  newScale /= scale;
//               } else {
//                  break;
//               }
//            }
//            M->popMatrix();
//            M->translate(Vector3f(1.0/6*(sizeX*newScale/scale), -1.0/6*(sizeX*newScale/scale), 0));
//            M->rotate(-(rand() % 40) - 5, Vector3f(0.0, 0.0, 1.0));
//            // M->scale(Vector3f(0.8, 0.8, 0.8));
//            break;
//      }
//   }
//   M->popMatrix();
//   prog->unbind();
//}
//
//static void render() {
//	// Get current frame buffer size.
//	int width, height;
//	glfwGetFramebufferSize(window, &width, &height);
//	glViewport(0, 0, width, height);
//
//	// Clear framebuffer.
//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//
//	//Use the matrix stack for Lab 6
//   float aspect = width/(float)height;
//
//   // Create the matrix stacks - please leave these alone for now
//   auto P = make_shared<MatrixStack>();
//   auto M = make_shared<MatrixStack>();
//
//   // Begin matrix transforms
//   P->pushMatrix();
//   // Apply perspective projection.
//   P->perspective(45.0f, aspect, 0.01f, 100.0f);
//
//   // Draw the ground
//   drawGround(P, M);
//   
//   // Copy tree random seeds so we generate the same trees
//   int tempTreeGenRand = treeGenRand;
//   int tempTreePosRand = treePosRand;
//   // Draw 10 random trees
//   for (int i = 0; i < NUM_MODELS; i++) {
//      // Generate the random tree positions;
//      srand(tempTreePosRand);
//      float posX = rand() / (float)RAND_MAX * 15 - 7.5;
//      float posZ = rand() / (float)RAND_MAX * 15 - 7.5;
//      float randomRotation = rand();
//      tempTreePosRand = rand(); // Store the random seed for later use
//      // Generate the random trees
//      srand(tempTreeGenRand);
//      renderLSystemTree(createLSystemTreeString("0", 5), randomRotation, phongProg, P, M, posX, -1, posZ, 4);
//      tempTreeGenRand = rand(); // Store the random seed for later use
//   }
//   // Draw 10 random robots
//   for (int i = 0; i < NUM_MODELS; i++) {
//      float posX = rand() / (float)RAND_MAX * 15 - 7.5;
//      float posZ = rand() / (float)RAND_MAX * 15 - 7.5;
//      float material = rand() % 8;
//      drawShape(robot, phongProg, P, M, posX, -0.3, posZ, material);
//   }
//   
//   P->popMatrix();
//   t += 0.01;
//   sun.dir[0] = cos(t);
//   sun.dir[1] = sin(t);
//   sun.dir[2] = cos(t);
//}
//
//static void updateCamera() {
//   Vector3f gaze = camera.lookAt - camera.pos;
//   Vector3f w = -gaze.normalized();
//   Vector3f u = camera.up.cross(w).normalized();
//   if (abs(camera.velW) > CAMERA_STOPPED_THRESHOLD) {
//      camera.pos += camera.velW * w;
//      camera.lookAt += camera.velW * w;
//   }
//   if (abs(camera.velU) > CAMERA_STOPPED_THRESHOLD) {
//      camera.pos += camera.velU * u;
//      camera.lookAt += camera.velU * u;
//   }
//}
//
//void initValues() {
//   // Initialize light sources
//   light.pos = Vector3f(0, 0, 0);
//   light.color = Vector3f(1, 1, 1);
//   sun.dir = Vector3f(5, 5, 5).normalized();
//   sun.color = Vector3f(253/255.0, 184/255.0, 19/255.0);
//
//   // Initialize camera
//   camera.pos = Vector3f(0, 0, 0);
//   camera.lookAt = Vector3f(0, 0, -1);
//   camera.up = Vector3f(0, 1, 0);
//}
//
//int main2(int argc, char **argv)
//{
//	if (argc < 2) {
//      cout << "Using ../resources/ as the default resources directory." << endl;
//      cout << "Please specify an argument if you wish to change the resources directory." << endl;
//   } else {
//      RESOURCE_DIR = argv[1] + string("/");
//   }
//
//   // Initialize things
//   initValues();
//
//	// Set error callback.
//	glfwSetErrorCallback(error_callback);
//	// Initialize the library.
//	if(!glfwInit()) {
//		return -1;
//	}
//   //request the highest possible version of OGL - important for mac
//   glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
//   glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
//   glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//   glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
//
//	// Create a windowed mode window and its OpenGL context.
//	window = glfwCreateWindow(640, 480, "Tyler's Awesome Window", NULL, NULL);
//	if(!window) {
//		glfwTerminate();
//		return -1;
//	}
//	// Make the window's context current.
//	glfwMakeContextCurrent(window);
//	// Initialize GLEW.
//	glewExperimental = true;
//	if(glewInit() != GLEW_OK) {
//		cerr << "Failed to initialize GLEW" << endl;
//		return -1;
//	}
//	//weird bootstrap of glGetError
//   glGetError();
//	cout << "OpenGL version: " << glGetString(GL_VERSION) << endl;
//   cout << "GLSL version: " << glGetString(GL_SHADING_LANGUAGE_VERSION) << endl;
//
//   // Disable cursor (allows unlimited scrolling)
//   glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
//
//	// Set vsync.
//	glfwSwapInterval(1);
//	// Set keyboard callback.
//	glfwSetKeyCallback(window, key_callback);
//   //set the mouse call back
//   // glfwSetMouseButtonCallback(window, mouse_callback);
//   // Set the mouse move call back
//   glfwSetCursorPosCallback(window, mouse_move_callback);
//   //set the window resize call back
//   glfwSetFramebufferSizeCallback(window, resize_callback);
//
//	// Initialize scene. Note geometry initialized in init now
//	init();
//   initGeom();
//
//	// Loop until the user closes the window.
//	while(!glfwWindowShouldClose(window)) {
//		// Render scene.
//		render();
//      // Update camera;
//      updateCamera();
//		// Swap front and back buffers.
//		glfwSwapBuffers(window);
//		// Poll for and process events.
//		glfwPollEvents();
//	}
//	// Quit program.
//	glfwDestroyWindow(window);
//	glfwTerminate();
//	return 0;
//}
