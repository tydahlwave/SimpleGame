//
//  Entity.h
//  SimpleGame
//
//  Created by Tyler Dahl on 1/18/17.
//
//

#ifndef Entity_h
#define Entity_h

class Entity {
public:
    Entity(int id) :_id(id) {}
    virtual ~Entity() {}
private:
    int _id;
};

#endif /* Entity_h */
