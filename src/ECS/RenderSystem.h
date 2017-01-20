//
//  RenderSystem.h
//  SimpleGame
//
//  Created by Tyler Dahl on 1/19/17.
//
//

#ifndef RenderSystem_h
#define RenderSystem_h

#include <map>
#include <memory>
#include <string>
#include <vector>

#include "Entity.h"
#include "../Shape.h"
#include "../Program.h"
#include "../Window.h"
#include "ShaderSystem.h"
#include "World.h"
#include "glm/glm.hpp"

using namespace std;
using namespace glm;

class RenderSystem {
public:
    RenderSystem() {}
    virtual ~RenderSystem() {}
    
    void loadShape(string filename);
    void render(World &world, ShaderSystem &shaderSystem, Window &window);
private:
    void drawShape(World &world, int entity, Window &window, const shared_ptr<Shape> shape, const shared_ptr<Program> shader);
    
    map<string, shared_ptr<Shape>> shapes;
};

#endif /* RenderSystem_h */
