#pragma once
#ifndef _GROUND_GRAPHICS_COMPONENT_H_
#define _GROUND_GRAPHICS_COMPONENT_H_

#include "GameObject.h"
#include "GraphicsComponent.h"

class GroundGraphicsComponent :: GraphicsComponent {
public:
   GroundGraphicsComponent();
   virtual ~GroundGraphicsComponent() {}

   void update(GameObject &obj, Graphics &graphics);
};

#endif













#include "GroundGraphicsComponent.h"

GroundGraphicsComponent::GroundGraphicsComponent() {

}

void GroundGraphicsComponent::update(GameObject &obj, Graphics &graphics) {
   Graphics.drawSquare(obj.pos, obj.size);
}
