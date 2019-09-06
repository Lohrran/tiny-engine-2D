#ifndef VELOCITYCOMPONENT_H
#define VELOCITYCOMPONENT_H

#include "Component.h"

struct VelocityComponent : public Component
{
	VelocityComponent(int x = 0, int y = 0) : x{ x }, y{ y } { }

	int x, y;
};
#endif