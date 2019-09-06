#ifndef ANIMATIONCLIP_H
#define ANIMATIONCLIP_H

#include <string>

struct AnimationClip
{
	AnimationClip(std::string path = "", int width = 0, int height = 0, int speed = 0, bool loop = true) : 
		path{ path }, width{ width }, height{ height }, speed{ speed }, loop{ loop } { }

	std::string path;
	int width, height, speed;
	bool loop;
	bool looped = false;
};
#endif