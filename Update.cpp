#include "stdafx.h"
#include "Engine.h"
#include <SFML/Graphics.hpp>
#include "PlayableCharacter.h"
#include "SoundManager.h"
#include "sstream"

using namespace sf;
using namespace std;

void Engine::update(float dtAsSeconds, PlayableCharacter& character)
{

	if (m_NewLevel)
	{
		loadLevel();
	}

	if (m_Playing)
	{

		// Update's player.
		m_Character.update(dtAsSeconds);

		if (detectCollisions(m_Character))
		{
			// New level required.
			m_NewLevel = true;
		}

		// Count down the time the player has left.
		m_TimeRemaining -= dtAsSeconds;

		// Have Thomas and Bob run out of time?
		if (m_TimeRemaining <= 0)
		{
			character.m_Lives = 0;
		}

		m_MainView.setCenter(m_Character.getCentre());

		if (character.m_Health == 0)
		{
			character.respawn(m_LevelManager.getStartPosition(), GRAVITY);
			character.m_Lives -= 1;
		}
	}// End of if playing.

	m_FramesSinceLastHUDUpdate++;

	// Update the HUD every m_TargetFramesPerHUDUpdate frames
	if (m_FramesSinceLastHUDUpdate > m_TargetFramesPerHUDUpdate)
	{

		// Update the HUD text
		stringstream ssTime;
		stringstream ssLevel;
		stringstream ssHealth;
		stringstream ssLives;

		// Update the time text
		ssTime << (int)m_TimeRemaining;
		m_Hud.setTime(ssTime.str());

		// Update the level text
		ssLevel << "Level: " << m_LevelManager.GetCurrentLevel();
		m_Hud.setLevel(ssLevel.str());

		ssHealth << "Health: " << m_Character.getHealth();
		m_Hud.setHealth(ssHealth.str());

		ssLives << "Lives: " << m_Character.getLives();
		m_Hud.setLives(ssLives.str());

		// zero our frames since last update, since we just updated
		m_FramesSinceLastHUDUpdate = 0;

	} // end if (time to update hud)

	if (character.m_Lives == 0)
	{
		m_Playing = false;
	}

}