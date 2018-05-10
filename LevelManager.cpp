#include "stdafx.h"
#include "LevelManager.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "TextureHolder.h"
#include <sstream>
#include <fstream>

using namespace sf;
using namespace std;

int** LevelManager::NextLevel(VertexArray& rVaLevel)
{
	m_LevelSize.x = 0;
	m_LevelSize.y = 0;

	// Get the next level.
	m_CurrentLevel++;
	if (m_CurrentLevel > NUM_LEVEL)
	{
		m_CurrentLevel = 1;
		m_TimeModifier -= 0.1f;
	}

	string LevelToLoad;
	switch (m_CurrentLevel)
	{
	case 1:
		LevelToLoad = "levels/level1.txt";
		m_StartPosition.x = 100;
		m_StartPosition.y = 380;
		m_BaseTimeLimit = 100.0f;
		break;

	case 2:
		LevelToLoad = "levels/level2.txt";
		m_StartPosition.x = 100;
		m_StartPosition.y = 380;
		m_BaseTimeLimit = 100.0f;
		break;

	case 3:
		LevelToLoad = "levels/level3.txt";
		m_StartPosition.x = 1250;
		m_StartPosition.y = 0;
		m_BaseTimeLimit = 30.0f;
		break;
	}

	ifstream InputFile(LevelToLoad);
	string s;

	while (getline(InputFile, s))
	{
		++m_LevelSize.y;
	}

	m_LevelSize.x = s.length();

	InputFile.clear();
	InputFile.seekg(0, ios::beg);

	int** arrayLevel = new int*[m_LevelSize.y];
	for (int i = 0; i < m_LevelSize.y; ++i)
	{
		arrayLevel[i] = new int[m_LevelSize.x];
	}

string row;
int y = 0;

while (InputFile >> row)
{
	for (int x = 0; x < row.length(); x++)
	{
		const char val = row[x];
		arrayLevel[y][x] = atoi(&val);
	}

	++y;
}

// Close the file
InputFile.close();

// What type of primitive are we using?
rVaLevel.setPrimitiveType(Quads);

// Set the size of the vertex array.
rVaLevel.resize(m_LevelSize.x * m_LevelSize.y * VERTS_IN_QUAD);

// Start at the begining of the vertex array.
int currentVertex = 0;

	for (int x = 0; x < m_LevelSize.x; ++x)
	{
		for (int y = 0; y < m_LevelSize.y; ++y)
		{

			// Position each vertex in the current quad.
			rVaLevel[currentVertex + 0].position = Vector2f(
				x * TILE_SIZE, 
				y * TILE_SIZE);
			rVaLevel[currentVertex + 1].position = Vector2f(
				x * TILE_SIZE + TILE_SIZE, 
				y * TILE_SIZE);
			rVaLevel[currentVertex + 2].position = Vector2f(
				x * TILE_SIZE + TILE_SIZE, 
				y * TILE_SIZE + TILE_SIZE);
			rVaLevel[currentVertex + 3].position = Vector2f(
				x * TILE_SIZE, 
				y * TILE_SIZE + TILE_SIZE);

			// Which tile from the sprite sheet should we use.
			int verticalOffset = arrayLevel[y][x] * TILE_SIZE;

			// Set up texture coordinates.
			rVaLevel[currentVertex + 0].texCoords = Vector2f(0, 0 + verticalOffset);
			rVaLevel[currentVertex + 1].texCoords = Vector2f(TILE_SIZE, 0 + verticalOffset);
			rVaLevel[currentVertex + 2].texCoords = Vector2f(TILE_SIZE, TILE_SIZE + verticalOffset);
			rVaLevel[currentVertex + 3].texCoords = Vector2f(0, TILE_SIZE + verticalOffset);

			// Update our current vertex so we can draw the next quad.
			currentVertex = currentVertex + VERTS_IN_QUAD;

		}
	} // End X for loop.

	return arrayLevel;

} // End function nextLevel().

Vector2i LevelManager::GetLevelSize()
{
	return m_LevelSize;
}

int LevelManager::GetCurrentLevel()
{
	return m_CurrentLevel;
}

float LevelManager::getTimeLimit()
{
	return m_BaseTimeLimit * m_TimeModifier;
}

Vector2f LevelManager::getStartPosition()
{
	return m_StartPosition;
}