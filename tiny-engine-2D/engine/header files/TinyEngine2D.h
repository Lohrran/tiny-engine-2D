#ifndef TINYENGINE2D_H
#define TINYENGINE2D_H

#include <string>
#include <memory>
#include <map>

#include "GameScreenManagement.h"
#include "GameScene.h"
#include "Screen.h"
#include "Time.h"

class TinyEngine2D
{
	public:
		TinyEngine2D(std::string tittle, int width, int height);
		
		TinyEngine2D(const TinyEngine2D&) = default;
		TinyEngine2D& operator = (const TinyEngine2D&) = delete;
		TinyEngine2D& operator = (TinyEngine2D&&) = delete;
		
		~TinyEngine2D();

		void addGameScene(std::string name, GameScene* gameScene);
		
		void setFirstGameScene(std::string name);
		void play();

	private:
		void verifyCurrentScene();

		//Screen
		std::shared_ptr<GameScreenManagement> gameScreenManagement = GameScreenManagement::get();

		std::map<std::string, GameScene*> gameScenes;
		std::string currentScene, previousScene;
		Screen screen;

		//Request to quit Game
		bool quit;

		// Delta Time
		std::shared_ptr<Time> time = Time::get();

		Uint64 now, last;
		double deltaTime;
};
#endif