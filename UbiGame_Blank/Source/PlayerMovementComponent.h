#pragma once
#include "GameEngine/EntitySystem/Component.h"

namespace Game
{
	class PlayerMovementComponent : public GameEngine::Component
	{
	public:
		virtual void Update() override;
		virtual void OnAddToWorld() override;
		float dy;
		float vy;
		float ay;
		float dx;
		float vx;
		bool lastframepressed;
		//gravity
		float g;
		PlayerMovementComponent() { // Constructor 
			dy = 0.0;
			vy = 0.0;
			ay = 1.0;
			dx = 0.0;
			vx = 4.0;
			lastframepressed = false;
			g = 40.0;
		}
	};
}