#include "Time.h"

std::shared_ptr<Time> Time::instance = nullptr;

Time::Time() { }

std::shared_ptr<Time> Time::get()
{
	if (instance == nullptr)
	{
		instance = std::make_shared<Time>();
	}

	return instance;
}

double Time::deltaTime()
{
	return delta;
}

void Time::setDeltaTime(const double& d)
{
	delta = d;
}