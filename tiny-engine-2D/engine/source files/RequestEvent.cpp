#include "RequestEvent.h"

std::shared_ptr<RequestEvent> RequestEvent::instance = nullptr;
std::shared_ptr<SDL_Event> RequestEvent::Event = nullptr;

RequestEvent::RequestEvent() { }

std::shared_ptr<RequestEvent> RequestEvent::get()
{
	if (instance == nullptr)
	{
		instance = std::make_shared<RequestEvent>();
	}
	return instance;
}

std::shared_ptr<SDL_Event> RequestEvent::getSDLEvent()
{
	if (Event == nullptr)
	{
		Event = std::make_shared<SDL_Event>();
	}
	return Event;
}