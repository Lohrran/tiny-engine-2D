#ifndef TIME_H
#define TIME_H

#include <memory>

class Time
{
	private:
		static std::shared_ptr<Time> instance;
		double delta;

	public:
		Time();
		Time(const Time&) = delete;
		const Time& operator = (const Time&) = delete;

		static std::shared_ptr<Time> get();
		double deltaTime();
		void setDeltaTime(const double &d);
};
#endif