#include "TinyEngine2D.h"

TinyEngine2D::TinyEngine2D(std::string title, int width, int height) : screen{title, width, height} 
{
	quit = false;
	currentScene = "";
	previousScene = "";

	now = SDL_GetPerformanceCounter();
	last = 0;
	deltaTime = 0;

	screen.create();
}

TinyEngine2D::~TinyEngine2D()
{
	while (!gameScenes.empty())
	{
		std::string gameSceneName = gameScenes.begin()->first;
		GameScene* ptr = gameScenes.find(gameSceneName)->second;

		gameScenes.erase(gameSceneName);

		delete ptr;
	}
}

void TinyEngine2D::addGameScene(std::string name, GameScene* gameScene)
{
	if (gameScenes[name] == nullptr)
	{
		gameScenes[name] = gameScene;
	}
}

void TinyEngine2D::setFirstGameScene(std::string name)
{
	gameScreenManagement->loadScene(name);
}

void TinyEngine2D::play()
{
	while (!quit)
	{
		verifyCurrentScene();

		quit = gameScenes[currentScene]->loop();
		
		screen.update();

		//Calculate DeltaTime
		last = now;
		now = SDL_GetPerformanceCounter();

		deltaTime = ((now - last) * 1000 / (double)SDL_GetPerformanceFrequency());
		time->setDeltaTime(deltaTime);
	}

	gameScenes[currentScene]->Free();
	
	screen.close();
}

void TinyEngine2D::verifyCurrentScene()
{
	if (currentScene != gameScreenManagement->getCurrentScene())
	{
		previousScene = currentScene;
		currentScene = gameScreenManagement->getCurrentScene();

		if (previousScene != "")
		{
			gameScenes[previousScene]->Free();
		}

		gameScenes[currentScene]->Initialize();
		gameScenes[currentScene]->Start();
	}
}