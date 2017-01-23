//
//  Renderer.h
//  SimpleGame
//
//  Created by Tyler Dahl on 1/22/17.
//
//

#ifndef Renderer_h
#define Renderer_h

#include "World.h"

class Renderer {
public:
    Renderer();
    virtual ~Renderer() {};
    
    void Initialize();
    void Render(World &world);
};

#endif /* Renderer_h */
