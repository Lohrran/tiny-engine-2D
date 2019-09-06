#ifndef TAGCOMPONENT_H
#define TAGCOMPONENT_H

#include "Component.h"
#include <string>


struct TagComponent : public Component
{
	TagComponent(std::string name = "") : name{ name } { }

	std::string name;
};

#endif