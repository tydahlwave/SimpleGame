//
//  Mesh.h
//  SimpleGame
//
//  Created by Tyler Dahl on 1/22/17.
//
//

#ifndef Mesh_h
#define Mesh_h

#include "Object.h"
#include "Bounds.h"

class Mesh : public Object {
public:
    Mesh() {};
    virtual ~Mesh() {};
    
    Bounds *bounds;
};

#endif /* Mesh_h */
