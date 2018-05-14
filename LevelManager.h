#pragma once
#include <SFML/Graphics.hpp>

class LevelManager
{

private:
	// Sets up level starts and timers.
	sf::Vector2i m_LevelSize;
	sf::Vector2f m_StartPosition;
	float m_TimeModifier = 1;
	float m_BaseTimeLimit = 0;
	int m_CurrentLevel = 0;
	const int NUM_LEVEL = 3;

public:
	// Sets up tiles, functions & intagers.
	const int TILE_SIZE = 50;
	const int VERTS_IN_QUAD = 4;

	float getTimeLimit();
	sf::Vector2f getStartPosition();
	int** NextLevel(sf::VertexArray& rVaLevel);
	sf::Vector2i GetLevelSize();
	int GetCurrentLevel();

};
