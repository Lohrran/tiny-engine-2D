#ifndef POSITIONCOMPONENT_H
#define POSITIONCOMPONENT_H

#include "Component.h"

struct PositionComponent : public Component
{
	PositionComponent(int x = 0, int y = 0) : x{ x }, y{ y } { }

	int x, y;
};
#endif