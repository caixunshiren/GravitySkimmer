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
			vx = 100.0;
			lastframepressed = false;
			g = 340.0;
		}


		int maxSpriteIndexRun = 3;
		int m_lastSpriteIndex = 0;
		float animationFrameRateTimerMax = 0.1f;
		float animationFrameRateTimer = animationFrameRateTimerMax;
	};
}