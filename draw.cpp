#include "stdafx.h"
#include "Engine.h"

void Engine::draw()
{
	// Erase the last frame.
	m_RenderWindow.clear(sf::Color::Blue);

	// Switch to the background view
	m_RenderWindow.setView(m_MainView);

	// Draw the background.
	m_RenderWindow.draw(m_BackgroundSprite);

	// switch to main view
	m_RenderWindow.setView(m_MainView);

	// Draw the level
	m_RenderWindow.draw(m_VALevel, &m_TextureTiles);

	// Draw Thomas and Bob.
	m_RenderWindow.draw(m_Character.getSprite());

	// Draw the HUD
	m_RenderWindow.setView(m_HudView);
	m_RenderWindow.draw(m_Hud.getLevel());
	m_RenderWindow.draw(m_Hud.getTime());

	if (!m_Playing)
	{
		m_RenderWindow.draw(m_Hud.getMessage());
	}

	// Show everything we have just drawn.
	m_RenderWindow.display();

}// End of draw function.