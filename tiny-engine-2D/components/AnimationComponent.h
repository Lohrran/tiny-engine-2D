#ifndef ANIMATIONCOMPONENT_H
#define ANIMATIONCOMPONENT_H

#include "Component.h"
#include "AnimationClip.h"
#include <map>

struct AnimationComponent : public Component
{
	AnimationComponent(){ }

	void add(std::string name, AnimationClip* clip) { clips.insert(std::make_pair(name, clip)); } //Helper

	std::map<std::string, AnimationClip*> clips;
};
#endif