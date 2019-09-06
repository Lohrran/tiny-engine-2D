#include "Camera.h"

std::shared_ptr<Camera> Camera::instance = nullptr;
SDL_Window* Camera::Window = NULL;
SDL_Surface* Camera::Surface = NULL;

Camera::Camera() { }

std::shared_ptr<Camera> Camera::get()
{
	if (instance == nullptr)
	{
		instance = std::make_shared<Camera>();
	}
	return instance;
}

SDL_Window* Camera::window()
{
	return Window;
}

SDL_Surface* Camera::surface() 
{
	return Surface;
}

void Camera::set(SDL_Window* window, SDL_Surface* surface)
{
	if (window != NULL)
	{
		Window = window;
	}

	if (surface != NULL)
	{
		Surface = surface;
	}
}

void Camera::reset()
{
	Window = NULL;
	Surface = NULL;
}