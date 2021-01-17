#include "GameBoard.h"
#include "GameEngine/EntitySystem/Component.h"
#include "GameEngine/Util/SoundManager.h"
#include "GameEngine/EntitySystem/Components/SoundComponent.h"
#include "GameEngine/GameEngineMain.h"
#include "PlayerMovementComponent.h"
#include "PlayerCameraComponent.h"
#include "PlayerSoundComponent.h"
#include "LinkedEntityComponent.h"
#include "Levelloader.h"
#include "GameEngine/EntitySystem/Components/SpriteRenderComponent.h" //<-- Remember to include the new component we will use
#include "GameEngine/EntitySystem/Components/CollidablePhysicsComponent.h"
#include <SFML/Window/Keyboard.hpp>   //<-- Add the keyboard include in order to get keyboard inputs
#include <iostream>
using namespace Game;

GameBoard::GameBoard()
	: m_gridSize(32.f)
	, LoadingTime(10.f)
{
	Levelloader::GetInstance()->LoadLevel(this);
	CreatePlayer((sf::Vector2i(50.f, 250.f)));
}


GameBoard::~GameBoard()
{

}


void GameBoard::Update()
{	
	float dt = GameEngine::GameEngineMain::GetInstance()->GetTimeDelta();
	/*if(!playerCreated){
		if (LoadingTime > 0) {
			LoadingTime -= GameEngine::GameEngineMain::GetTimeDelta();
		}
		else {
			//CreatePlayer((sf::Vector2i(50.f, 250.f)));
			playerCreated = true;
		}
	}*/
	//UpdatePlayerOrientation();
	// UpdateGround(dt);
}

void GameBoard::CreatePlayer(sf::Vector2i coords)
{
	m_player = new GameEngine::Entity();
	GameEngine::GameEngineMain::GetInstance()->AddEntity(m_player);
	m_player->SetEntityType(GameEngine::EEntityType::player);

	CreateBackground();


	m_player->SetPos(sf::Vector2f(coords.x, coords.y));
	m_player->SetSize(sf::Vector2f(50.0f, 50.0f));

	//Render
	GameEngine::SpriteRenderComponent* render = m_player->AddComponent<GameEngine::SpriteRenderComponent>(); //<-- Use the SpriteRenderComponent
	
	render->SetFillColor(sf::Color::Transparent);
	render->SetTexture(GameEngine::eTexture::PlayerRun);  // <-- Assign the texture to this entity
	
	//Movement
	m_player->AddComponent<Game::PlayerMovementComponent>();  // <-- Added the movement component to the player
	m_player->AddComponent<GameEngine::CollidablePhysicsComponent>();
	m_player->AddComponent <PlayerCameraComponent>();

	//sound
	//m_player->AddComponent<Game::PlayerSoundComponent>();

	GameEngine::SoundComponent* const soundComponent = m_player->AddComponent<GameEngine::SoundComponent>();
	GameEngine::SoundManager::SoundId bgm = soundComponent->LoadSoundFromFile("Resources/snd/bgm.wav");
	soundComponent->PlaySound(bgm);

}


void Game::GameBoard::CreateGround(sf::Vector2i coords)
{
	GameEngine::Entity* ground = new GameEngine::Entity();
	GameEngine::GameEngineMain::GetInstance()->AddEntity(ground);
	ground->SetEntityType(GameEngine::EEntityType::ground);


	float spawnPosX = coords.x * m_gridSize + (m_gridSize / 2.f);
	float spawnPosY = coords.y * m_gridSize + (m_gridSize / 2.f);

	ground->SetPos(sf::Vector2f(spawnPosX, spawnPosY));
	ground->SetSize(sf::Vector2f(m_gridSize, m_gridSize));

	// Render
	GameEngine::SpriteRenderComponent* spriteRender = static_cast<GameEngine::SpriteRenderComponent*>
		(ground->AddComponent<GameEngine::SpriteRenderComponent>());
	spriteRender->SetFillColor(sf::Color::Transparent);
	spriteRender->SetTexture(GameEngine::eTexture::Ground);
	ground->AddComponent<GameEngine::CollidableComponent>();
}

void Game::GameBoard::CreateDirt(sf::Vector2i coords)
{
	GameEngine::Entity* dirt = new GameEngine::Entity();
	GameEngine::GameEngineMain::GetInstance()->AddEntity(dirt);
	//dirt->SetEntityType(GameEngine::EEntityType::ground);


	float spawnPosX = coords.x * m_gridSize + (m_gridSize / 2.f);
	float spawnPosY = coords.y * m_gridSize + (m_gridSize / 2.f);

	dirt->SetPos(sf::Vector2f(spawnPosX, spawnPosY));
	dirt->SetSize(sf::Vector2f(m_gridSize, m_gridSize));

	// Render
	GameEngine::SpriteRenderComponent* spriteRender = static_cast<GameEngine::SpriteRenderComponent*>
		(dirt->AddComponent<GameEngine::SpriteRenderComponent>());
	spriteRender->SetFillColor(sf::Color::Transparent);
	spriteRender->SetTexture(GameEngine::eTexture::dirt);
	//dirt->AddComponent<GameEngine::CollidableComponent>();
}

void Game::GameBoard::CreateBackWall(sf::Vector2i coords)
{
	GameEngine::Entity* backWall = new GameEngine::Entity();
	GameEngine::GameEngineMain::GetInstance()->AddEntity(backWall);

	float spawnPosX = coords.x * m_gridSize + (m_gridSize / 2.f);
	float spawnPosY = coords.y * m_gridSize + (m_gridSize / 2.f);

	backWall->SetPos(sf::Vector2f(spawnPosX, spawnPosY));
	backWall->SetSize(sf::Vector2f(m_gridSize, m_gridSize));

	// Render
	GameEngine::SpriteRenderComponent* spriteRender = static_cast<GameEngine::SpriteRenderComponent*>
		(backWall->AddComponent<GameEngine::SpriteRenderComponent>());
	spriteRender->SetFillColor(sf::Color::Transparent);
	spriteRender->SetTexture(GameEngine::eTexture::backWall);
	spriteRender->SetZLevel(-1);
}

void Game::GameBoard::CreateSpike(sf::Vector2i coords)
{
	GameEngine::Entity* spike = new GameEngine::Entity();
	GameEngine::GameEngineMain::GetInstance()->AddEntity(spike);
	spike->SetEntityType(GameEngine::EEntityType::spike);

	float spawnPosX = coords.x * m_gridSize + (m_gridSize / 2.f);
	float spawnPosY = coords.y * m_gridSize + (m_gridSize / 2.f);

	spike->SetPos(sf::Vector2f(spawnPosX, spawnPosY));
	spike->SetSize(sf::Vector2f(m_gridSize, m_gridSize));

	// Render
	GameEngine::SpriteRenderComponent* spriteRender = static_cast<GameEngine::SpriteRenderComponent*>
		(spike->AddComponent<GameEngine::SpriteRenderComponent>());
	spriteRender->SetFillColor(sf::Color::Transparent);
	spriteRender->SetTexture(GameEngine::eTexture::spike);
	spike->AddComponent<GameEngine::CollidableComponent>();
}

void Game::GameBoard::CreateSpikeFliped(sf::Vector2i coords)
{
	GameEngine::Entity* spikeFlip = new GameEngine::Entity();
	GameEngine::GameEngineMain::GetInstance()->AddEntity(spikeFlip);
	spikeFlip->SetEntityType(GameEngine::EEntityType::spike);

	float spawnPosX = coords.x * m_gridSize + (m_gridSize / 2.f);
	float spawnPosY = coords.y * m_gridSize + (m_gridSize / 2.f);

	spikeFlip->SetPos(sf::Vector2f(spawnPosX, spawnPosY));
	spikeFlip->SetSize(sf::Vector2f(m_gridSize, m_gridSize));

	// Render
	GameEngine::SpriteRenderComponent* spriteRender = static_cast<GameEngine::SpriteRenderComponent*>
		(spikeFlip->AddComponent<GameEngine::SpriteRenderComponent>());
	spriteRender->SetFillColor(sf::Color::Transparent);
	spriteRender->SetTexture(GameEngine::eTexture::spikeFlip);
	spikeFlip->AddComponent<GameEngine::CollidableComponent>();
}

void Game::GameBoard::CreateBackground()
{
	GameEngine::Entity* background = new GameEngine::Entity();
	GameEngine::GameEngineMain::GetInstance()->AddEntity(background);

	background->SetPos(sf::Vector2f(250.f,250.f));
	background->SetSize(sf::Vector2f(600.f, 600.f));

	GameEngine::SpriteRenderComponent* render = static_cast<GameEngine::SpriteRenderComponent*>
		(background->AddComponent<GameEngine::SpriteRenderComponent>());

	render->SetTexture(GameEngine::eTexture::Background);
	render->SetFillColor(sf::Color::Transparent);
	render->SetZLevel(-1);

	LinkedEntityComponent* linkedcmp = static_cast<LinkedEntityComponent*>
		(background->AddComponent<LinkedEntityComponent>());
	linkedcmp->SetFollowedEntity(m_player);
	linkedcmp->SetFollowOff(sf::Vector2f(50.f, 0.f));

}
