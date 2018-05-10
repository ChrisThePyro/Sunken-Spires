#include "stdafx.h"
#include "Engine.h"

using namespace sf;

Engine::Engine()
{

	Vector2f resolution;
	resolution.x = VideoMode::getDesktopMode().width;
	resolution.y = VideoMode::getDesktopMode().height;

	m_RenderWindow.create(VideoMode(resolution.x, resolution.y), "Sunken Spires", Style::Titlebar);

	m_MainView.setSize(resolution.x/2, resolution.y/2);
	m_HudView.reset(FloatRect(0, 0, resolution.x, resolution.y));

	m_BackgroundTexture = TextureHolder::GetTexture("graphics/background.png");
	m_BackgroundSprite.setTexture(m_BackgroundTexture);
	m_TextureTiles = TextureHolder::GetTexture("graphics/tiles_sheet.png");
}

void Engine::run()
{
	Clock clock;

	while (m_RenderWindow.isOpen())
	{
		Time dt = clock.restart();
		m_GameTimeTotal += dt;
		float dtAsSeconds = dt.asSeconds();

		input();
		update(dtAsSeconds);
		draw();
	}
}