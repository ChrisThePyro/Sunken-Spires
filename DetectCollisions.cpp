#include "stdafx.h"
#include "Engine.h"
#include <iostream>

using namespace sf;

bool Engine::detectCollisions(PlayableCharacter& character)
{
	// Initialise reachedGoal to false by default.
	bool reachedGoal = false;

	// make a rectangle for the Character's collision
	FloatRect detectionZone = character.getPosition();

	// Make a FloatRect to test each block.
	FloatRect block;

	block.width = TILE_SIZE;
	block.height = TILE_SIZE;

	// Build a zone around the Character to detect collision.
	int startX = (int)(detectionZone.left / TILE_SIZE) - 1;
	int startY = (int)(detectionZone.top / TILE_SIZE) - 1;
	int endX = (int)(detectionZone.left / TILE_SIZE) + 2;
	int endY = (int)(detectionZone.top / TILE_SIZE) + 3; // Tgomas is quite tall.

														 // Make sure we don't test positions lower than zero.
	if (startX < 0) startX = 0;
	if (startY < 0) startY = 0;

	// Make sure we don't test positions greater than our level size.
	if (endX > m_LevelManager.GetLevelSize().x) endX = m_LevelManager.GetLevelSize().x;
	if (endY > m_LevelManager.GetLevelSize().y) endY = m_LevelManager.GetLevelSize().y;

	// Handle player falling out of the level.
	FloatRect level(0, 0, m_LevelManager.GetLevelSize().x * TILE_SIZE, m_LevelManager.GetLevelSize().y * TILE_SIZE);
	if (!detectionZone.intersects(level))
	{
		// Respawn the Character
		character.spawn(m_LevelManager.getStartPosition(), GRAVITY);
	}

	// Loop through all nearby blocks.
	for (int x = startX; x < endX; ++x)
	{
		for (int y = startY; y < endY; ++y)
		{
			// Set up our current block.
			block.left = x * TILE_SIZE;
			block.top = y * TILE_SIZE;

			  // Is Character collding with a regular block?
			if (m_ArrayLevel[y][x] == 1)
			{
				if (character.getRight().intersects(block))
				{
					character.stopRight(block.left);
				}
				else if (character.getLeft().intersects(block))
				{
					character.stopLeft(block.left);
				}

				if (character.getFeet().intersects(block))
				{
					character.stopFalling(block.top);
				}
				else if (character.getHead().intersects(block))
				{
					character.stopJump();
				}
			} // end normal block test.

			  // Have we reached the goal?
			if (m_ArrayLevel[y][x] == 4)
			{
				// Character has reached the goal.
				reachedGoal = true;
			}

			// More collisions here once we have learned about particle effects.

		} // End y loop.
	} // End x loop.


	  // Return weather or not our Characters hae completed this level.
	return reachedGoal;

} // End detectCollisions()