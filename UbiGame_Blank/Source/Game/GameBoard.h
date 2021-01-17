#pragma once
#include "GameEngine/EntitySystem/Entity.h"

#include <SFML/System/Vector2.hpp>
#include <vector>

namespace Game
{
	//Used for storing and controlling all game related entities, as well as providing an entry point for the "game" side of application	
	class PlayerEntity;	

	class GameBoard
	{
	public:
		GameBoard();
		virtual ~GameBoard();
		void CreatePlayer(sf::Vector2i coords);
		void CreateGround(sf::Vector2i coords);
		void CreateDirt(sf::Vector2i coords);
		void CreateBackWall(sf::Vector2i coords);
		void CreateSpike(sf::Vector2i coords);
		void CreateSpikeFliped(sf::Vector2i coords);

		void CreateBackground();
		void Update();		
		bool IsGameOver() { return false; }

	private:
		GameEngine::Entity* m_player;
		//void UpdateGround(float dt);
		//void UpdatePlayerOrientation();
		GameEngine::Entity* ground;

		float m_gridSize;
		float LoadingTime;
		bool playerCreated;
	};
}

