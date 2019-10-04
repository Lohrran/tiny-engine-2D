#ifndef BOXCOLLISIONSYSTEM_H
#define BOXCOLLISIONSYSTEM_H

//System
#include "Requeriment.h"

//Components
#include "BoxColliderComponent.h"
#include "PositionComponent.h"

//Events
#include "CollisionEvent.h"

class BoxCollisionSystem : public Requeriment <BoxColliderComponent, PositionComponent>
{
	public:
		void init(GameObject* obj) override;
		void update(GameObject* obj) override;
		void free(GameObject* obj) override;

	private:
		bool checkBoxCollision(GameObject* obj, GameObject* other);
};
#endif