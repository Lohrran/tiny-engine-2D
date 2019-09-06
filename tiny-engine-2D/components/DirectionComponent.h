#ifndef DIRECTIONCOMPONENT_H
#define DIRECTIONCOMPONENT_H

#include "Component.h"

enum class Direction
{
	UP,
	DOWN,
	RIGHT,
	LEFT,
	NONE
};

struct DirectionComponent : public Component
{
	DirectionComponent()  { }

	Direction direction;
};

#endif