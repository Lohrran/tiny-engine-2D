#ifndef NAMECOMPONENT_H
#define NAMECOMPONENT_H

#include "Component.h"
#include <string>

struct NameComponent : public Component
{
	NameComponent(std::string name = "") : name{ name } { }

	std::string name;
};

#endif