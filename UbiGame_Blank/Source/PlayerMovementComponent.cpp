#include "PlayerMovementComponent.h"

#include <SFML/Window/Keyboard.hpp>   //<-- Add the keyboard include in order to get keyboard inputs

#include "GameEngine/GameEngineMain.h" //<-- Add this include to retrieve the delta time between frames

#include "GameEngine/EntitySystem/Components/SpriteRenderComponent.h"

#include "GameEngine/EntitySystem/Components/CollidablePhysicsComponent.h"

#include <iostream>// dubug

#include "GameEngine/EntitySystem/Components/CollidablePhysicsComponent.h"

using namespace Game;




void PlayerMovementComponent::Update() 
{
	Component::Update();
    

    check_state();

    PlayerControl();
    animateByState();

    
}

void PlayerMovementComponent::check_state() {
    GameEngine::CollidablePhysicsComponent* hitbox = GetEntity()->GetComponent<GameEngine::CollidablePhysicsComponent>();


}

void PlayerMovementComponent::animateByState() {
    if (state == 1) {

        if (animationFrameRateTimer < 0) {
            s1++;
            animationFrameRateTimer = animationFrameRateTimerMax;
        }
        else {
            animationFrameRateTimer -= GameEngine::GameEngineMain::GetTimeDelta();;
        }

        if (s1 > 3) { s1 = 0; }

        GameEngine::SpriteRenderComponent* render = GetEntity()->GetComponent<GameEngine::SpriteRenderComponent>();
        if (render)
        {
            render->SetTileIndex(sf::Vector2i(s1, 0));
        }

    }
    if (state == 2) {
        if (animationFrameRateTimer < 0) {
            s2++;
            animationFrameRateTimer = animationFrameRateTimerMax;
        }
        else {
            animationFrameRateTimer -= GameEngine::GameEngineMain::GetTimeDelta();;
        }

        if (s2 > 7) { s2 = 4; }

        GameEngine::SpriteRenderComponent* render = GetEntity()->GetComponent<GameEngine::SpriteRenderComponent>();
        if (render)
        {
            render->SetTileIndex(sf::Vector2i(s2, 0));
        }

    }
    if (state == 3) {
        if (animationFrameRateTimer < 0) {
            s3++;
            animationFrameRateTimer = animationFrameRateTimerMax;
        }
        else {
            animationFrameRateTimer -= GameEngine::GameEngineMain::GetTimeDelta();;
        }

        if (s3 > 9) { s3 = 8; }

        GameEngine::SpriteRenderComponent* render = GetEntity()->GetComponent<GameEngine::SpriteRenderComponent>();
        if (render)
        {
            render->SetTileIndex(sf::Vector2i(s3, 0));
        }

    }
    if (state == 4) {
        if (animationFrameRateTimer < 0) {
            s4++;
            animationFrameRateTimer = animationFrameRateTimerMax;
        }
        else {
            animationFrameRateTimer -= GameEngine::GameEngineMain::GetTimeDelta();;
        }

        if (s4 > 11) { s4 = 10; }

        GameEngine::SpriteRenderComponent* render = GetEntity()->GetComponent<GameEngine::SpriteRenderComponent>();
        if (render)
        {
            render->SetTileIndex(sf::Vector2i(s4, 0));
        }

    }

}

void PlayerMovementComponent::PlayerControl() {
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

    //Update the entity position
    GetEntity()->SetPos(GetEntity()->GetPos() + displacement);
    GameEngine::CollidablePhysicsComponent* colPhys = GetEntity()->GetComponent<GameEngine::CollidablePhysicsComponent>();
    if (colPhys->DidCollide() && colPhys->GetLastCollideEntity() != nullptr) {
        std::cout << "Player destroyed" << std::endl;
        GameEngine::GameEngineMain::GetInstance()->RemoveEntity(GetEntity());
        //GameEngine::GameEngineMain::GetInstance()->RemoveEntity(colPhys->GetLastCollideEntity());
    }
    
    
}

void PlayerMovementComponent::OnAddToWorld() {}