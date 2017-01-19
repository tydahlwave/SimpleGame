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
#include "../Window.h"

using namespace std;

class RenderSystem {
public:
    RenderSystem() {}
    virtual ~RenderSystem() {}
    
    void loadShape(string filename);
    void render(Window &window, const shared_ptr<Program> prog);
private:
    map<string, shared_ptr<Shape>> shapes;
};

#endif /* RenderSystem_h */
