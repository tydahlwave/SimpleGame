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
#include "Material.h"
#include "Shader.h"

class MeshRenderer : public Component {
public:
    MeshRenderer() { name = "MeshRenderer"; };
    MeshRenderer(Mesh *m, Material *mat, Shader *s) :MeshRenderer() { mesh = m; material = mat; shader = s; }
    virtual ~MeshRenderer() {};
    
    Mesh *mesh = nullptr;
    Material *material = nullptr;
    Shader *shader = nullptr;
};

#endif /* MeshRenderer_h */
