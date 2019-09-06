#ifndef ANIMATORCOMPONENT_H
#define ANIMATORCOMPONENT_H

#include "Component.h"
#include <SDL.h>
#include <string>
#include <map>
#include <vector>
#include <utility>

struct AnimatorComponent : public Component
{
	AnimatorComponent(std::string startState = "") : state{ startState } { }

	std::map<std::string, std::pair <SDL_Surface*, int>> animations;
	std::string state;
};
#endif