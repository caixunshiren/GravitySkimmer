#include "PlayerMovementComponent.h"

#include <SFML/Window/Keyboard.hpp>   //<-- Add the keyboard include in order to get keyboard inputs

#include "GameEngine/GameEngineMain.h" //<-- Add this include to retrieve the delta time between frames

using namespace Game;

void PlayerMovementComponent::Update() 
{
	Component::Update();
    


    //Grabs how much time has passed since last frame
    const float dt = GameEngine::GameEngineMain::GetTimeDelta();

    //By default the displacement is 0,0
    sf::Vector2f displacement{ 0.0f,0.0f };

    //alternate gravity direction when space is pressed
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
    {
        if (lastframepressed == false) {
            ay = ay * -1;
            vy = 0;
            dy = 0;
            lastframepressed = true;
        }
        
    }
    else { lastframepressed = false; }

    //update effect due to gravity
    vy = vy + ay * g * dt;
    dy = vy * dt;
    displacement.y += dy;

    //moving right
    dx = vx * dt;
    displacement.x += dx;

    /*
    //The amount of speed that we will apply when input is received
    const float inputAmount = 100.0f;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        displacement.x -= inputAmount * dt;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        displacement.x += inputAmount * dt;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        displacement.y -= inputAmount * dt;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        displacement.y += inputAmount * dt;
    }
    */

    //Update the entity position
    GetEntity()->SetPos(GetEntity()->GetPos() + displacement);
}

void PlayerMovementComponent::OnAddToWorld() {}