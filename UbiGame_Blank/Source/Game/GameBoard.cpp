#include "GameBoard.h"

#include "GameEngine/GameEngineMain.h"
#include "PlayerMovementComponent.h"
#include "PlayerCameraComponent.h"
#include "GameEngine/EntitySystem/Components/SpriteRenderComponent.h" //<-- Remember to include the new component we will use
#include "GameEngine/EntitySystem/Components/CollidablePhysicsComponent.h"
#include <SFML/Window/Keyboard.hpp>   //<-- Add the keyboard include in order to get keyboard inputs

using namespace Game;

GameBoard::GameBoard()
{
	CreatePlayer();
	CreateGround();
}


GameBoard::~GameBoard()
{

}


void GameBoard::Update()
{	
	float dt = GameEngine::GameEngineMain::GetInstance()->GetTimeDelta();
	// UpdateGround(dt);
}

void GameBoard::CreatePlayer()
{
	m_player = new GameEngine::Entity();
	GameEngine::GameEngineMain::GetInstance()->AddEntity(m_player);

	m_player->SetPos(sf::Vector2f(200.0f, 300.0f));
	m_player->SetSize(sf::Vector2f(50.0f, 50.0f));

	//Render
	GameEngine::SpriteRenderComponent* render = m_player->AddComponent<GameEngine::SpriteRenderComponent>(); //<-- Use the SpriteRenderComponent
	last_dir = m_player->GetComponent<Game::PlayerMovementComponent>()->ay;
	render->SetFillColor(sf::Color::Transparent);
	render->SetTexture(GameEngine::eTexture::PlayerRun);  // <-- Assign the texture to this entity
	
	//Movement
	m_player->AddComponent<Game::PlayerMovementComponent>();  // <-- Added the movement component to the player
	m_player->AddComponent<GameEngine::CollidablePhysicsComponent>();
	m_player->AddComponent <PlayerCameraComponent>();
}

void GameBoard::CreateGround() {
	GameEngine::Entity* ground = new GameEngine::Entity();
	GameEngine::GameEngineMain::GetInstance()->AddEntity(ground);

	ground->SetPos(sf::Vector2f(50.0f, 50.0f));
	ground->SetSize(sf::Vector2f(50.0f, 50.0f));

	// Render
	GameEngine::SpriteRenderComponent* spriteRender = static_cast<GameEngine::SpriteRenderComponent*>
		(ground->AddComponent<GameEngine::SpriteRenderComponent>());
	spriteRender->SetFillColor(sf::Color::Transparent);
	spriteRender->SetTexture(GameEngine::eTexture::Ground);
	ground->AddComponent<GameEngine::CollidableComponent>();
}

void GameBoard::UpdatePlayerOrientation() {
	float this_dir = m_player->GetComponent<Game::PlayerMovementComponent>()->ay;
	GameEngine::SpriteRenderComponent* render = m_player->AddComponent<GameEngine::SpriteRenderComponent>(); //<-- Use the SpriteRenderComponent

	if (this_dir > 0)
	{
		render->SetFillColor(sf::Color::Transparent);
		render->SetTexture(GameEngine::eTexture::PlayerRun);
	}  // <-- Assign the texture to this entity
	else {
		render->SetFillColor(sf::Color::Transparent);
		render->SetTexture(GameEngine::eTexture::PlayerRunFlip);
	}
}