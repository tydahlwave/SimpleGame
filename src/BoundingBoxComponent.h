#ifndef BoundingBoxComponent_h
#define BoundingBoxComponent_h

#include "glm/glm.hpp"

using namespace glm;

class BoundingBoxComponent {

public:
	vec3 mins;
	vec3 maxes;
};

#endif /* BoundingBoxComponent_h */

