#include "GameScreenManagement.h"

std::shared_ptr<GameScreenManagement> GameScreenManagement::instance = nullptr;

GameScreenManagement::GameScreenManagement() { }

std::shared_ptr<GameScreenManagement> GameScreenManagement::get()
{
	if (instance == nullptr)
	{
		instance = std::make_shared<GameScreenManagement>();
	}
	return instance;
}

void GameScreenManagement::loadScene(std::string name)
{
	currentScene = name;
}

std::string GameScreenManagement::getCurrentScene()
{
	return currentScene;
}