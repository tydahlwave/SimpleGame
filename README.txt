Program 4 by Tyler Dahl

All features are fully functional.

To Run The Program:
1. Create a build directory.
2. Inside the build directory, run "cmake .." and then run "make"
3. Start the program by typing "./program4"
   (no need to specify resources directory as it uses a default value of "../resources/",
    but if you want to, you can run "./program4 ../resources" to specify a resource directory.)

Functionality:
- 'a' moves the camera left relative to its own axis
- 'd' moves the camera right relative to its own axis
- 'w' moves the camera forward relative to its own axis
- 's' moves the camera backward relative to its own axis
- SPACE re-generates the trees and the robots with new random positions (the trees stay stationary, but change their branch pattern)
- moving the mouse will rotate the view

In terms of lighting, there is a fast day/night cycle to showcase different lighting conditions of the world.
There is also a spot light centered on the camera, which illuminates models as you get near them.

For materials, I added Ruby, Emerald, Polished Gold, and Bronze, which you can see on the robots and the leaves of the trees.
Other materials include Shiny Blue Plastic, Pearl, Brass, and Copper.
If not all materials are present in a map, press SPACE until a model contains the material you are looking for.

Enjoy!
