#pragma once
#ifndef _GRAPHICS_COMPONENT_H_
#define _GRAPHICS_COMPONENT_H_

class GraphicsComponent :: Component {
public:
   virtual void update(GameObject &obj, Graphics &graphics);
};

// class GraphicsComponent :: Component {
// public:
//   virtual ~GraphicsComponent() {}
//   virtual void update(GameObject& obj, Graphics& graphics) = 0;
// };

#endif
