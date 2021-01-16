#include "Levelloader.h"
#include "SFML//Graphics/Texture.hpp"
#include "GameEngine//Util//TextureManager.h"
#include "SFML/Graphics/Color.hpp"
#include "Game//GameBoard.h"

using namespace Game;

Levelloader* Levelloader::sm_instance = nullptr;

Levelloader::Levelloader() {}

Levelloader::~Levelloader() {}

void Levelloader::LoadLevel(GameBoard* board) {

}