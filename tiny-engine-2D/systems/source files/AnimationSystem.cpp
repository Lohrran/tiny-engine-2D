#include "AnimationSystem.h"

void AnimationSystem::init(GameObject* obj)
{	
	eventChannel->subscribe(this, &AnimationSystem::onAnimatorState);

	for (auto clip : obj->getComponent<AnimationComponent>()->clips) //Load Animations From AnimationComponent to AnimatorComponent
	{
		SDL_Surface* animation = load(clip.second->path.c_str());
		int frames = (animation->w / clip.second->width) + (animation->h / clip.second->height) - 1;
		obj->getComponent<AnimatorComponent>()->animations[clip.first] = std::make_pair(animation, frames);
	}
}

void AnimationSystem::update(GameObject* obj)
{		
	std::string state = obj->getComponent<AnimatorComponent>()->state;

	if (obj->getComponent<AnimatorComponent>()->animations.find(state) != obj->getComponent<AnimatorComponent>()->animations.cend())
	{
		int speed = obj->getComponent<AnimationComponent>()->clips[state]->speed;
		int width = obj->getComponent<AnimationComponent>()->clips[state]->width;
		int height = obj->getComponent<AnimationComponent>()->clips[state]->height;

		int frames = obj->getComponent<AnimatorComponent>()->animations[state].second;//Number of Frames
		
		Uint32 ticks = SDL_GetTicks();
		Uint32 sprite = (ticks / speed) % frames;
		
		SDL_Rect srcrect = { sprite * width, 0, width, height }; //Animating;

		if (!obj->getComponent<AnimationComponent>()->clips[state]->loop) //Loop Once
		{
			if (obj->getComponent<AnimationComponent>()->clips[state]->looped)
			{
				srcrect = { frames, 0, width, height };	//Last Frame
			}
			obj->getComponent<AnimationComponent>()->clips[state]->looped = true;
		}

		SDL_Rect dstrect =
		{
			obj->getComponent<PositionComponent>()->x,
			obj->getComponent<PositionComponent>()->y,
			width,
			height
		};

		SDL_BlitSurface
		(
			obj->getComponent<AnimatorComponent>()->animations[state].first,	//Loaded Sprite
			&srcrect,															//Display the Current Frame Rect
			camera->surface(),
			&dstrect															//Display the Current Frame Rect with Position Updated
		);
	}
}

void AnimationSystem::free(GameObject* obj) 
{
	for (auto anim : obj->getComponent<AnimatorComponent>()->animations)
	{
		SDL_FreeSurface(anim.second.first);
	}
}

SDL_Surface* AnimationSystem::load(const char* path)
{
	SDL_Surface* imageLoaded = NULL;
	SDL_Surface* processedImage = NULL;

	imageLoaded = SDL_LoadBMP(path);

	if (imageLoaded != NULL)
	{
		processedImage = SDL_ConvertSurface(imageLoaded, imageLoaded->format, 0);
		SDL_FreeSurface(imageLoaded);

		if (processedImage != NULL)
		{
			Uint32 colorKey = SDL_MapRGB(processedImage->format, 255, 0, 225);//Not Passing transparency to all BMP
			SDL_SetColorKey(processedImage, SDL_TRUE, colorKey);
		}
	}
	return processedImage;
}

void AnimationSystem::onAnimatorState(StateEvent* evt)
{
	evt->obj->getComponent<AnimatorComponent>()->state = evt->state;
}