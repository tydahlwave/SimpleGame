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

using namespace std;

class RenderSystem {
public:
    RenderSystem() {}
    virtual ~RenderSystem() {}
    
    void loadShape(string filename);
    void render(ShaderSystem &shaderSystem, Window &window);
private:
    void drawShape(int entity, Window &window, const shared_ptr<Shape> shape, const shared_ptr<Program> shader);
    
    map<string, shared_ptr<Shape>> shapes;
};

#endif /* RenderSystem_h */
