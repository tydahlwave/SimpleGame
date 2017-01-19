//
//  ShaderTypeComponent.h
//  SimpleGame
//
//  Created by Tyler Dahl on 1/19/17.
//
//

#ifndef ShaderTypeComponent_h
#define ShaderTypeComponent_h

enum ShaderType {
    Player,
    Sheep,
    Tree,
    Wolf
};

class ShaderTypeComponent {
public:
    ShaderType type;
};

#endif /* ShaderTypeComponent_h */
