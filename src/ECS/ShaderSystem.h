//
//  ShaderSystem.h
//  SimpleGame
//
//  Created by Tyler Dahl on 1/19/17.
//
//

#ifndef ShaderSystem_h
#define ShaderSystem_h

#include <map>
#include <string>
#include <memory>

#include "../Program.h"

using namespace std;

class ShaderSystem {
public:
    ShaderSystem() {}
    virtual ~ShaderSystem() {}
    
    void loadPhong();
    void loadGround();
    shared_ptr<Program> getShaderByName(string name) { return shaders[name]; }
private:
    map<string, shared_ptr<Program>> shaders;
};

#endif /* ShaderSystem_h */
