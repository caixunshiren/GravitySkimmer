#pragma once
#include "GameEngine/EntitySystem/Component.h"
#include "SFML/System/Vector2.hpp"
#include "GameEngine/EntitySystem/Entity.h"


class GameEngine::Entity;

namespace Game
{
	class LinkedEntityComponent : public GameEngine::Component
	{
	public:
		LinkedEntityComponent();
		~LinkedEntityComponent();
		void Update();
		GameEngine::Entity* m_followedEntity;
		sf::Vector2f m_offset;
		void SetFollowedEntity(GameEngine::Entity*);
		void SetFollowOff(sf::Vector2f);
	};


}