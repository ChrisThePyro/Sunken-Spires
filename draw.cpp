#include "stdafx.h"
#include "Engine.h"
#include "LevelManager.h"
#include "PlayableCharacter.h"

void Engine::draw(PlayableCharacter& character)
{
	// Erase the last frame.
	m_RenderWindow.clear(sf::Color::Blue);

	if (m_Playing && character.m_Lives != 0 && character.m_Win == false)
	{
		// Switch to the background view
		m_RenderWindow.setView(m_MainView);

		// Draw the background.
		m_RenderWindow.draw(m_BackgroundSprite);

		// switch to main view
		m_RenderWindow.setView(m_MainView);

		// Draw the level
		m_RenderWindow.draw(m_VALevel, &m_TextureTiles);

		// Draw the player.
		m_RenderWindow.draw(m_Character.getSprite());

		// Draw the HUD
		m_RenderWindow.setView(m_HudView);
		m_RenderWindow.draw(m_Hud.getLevel());
		m_RenderWindow.draw(m_Hud.getTime());
		m_RenderWindow.draw(m_Hud.getLives());
		m_RenderWindow.draw(m_Hud.getHealth());
	}

	if (!m_Playing && character.m_Lives != 0 && character.m_Win == false)
	{
		m_RenderWindow.draw(m_Hud.getMessage());
	}

	if (character.m_Lives == 0 && character.m_Win != true)
	{
		m_RenderWindow.draw(m_Hud.getGameoverMessage());
	}

	if (character.m_Win == true && character.m_Lives != 0)
	{
		m_RenderWindow.draw(m_Hud.getWinMessage());
	}

	// Show everything we have just drawn.
	m_RenderWindow.display();

}// End of draw function.