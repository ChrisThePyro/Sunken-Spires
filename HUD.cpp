#include "stdafx.h"
#include "HUD.h"
#include "PlayableCharacter.h"

// =====================================================================

Hud::Hud()
{

	Vector2f resolution;
	resolution.x = VideoMode::getDesktopMode().width;
	resolution.y = VideoMode::getDesktopMode().height;

	// Load the font
	m_Font.loadFromFile("fonts/Roboto-Light.ttf");

	// when Paused
	m_StartText.setFont(m_Font);
	m_StartText.setCharacterSize(50);
	m_StartText.setFillColor(Color::White);
	m_StartText.setString("Welcome to Sunken Spires! Press Enter to start!");

	// Position text
	FloatRect textRect = m_StartText.getLocalBounds();

	m_StartText.setOrigin(textRect.left + textRect.width / 2.0f,
		textRect.top + textRect.height / 2.0f);

	m_StartText.setPosition(resolution.x / 2.0f, resolution.y / 2.0f);

	// Time
	m_TimeText.setFont(m_Font);
	m_TimeText.setCharacterSize(25);
	m_TimeText.setFillColor(Color::White);
	m_TimeText.setPosition(resolution.x - 150, 0);
	m_TimeText.setString("-----");

	// Level
	m_LevelText.setFont(m_Font);
	m_LevelText.setCharacterSize(25);
	m_LevelText.setFillColor(Color::White);
	m_LevelText.setPosition(25, 0);
	m_LevelText.setString("1");

	m_LivesText.setFont(m_Font);
	m_LivesText.setCharacterSize(25);
	m_LivesText.setFillColor(Color::White);
	m_LivesText.setPosition(25, 25);
	m_LivesText.setString("Lives");

} // end function Hud()

  // =====================================================================

Text Hud::getMessage()
{

	return m_StartText;

} // end function getMessage()

  // =====================================================================

Text Hud::getLevel()
{

	return m_LevelText;

} // end function getLevel()

  // =====================================================================

Text Hud::getTime()
{

	return m_TimeText;

} // end function getTime()

  // =====================================================================

void Hud::setLevel(String text)
{

	m_LevelText.setString(text);

} // end function setLevel()

  // =====================================================================

void Hud::setTime(String text)
{

	m_TimeText.setString(text);

} // end function setTime()

  // =====================================================================