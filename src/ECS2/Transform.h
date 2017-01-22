//
//  Transform.h
//  SimpleGame
//
//  Created by Tyler Dahl on 1/22/17.
//
//

#ifndef Transform_h
#define Transform_h

#include "glm/glm.hpp"

#include "Component.h"

class Transform : public Component {
public:
    Transform() { name = "Transform"; };
    virtual ~Transform() {};
    
    glm::vec3 position = glm::vec3(0, 0, 0);
    glm::vec3 rotation = glm::vec3(0, 0, 0);
    glm::vec3 scale = glm::vec3(1, 1, 1);
};


#endif /* Transform_h */
