//
//  Bounds.h
//  SimpleGame
//
//  Created by Tyler Dahl on 1/23/17.
//
//

#ifndef Bounds_h
#define Bounds_h

#include "glm/glm.hpp"

class Bounds {
public:
    Bounds() {};
    Bounds(glm::vec3 _min, glm::vec3 _max) {
        min = _min;
        max = _max;
        size = max - min;
        center = (_min + _max) / glm::vec3(2, 2, 2);
    };
    Bounds(glm::vec3 c, glm::vec3 _min, glm::vec3 _max, glm::vec3 s) {
        center = c;
        min = _min;
        max = _max;
        size = s;
    }
    virtual ~Bounds() {};

    glm::vec3 center = glm::vec3(0, 0, 0);
    glm::vec3 min = glm::vec3(0, 0, 0);
    glm::vec3 max = glm::vec3(0, 0, 0);
    glm::vec3 size = glm::vec3(0, 0, 0);
};

#endif /* Bounds_h */
