#include "GameBoard.h"

#include "GameEngine/GameEngineMain.h"
#include "PlayerMovementComponent.h"
#include "GameEngine/EntitySystem/Components/SpriteRenderComponent.h" //<-- Remember to include the new component we will use

using namespace Game;

GameBoard::GameBoard()
{
	CreatePlayer();
}


GameBoard::~GameBoard()
{

}


void GameBoard::Update()
{	
	
}

void GameBoard::CreatePlayer()
{
	m_player = new GameEngine::Entity();
	GameEngine::GameEngineMain::GetInstance()->AddEntity(m_player);

	m_player->SetPos(sf::Vector2f(50.0f, 50.0f));
	m_player->SetSize(sf::Vector2f(50.0f, 50.0f));

	//Render
	GameEngine::SpriteRenderComponent* render = m_player->AddComponent<GameEngine::SpriteRenderComponent>(); //<-- Use the SpriteRenderComponent
	
	render->SetFillColor(sf::Color::Transparent);
	render->SetTexture(GameEngine::eTexture::Player);  // <-- Assign the texture to this entity
	
	//Movement
	m_player->AddComponent<Game::PlayerMovementComponent>();  // <-- Added the movement component to the player
}