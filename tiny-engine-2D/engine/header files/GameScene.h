#ifndef GAMESCENE_H
#define GAMESCENE_H

//SDL Lib
#include <SDL.h>

//Engine
#include "RequestEvent.h"

class GameScene
{
	public: 
		bool loop();
	
		virtual void Initialize() = 0;
		virtual void Start() = 0;
		virtual void Input() = 0;
		virtual void Update() = 0;
		virtual void Free() = 0;
	
	private:
		std::shared_ptr<RequestEvent> requestEvent = RequestEvent::get();
};
#endif