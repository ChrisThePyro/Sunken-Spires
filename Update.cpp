#include "stdafx.h"
#include "Engine.h"
#include <SFML/Graphics.hpp>
#include <sstream>

using namespace sf;

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

}