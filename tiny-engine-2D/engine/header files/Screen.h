#ifndef SCREEN_H
#define SCREEN_H

#include <memory>
#include <string>

//Library SDL2
#include <SDL.h>
#undef main

#include "Camera.h"

class Screen
{
	public:
		Screen(std::string title, int width, int height);

		Screen& operator = (const Screen&) = delete;
		Screen& operator = (Screen&&) = delete;
		
		~Screen() = default;

		void create();
		void update();
		void close();

	private:
		bool isInitialized();

		std::shared_ptr<Camera> camera = Camera::get();
		SDL_Window* Window;
		SDL_Surface* SurfaceWindow;

		std::string title;
		int width, height;
};
#endif