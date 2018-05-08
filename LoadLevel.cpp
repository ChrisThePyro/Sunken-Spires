#include "stdafx.h"
#include "Engine.h"

using namespace sf;

void Engine::loadLevel()
{

	m_Playing = false;

	// Delete the previously allocated memory.
	for (int i = 0; i < m_LevelManager.GetLevelSize().y; i++)
	{
		delete[] m_ArrayLevel[i];
	}
	delete[] m_ArrayLevel;

	// Load the next 2D array with the map for the level and repopulate the vertex array as well.
	m_ArrayLevel = m_LevelManager.NextLevel(m_VALevel);

	// How long is the new time limit?
	m_TimeRemaining = m_LevelManager.getTimeLimit();

	// Spawn Thomas and Bob.
	m_Character.spawn(m_LevelManager.getStartPosition(), GRAVITY);

	// Make sure this isn't run twice.
	m_NewLevel = false;

} // End of the loadLevel function.