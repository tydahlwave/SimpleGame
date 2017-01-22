//
//  MeshRenderer.h
//  SimpleGame
//
//  Created by Tyler Dahl on 1/22/17.
//
//

#ifndef MeshRenderer_h
#define MeshRenderer_h

#include "Component.h"
#include "Mesh.h"
#include "Shader.h"

class MeshRenderer : public Component {
public:
    MeshRenderer() { name = "MeshRenderer"; };
    virtual ~MeshRenderer() {};
    
    Mesh *mesh;
    Shader *shader;
};

#endif /* MeshRenderer_h */
