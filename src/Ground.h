#pragma once
#ifndef _GROUND_H_
#define _GROUND_H_

class Ground :: GameObject {
public:
   Ground();
   virtual ~Ground() {}

   void update(World& world, Graphics& graphics);
private:
};

#endif
