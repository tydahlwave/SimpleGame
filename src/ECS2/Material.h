//
//  Material.h
//  SimpleGame
//
//  Created by Tyler Dahl on 1/22/17.
//
//

#ifndef Material_h
#define Material_h

#include "Color.h"
#include "Texture.h"

class Material : public Object {
public:
    Color *color;
    Texture *texture;
    
    static Material *plastic; // TODO: remember to set name
    static Material *aluminum;
    static Material *goldCeramic;
};

#endif /* Material_h */
