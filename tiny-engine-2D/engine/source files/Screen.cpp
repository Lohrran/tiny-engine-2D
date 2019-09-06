#include "Screen.h"

Screen::Screen(std::string title, int width, int height) : title{ title }, width{ width }, height{ height }
{
	// Initialize Window and SurfaceWindow if already exist a created Camera
	if (camera->window() != NULL)
	{
		Window = camera->window();
	}

	if (camera->surface() != NULL)
	{
		SurfaceWindow = camera->surface();
	}
}

void Screen::create()
{
	bool initialized = isInitialized();
}

void Screen::update()
{
	SDL_UpdateWindowSurface(Window);
	SDL_FillRect(SurfaceWindow, NULL, SDL_MapRGB(SurfaceWindow->format, 75, 117, 242));

	camera->set(Window, SurfaceWindow);
}

void Screen::close()
{
	SDL_FreeSurface(SurfaceWindow);
	SurfaceWindow = NULL;

	SDL_DestroyWindow(Window);
	Window = NULL;

	camera->reset();

	SDL_Quit();
}

bool Screen::isInitialized()
{
	bool success = true;
	if (SDL_Init(SDL_INIT_VIDEO) >= 0)
	{
		Window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);

		if (Window != NULL)
		{
			SurfaceWindow = SDL_GetWindowSurface(Window);

			SDL_FillRect(SurfaceWindow, NULL, SDL_MapRGB(SurfaceWindow->format, 75, 117, 242));
		}

		else
		{
			success = false;
		}
	}

	else
	{
		success = false;
	}

	camera->set(Window, SurfaceWindow);

	return success;
}