//
//  TransformComponent.h
//  SimpleGame
//
//  Created by Tyler Dahl on 1/19/17.
//
//

#ifndef TransformComponent_h
#define TransformComponent_h

#include "../MatrixStack.h"

class TransformComponent {
public:
    vec3 rotate;
    vec3 scale;
    
    const mat4 &getMatrix(vec3 position) {
        auto M = make_shared<MatrixStack>();
        M->translate(position);
        M->rotate(rotate.x, vec3(1, 0, 0));
        M->rotate(rotate.y, vec3(0, 1, 0));
        M->rotate(rotate.z, vec3(0, 0, 1));
        M->scale(scale);
        return M->topMatrix();
    }
};

#endif /* TransformComponent_h */
