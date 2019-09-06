#include "GameScene.h"

bool GameScene::loop()
{
	while (SDL_PollEvent(&*requestEvent->getSDLEvent()) != 0) //Inputs Go Inside the Event Loop
	{
		if (requestEvent->getSDLEvent()->type == SDL_QUIT) 	//User requests quit
		{
			return true;
		}
		Input();
	}

	Update();

	return false;
}