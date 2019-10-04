#ifndef REQUESTEVENT_H
#define REQUESTEVENT_H

#include <SDL.h>
#include <memory>

class RequestEvent
{
	private:
		static std::shared_ptr<RequestEvent> instance;
		static std::shared_ptr<SDL_Event> Event;

	public:
		RequestEvent();
		RequestEvent(const RequestEvent&) = delete;
		RequestEvent& operator = (const RequestEvent&) = delete;

		static std::shared_ptr<RequestEvent> get();

		static std::shared_ptr<SDL_Event> getSDLEvent();

};
#endif
