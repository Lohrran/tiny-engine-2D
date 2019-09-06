#ifndef BOXCOLLIDERCOMPONENT_H
#define BOXCOLLIDERCOMPONENT_H

#include <SDL.h>
#include "Component.h"

struct BoxColliderComponent : public Component
{
	BoxColliderComponent(int width = 0, int height = 0) : width{ width }, height{ height } { }

	int width, height;
};
#endif