#ifndef ANIMATORSYSTEM_H
#define ANIMATORSYSTEM_H

//SDL2 Library
#include <SDL.h>

//System
#include "Requeriment.h"

//Components
#include "AnimationComponent.h"
#include "AnimatorComponent.h"
#include "PositionComponent.h"

//Events
#include "StateEvent.h"

//Camera
#include "Camera.h"

class AnimationSystem : public Requeriment <AnimationComponent, AnimatorComponent, PositionComponent>
{
	public:
		void init(GameObject* obj) override;
		void update(GameObject* obj) override;
		void free(GameObject* obj) override;

		void onAnimatorState(StateEvent* evt);
	
	private:
		std::shared_ptr<Camera> camera = Camera::get();

		static SDL_Surface* load(const char* path);
};
#endif
