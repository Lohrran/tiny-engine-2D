#ifndef KEYBOARDSYSTEM_H
#define KEYBOARDSYSTEM_H

#include <SDL.h>

#include "RequestEvent.h"
#include "Requeriment.h"
#include "KeyboardComponent.h"
#include "KeyboardDownEvent.h"

class KeyboardSystem : public Requeriment <KeyboardComponent>
{
	public:
		void init(GameObject* obj) override;
		void update(GameObject* obj) override;
		void free(GameObject* obj) override;

	private:
		std::shared_ptr<RequestEvent> keyEvent = RequestEvent::get();
};
#endif