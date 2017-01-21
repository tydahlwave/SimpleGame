#ifndef BoundingBoxComponent_h
#define BoundingBoxComponent_h

#include "glm/glm.hpp"

using namespace glm;

class BoundingBoxComponent {
public:
    BoundingBoxComponent() {};
    virtual ~BoundingBoxComponent() {};
    
	vec3 min = vec3(0, 0, 0);
	vec3 max = vec3(0, 0, 0);
};

#endif /* BoundingBoxComponent_h */

