#include "GameEngine/EntitySystem/Component.h"
#include "SFML/System/Vector2.hpp"
#include "LinkedEntityComponent.h"
#include "GameEngine/EntitySystem/Entity.h"


using namespace Game;

LinkedEntityComponent::LinkedEntityComponent()
	: m_followedEntity(nullptr)
	, m_offset(sf::Vector2f(0.f, 0.f))
{}

LinkedEntityComponent::~LinkedEntityComponent()
{

}

void LinkedEntityComponent::Update()
{
	__super::Update();

	if (m_followedEntity)
	{
		GetEntity()->SetPos(m_followedEntity->GetPos() + m_offset);
	}
}

void LinkedEntityComponent::SetFollowedEntity(GameEngine::Entity* player) {
	m_followedEntity = player;
}

void LinkedEntityComponent::SetFollowOff(sf::Vector2f f) {
	m_offset = f;
}