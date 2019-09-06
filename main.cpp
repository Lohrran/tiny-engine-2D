//Inverse Double NES Resolution
#define SCREEN_WIDTH 480
#define SCREEN_HEIGHT 512

// ENGINE
#include "TinyEngine2D.h"

// GAME SCENES
#include "GameplayScene.h"
#include "MenuScene.h"

#include <iostream>

int main(int argc, char *argv[])
{
	// Initialize the screen with a proper name, width and height
	TinyEngine2D engine{ "Tic-Tac-Toe", SCREEN_WIDTH, SCREEN_HEIGHT };

	engine.addGameScene("GameplayScene", new GameplayScene{ });
	engine.addGameScene("MenuScene", new MenuScene{ });

	// Set first scene where the game will start
	engine.setFirstGameScene("MenuScene");

	// Run the game
	engine.play();


	std::cout << "\n\n\n";
	system("pause");
	return 0;
}