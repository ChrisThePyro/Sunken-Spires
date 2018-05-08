#include "stdafx.h"
#include "Engine.h"

using namespace sf;

void Engine::input()
{
	Event event;
	while (m_RenderWindow.pollEvent(event))
	{
		if (event.type == Event::KeyPressed)
		{
			// Handle the player quitting.
			if (Keyboard::isKeyPressed(Keyboard::Escape))
			{
				m_RenderWindow.close();
			}

			// Handle the player starting the game.
			if (Keyboard::isKeyPressed(Keyboard::Return))
			{
				m_Playing = true;
			}
		}

		if (m_Character.handleInput())
		{
		}
	}
}