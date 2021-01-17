#include "PlayerCameraComponent.h"

#include "GameEngine/GameEngineMain.h"
#include "GameEngine/Util/CameraManager.h"

using namespace Game;

PlayerCameraComponent::PlayerCameraComponent()
{

}


PlayerCameraComponent::~PlayerCameraComponent()
{

}

void PlayerCameraComponent::OnAddToWorld()
{

}


void PlayerCameraComponent::Update()
{
	Component::Update();
	sf::Vector2f offSet = sf::Vector2f(170.f, 0);
	GameEngine::CameraManager::GetInstance()->GetCameraView().setCenter(GetEntity()->GetPos() + offSet);
}