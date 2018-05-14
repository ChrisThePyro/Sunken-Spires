#include "stdafx.h"
#include "Engine.h"
#include "PlayableCharacter.h"
#include "LevelManager.h"
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
	int startY = (int)(detectionZone.top / TILE_SIZE);
	int endX = (int)(detectionZone.left / TILE_SIZE) + 2;
	int endY = (int)(detectionZone.top / TILE_SIZE) + 3;

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
			if (m_ArrayLevel[y][x] == 1 || m_ArrayLevel[y][x] == 3)
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

			if (m_ArrayLevel[y][x] == 5 || m_ArrayLevel[y][x] == 6)
			{
				if (character.getFeet().intersects(block))
				{
					character.stopFalling(block.top);
				}
			}

			if (m_ArrayLevel[y][x] == 2)
			{
				if (character.getHead().intersects(block))
				{
					// The are in the water
					character.respawn(m_LevelManager.getStartPosition(), GRAVITY);
					m_SoundManager.playFallInWater();
					character.m_Lives -= 1;
				}
			} // End water


			// Spikey thing
			if (m_ArrayLevel[y][x] == 8)
			{
				// Check if this block is in our immune list
				sf::Vector2i blockCoords;
				blockCoords.y = y;
				blockCoords.x = x;

				bool inImmuneList = false;
				auto itImmune = character.m_ImmuneBlocks.begin();
				for (; itImmune != character.m_ImmuneBlocks.end(); ++itImmune)
				{
					if (blockCoords == *itImmune)
					{
						inImmuneList = true;
						break;
					}
				}

				// Test collisions & act on any we encounter
				bool collidedWithBlock = false;

				if (character.getRight().intersects(block))
				{
					if (!inImmuneList)
					{
						character.m_Health = (character.m_Health - 10);
						character.m_Position.x -= 75;
						m_SoundManager.PlayOuch();
					}
					collidedWithBlock = true;
				}
				else if (character.getLeft().intersects(block))
				{
					if (!inImmuneList)
					{
						character.m_Health = (character.m_Health - 10);
						character.m_Position.x += 75;
						m_SoundManager.PlayOuch();
					}
					collidedWithBlock = true;
				}
				else if (character.getFeet().intersects(block))
				{
					if (!inImmuneList)
					{
						character.m_Health = (character.m_Health - 10);
						character.m_Position.x -= 75;
						character.m_Position.y -= 75;
						m_SoundManager.PlayOuch();
					}
					collidedWithBlock = true;
				}

				// Add or remove from list
				if (inImmuneList && !collidedWithBlock)
				{
					// Remove from list
					character.m_ImmuneBlocks.erase(itImmune);
				}
				else if (!inImmuneList && collidedWithBlock)
				{
					// Add to list
					character.m_ImmuneBlocks.push_back(blockCoords);
				}
			}

			  // Have we reached the goal?
			if (m_ArrayLevel[y][x] == 4 && character.m_Win == false)
			{
				// Character has reached the goal.
				if (m_LevelManager.GetCurrentLevel() != 3)
				{
					reachedGoal = true;
					m_SoundManager.playReachGoal();
				}

				if (m_LevelManager.GetCurrentLevel() == 3)
				{
					character.m_Win = true;
					m_SoundManager.playReachGoal();
					m_Playing = false;
				}
			}

			// More collisions here once we have learned about particle effects.

		} // End y loop.
	} // End x loop.


	  // Return weather or not our Character has completed this level.
	return reachedGoal;

} // End detectCollisions()