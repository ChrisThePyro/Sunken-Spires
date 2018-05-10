#include "stdafx.h"
#include "Engine.h"
#include <SFML/Graphics.hpp>
#include "sstream"

using namespace sf;
using namespace std;

void Engine::update(float dtAsSeconds)
{

	if (m_NewLevel)
	{
		loadLevel();
	}

	if (m_Playing)
	{

		// Update Thomas and Bob
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
			m_NewLevel = true;
		}

		m_MainView.setCenter(m_Character.getCentre());

	}// End of if playing.

	m_FramesSinceLastHUDUpdate++;

	// Update the HUD every m_TargetFramesPerHUDUpdate frames
	if (m_FramesSinceLastHUDUpdate > m_TargetFramesPerHUDUpdate)
	{

		// Update the HUD text
		stringstream ssTime;
		stringstream ssLevel;

		// Update the time text
		ssTime << (int)m_TimeRemaining;
		m_Hud.setTime(ssTime.str());

		// Update the level text
		ssLevel << "Level: " << m_LevelManager.GetCurrentLevel();
		m_Hud.setLevel(ssLevel.str());

		// zero our frames since last update, since we just updated
		m_FramesSinceLastHUDUpdate = 0;

	} // end if (time to update hud)

}