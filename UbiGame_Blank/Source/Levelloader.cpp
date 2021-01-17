#include "Levelloader.h"
#include "SFML//Graphics/Texture.hpp"
#include "GameEngine//Util//TextureManager.h"
#include "SFML/Graphics/Color.hpp"
#include "Game//GameBoard.h"
#include <ioStream>

using namespace Game;

Levelloader* Levelloader::sm_instance = nullptr;

Levelloader::Levelloader() {}

Levelloader::~Levelloader() {}

void Levelloader::LoadLevel(GameBoard* board) {
    sf::Texture* level = GameEngine::TextureManager::GetInstance()->GetTexture(GameEngine::eTexture::level);

    sf::Image levelImage = level->copyToImage();

    for (unsigned int y = 0; y < levelImage.getSize().y; y++) {
        for (unsigned int x = 0; x < levelImage.getSize().x; x++) {
            sf::Color pixelColor = levelImage.getPixel(x, y);
            
            //if (pixelColor.r == 255 && pixelColor.g == 0 && pixelColor.b == 0) {
            //    std::cout << pixelColor.r << ", " << pixelColor.g << ", " << pixelColor.b << std::endl;
            //    //board->CreatePlayer(sf::Vector2i(x, y));
            //}
            board->CreateBackWall(sf::Vector2i(x, y));
            if (pixelColor.r < 2 && pixelColor.g < 2 && pixelColor.b < 2) {
                board->CreateGround(sf::Vector2i(x, y));
            }
            else if (pixelColor.r < 2 && pixelColor.g < 2 && pixelColor.b > 253) {
                board->CreateSpike(sf::Vector2i(x, y));
            }

            
        }
    }
}