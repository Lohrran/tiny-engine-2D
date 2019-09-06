# Tiny-Engine-2D
> Tiny Engine 2D is made with an Entity Component System architecture and use SDL2 Library

## Why?
After I implement the **[Entity Component System](https://github.com/Lohrran/Entity-Component-System)** I want to prove the concept in a real game example, so between implemantation I ended up creating a little tiny cheap 2D engine 😅.

## Introduction
The framework was based on my implementation of the Entity Component System and SDL 2 library.

## How to

Import the files for your project, download and set up SDL2 library into to IDE and enjoy!


###### Create GameScene

.h File:

```c++

#ifndef GAMEPLAYSCENE_H
#define GAMEPLAYSCENE_H

//Engine
#include "GameScene.h"

//ECS
#include "Scene.h"
#include "Resources.h"

//Add any component or system that you need
#include "SpriteComponent.h"
#include "PositionComponent.h"
#include "TagComponent.h"
#include "MouseComponent.h"
#include "NameComponent.h"

#include "SpriteSystem.h"
#include "MouseSystem.h"

class GameplayScene : public GameScene
{
    public:
        void Initialize() override;
	void Start() override;
	void Input() override;
	void Update() override;
	void Free() override;

    private:
        Scene scene;
	Resources resources{ &scene };
};
#endif

```

.cpp File:

```c++

#include "GameplayScene.h"

GameplayScene::GameplayScene() : resources{ &scene } { }

void GameplayScene::Initialize()
{
    // --- CREATE GAMEOBJECTS --- //
    GameObject* board = scene.createGameObject();
    board->addComponent<TagComponent>("Board");
    board->addComponent<SpriteComponent>("C:\\Users\\user\\Desktop\\img\\board.bmp", 480, 512);
    board->addComponent<PositionComponent>(0, 0);
    
    // --- INITIALIZE SYSTEMS --- //
    resources.add<SpriteSystem>();
    resources.add<MouseSystem>();
    resources.configure();
}

void GameplayScene::Start()
{
    resources.init<SpriteSystem>();
    resources.init<MouseSystem>();
}

void GameplayScene::Input()
{
    resources.update<MouseSystem>();
}

void GameplayScene::Update()
{
    resources.update<SpriteSystem>();
}

void GameplayScene::Free()
{
    resources.free<SpriteSystem>();
}

```

###### Run Game
```c++

#define SCREEN_WIDTH 480
#define SCREEN_HEIGHT 512

// ENGINE
#include "TinyEngine2D.h"

// GAME SCENES
#include "GameplayScene.h"
#include "MenuScene.h"


int main(int argc, char *argv[])
{
    TinyEngine2D engine{ "Tic-Tac-Toe", SCREEN_WIDTH, SCREEN_HEIGHT };
    engine.addGameScene("GameplayScene", new GameplayScene{ });
    engine.addGameScene("MenuScene", new MenuScene{ });
    engine.setFirstGameScene("MenuScene");

    engine.play();

    return 0;
}

```

## To be Implement

* Better load of imagens, and accept transparency (.png)
* 2D Physics
* Audio
