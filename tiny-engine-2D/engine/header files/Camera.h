#ifndef CAMERA_H
#define CAMERA_H

#include <SDL.h>
#include <memory>

class Camera
{
	public:
		Camera();
		
		Camera(const Camera&) = delete;
		Camera& operator = (const Camera&) = delete;

		static std::shared_ptr<Camera> get();

		static SDL_Window* window();
		static SDL_Surface* surface();
		
		static void set(SDL_Window* window, SDL_Surface* surface);
		static void reset();

	private:
		static std::shared_ptr<Camera> instance;
		static SDL_Window* Window;
		static SDL_Surface* Surface;
};
#endif