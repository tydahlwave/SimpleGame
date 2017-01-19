//
//  EntityTypeComponent.h
//  SimpleGame
//
//  Created by Tyler Dahl on 1/18/17.
//
//

#ifndef EntityTypeComponent_h
#define EntityTypeComponent_h

enum EntityType {
    Player,
    Sheep,
    Tree,
    Wolf
};

class EntityTypeComponent {
public:
    EntityType type;
};

#endif /* EntityTypeComponent_h */
