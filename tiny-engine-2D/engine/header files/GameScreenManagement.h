#ifndef GAMESCREENMANAGEMENT_H
#define GAMESCREENMANAGEMENT_H

#include <string>
#include <memory>

class GameScreenManagement
{
	public:
		GameScreenManagement();

		GameScreenManagement(const GameScreenManagement&) = delete;
		GameScreenManagement& operator = (const GameScreenManagement&) = delete;

		static std::shared_ptr<GameScreenManagement> get();

		void loadScene(std::string name);

		std::string getCurrentScene();

	private:
		static std::shared_ptr<GameScreenManagement> instance;

		std::string currentScene;
};
#endif