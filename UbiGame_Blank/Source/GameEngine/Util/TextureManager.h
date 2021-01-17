#pragma once
#include <vector>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Vector2.hpp>

namespace GameEngine
{
	//TODO - if needed, move out of Engine part to some sort of loader on the game side of things
	namespace eTexture
	{
		enum type
		{
			None = -1,
			PlayerRun, //<-- Add a new entry for our new texture
			PlayerRunFlip,
			Ground, //<-- ground texture
			dirt,
			backWall,
			spike,
			spikeFlip,
			level,
			Background,
			Count,
		};
	}	

	inline const char* GetPath(eTexture::type texture)
	{
		switch (texture)
		{
		case eTexture::PlayerRun: return "Character-combined.png"; //<-- The name of the image on disk
		case eTexture::PlayerRunFlip: return "Character-run-flip.png"; //<-- The name of the image on disk
		case eTexture::Ground: return "grass-surface.png"; //<-- The name of the image on disk
		case eTexture::dirt: return "dirt.png"; //<-- The name of the image on disk
		case eTexture::level: return "level_final.png"; //<-- The name of the image on disk
		case eTexture::backWall: return "backwall.png"; //<-- The name of the image on disk
		case eTexture::spike: return "woodSpike.png";
		case eTexture::spikeFlip: return "woodSpikeFlip.png";
		case eTexture::Background: return "Background3.png";
		}
		return "UnknownTexType";
	}

	class TextureManager
	{
	public:
		static TextureManager* GetInstance() { if (!sm_instance) sm_instance = new TextureManager(); return sm_instance; }
		~TextureManager();

		void LoadTextures();
		void UnLoadTextures();

		sf::Texture* GetTexture(eTexture::type texture) const { return m_textures[(int)texture]; }

	private:
		TextureManager();
		static TextureManager* sm_instance;

		sf::Texture* m_textures[eTexture::Count];
	};
}

namespace TextureHelper
{
	sf::Vector2f GetTextureTileSize(GameEngine::eTexture::type texture);
}

