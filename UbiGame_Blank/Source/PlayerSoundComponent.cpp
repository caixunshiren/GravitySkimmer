#include "PlayerSoundComponent.h"

#include "GameEngine/GameEngineMain.h"
#include "GameEngine/EntitySystem/Components/SoundComponent.h"

using namespace Game;

PlayerSoundComponent::PlayerSoundComponent()
{

}


PlayerSoundComponent::~PlayerSoundComponent()
{

}

void PlayerSoundComponent::OnAddToWorld()
{
	if (GameEngine::SoundComponent* const soundComponent = GetEntity()->GetComponent<GameEngine::SoundComponent>())
	{
		bgm = soundComponent->LoadSoundFromFile("Resources/snd/bgm.mp3");
		soundComponent->PlaySound(bgm);
	}
}


void PlayerSoundComponent::Update()
{
	Component::Update();

	m_timeSinceLastUpSound += GameEngine::GameEngineMain::GetTimeDelta();
	m_timeSinceLastDownSound += GameEngine::GameEngineMain::GetTimeDelta();
}


void PlayerSoundComponent::RequestSound(bool upSound)
{
	static bool enablePlayerSounds = false;	
	if (!enablePlayerSounds)
		return;

	GameEngine::SoundManager::SoundId soundId = upSound ? m_upSoundId : m_downSoundId;
	float& lastPlayTimer =					    upSound ? m_timeSinceLastUpSound : m_timeSinceLastDownSound;
	

	if (GameEngine::SoundComponent* const soundComponent = GetEntity()->GetComponent<GameEngine::SoundComponent>())
	{
		if (lastPlayTimer > 1.0f)
		{
			soundComponent->PlaySound(soundId);
			lastPlayTimer = 0.0f;
		}
	}
}