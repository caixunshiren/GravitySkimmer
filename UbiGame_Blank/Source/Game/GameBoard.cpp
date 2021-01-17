#include "GameBoard.h"

#include "GameEngine/GameEngineMain.h"
#include "PlayerMovementComponent.h"
#include "PlayerCameraComponent.h"
#include "Levelloader.h"
#include "GameEngine/EntitySystem/Components/SpriteRenderComponent.h" //<-- Remember to include the new component we will use
#include "GameEngine/EntitySystem/Components/CollidablePhysicsComponent.h"

using namespace Game;

GameBoard::GameBoard()
	: m_gridSize(32.f)
{
	Levelloader::GetInstance()->LoadLevel(this);
	CreatePlayer(sf::Vector2i(150.f, 150.f));
}


GameBoard::~GameBoard()
{

}


void GameBoard::Update()
{	
	float dt = GameEngine::GameEngineMain::GetInstance()->GetTimeDelta();
	// UpdateGround(dt);
}

void GameBoard::CreatePlayer(sf::Vector2i coords)
{
	m_player = new GameEngine::Entity();
	GameEngine::GameEngineMain::GetInstance()->AddEntity(m_player);

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
}


void Game::GameBoard::CreateGround(sf::Vector2i coords)
{
	GameEngine::Entity* ground = new GameEngine::Entity();
	GameEngine::GameEngineMain::GetInstance()->AddEntity(ground);

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

void GameBoard::UpdatePlayerOrientation() {
	dirA = m_player->GetComponent<Game::PlayerMovementComponent>()->ay;
	GameEngine::SpriteRenderComponent* render = m_player->AddComponent<GameEngine::SpriteRenderComponent>(); //<-- Use the SpriteRenderComponent

	if (dirA > 0)
	{
		render->SetFillColor(sf::Color::Transparent);
		render->SetTexture(GameEngine::eTexture::PlayerRun);
	}  // <-- Assign the texture to this entity
	else {
		render->SetFillColor(sf::Color::Transparent);
		render->SetTexture(GameEngine::eTexture::PlayerRunFlip);
	}
}