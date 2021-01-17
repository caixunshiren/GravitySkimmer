#pragma once
#include <vector>

namespace Game 
{
	class GameBoard;

	class Levelloader
	{
	public:
		~Levelloader();

		float m_gridSize = 50.0f;

		static Levelloader* GetInstance() { if (!sm_instance) sm_instance = new Levelloader(); return sm_instance; }
	
		void LoadLevel(GameBoard* board);

	private:
		Levelloader();
		static Levelloader* sm_instance;
	};
}



