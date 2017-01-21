//
//  EntityFactory.cpp
//  SimpleGame
//
//  Created by Tyler Dahl on 1/18/17.
//
//

#include <stdio.h>

#include "EntityFactory.h"

int EntityFactory::createPlayer(World &world) {
    int player = world.createEntity();
	if (player > -1) {
		world.entity[player] = (COMP_POSITION | COMP_VELOCITY | COMP_TRANSFORM | COMP_ENTITY_TYPE | COMP_SHADER_TYPE);

		world.position[player].value = vec3(0, 0, 0);
		world.velocity[player].value = vec3(0, 0, 0);
                world.transform[player].rotate = vec3(0, 0, 0);
                world.transform[player].scale = vec3(1, 1, 1);
		world.entityType[player].type = "bunny";
		world.shaderType[player].type = "phong";

		return player;
	}
}

int EntityFactory::createSheep(World &world) {
    int sheep = world.createEntity();
	if (sheep > -1) {

		world.entity[sheep] = (COMP_POSITION | COMP_VELOCITY | COMP_ACCELERATION | COMP_TRANSFORM | COMP_ENTITY_TYPE | COMP_SHADER_TYPE);

		world.position[sheep].value = vec3(0, 0, 0);
		world.velocity[sheep].value = vec3(0, 0, 0);
                world.acceleration[sheep].value = vec3(0, 0, 0);
                world.transform[sheep].rotate = vec3(0, 0, 0);
                world.transform[sheep].scale = vec3(1, 1, 1);
		world.entityType[sheep].type = "bunny";
		world.shaderType[sheep].type = "phong";

		return sheep;
	}
}

int EntityFactory::createGround(World &world) {
    int ground = world.createEntity();
	if (ground > -1) {

		world.entity[ground] = (COMP_POSITION | COMP_TRANSFORM | COMP_ENTITY_TYPE | COMP_SHADER_TYPE);

		world.position[ground].value = vec3(0, -1, 0);
                world.transform[ground].rotate = vec3(0, 0, 0);
                world.transform[ground].scale = vec3(50, 1, 50);
		world.entityType[ground].type = "rect";
		world.shaderType[ground].type = "ground";

	}
}
