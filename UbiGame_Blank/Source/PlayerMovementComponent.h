#pragma once
#include "GameEngine/EntitySystem/Component.h"

namespace Game
{
	class PlayerMovementComponent : public GameEngine::Component
	{
	public:
		virtual void Update() override;
		virtual void OnAddToWorld() override;
		void animateByState();
		void PlayerControl();
		void check_state();
		void CollideSpike();
		float dy;
		float vy;
		float ay;
		float dx;
		float vx;
		bool lastframepressed;
		//gravity
		float g;
		int state; 

		//animation states
		int s1;
		int s2;
		int s3;
		int s4;

		PlayerMovementComponent() { // Constructor 
			dy = 0.0;
			vy = 0.0;
			ay = 1.0;
			dx = 0.0;
			vx = 200.0;
			lastframepressed = false;
			g = 340.0;
			state = 3;
			s1 = 0;
			s2 = 4;
			s3 = 8;
			s4 = 10;
		}

		float last_y = 0;

		int maxSpriteIndexRun = 3;
		int m_lastSpriteIndex = 0;
		float animationFrameRateTimerMax = 0.1f;
		float animationFrameRateTimer = animationFrameRateTimerMax;
	};
}