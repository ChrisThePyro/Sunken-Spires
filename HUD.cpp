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

	m_GameoverText.setFont(m_Font);
	m_GameoverText.setCharacterSize(50);
	m_GameoverText.setFillColor(Color::White);
	m_GameoverText.setString("GAME OVER!");

	m_WinText.setFont(m_Font);
	m_WinText.setCharacterSize(50);
	m_WinText.setFillColor(Color::White);
	m_WinText.setString("PLAYER WINS!");

	// Position text
	FloatRect textRect = m_StartText.getLocalBounds();

	m_StartText.setOrigin(textRect.left + textRect.width / 2.0f,
		textRect.top + textRect.height / 2.0f);

	m_StartText.setPosition(resolution.x / 2.0f, resolution.y / 2.0f);

	FloatRect GameoverTextRect = m_GameoverText.getLocalBounds();

	m_GameoverText.setOrigin(GameoverTextRect.left + GameoverTextRect.width / 2.0f,
		GameoverTextRect.top + GameoverTextRect.height / 2.0f);

	m_GameoverText.setPosition(resolution.x / 2.0f, resolution.y / 4);

	FloatRect WinTextRect = m_WinText.getLocalBounds();

	m_WinText.setOrigin(WinTextRect.left + WinTextRect.width / 2.0f,
		WinTextRect.top + WinTextRect.height / 2.0f);

	m_WinText.setPosition(resolution.x / 2.0f, resolution.y / 4);

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

	m_HealthText.setFont(m_Font);
	m_HealthText.setCharacterSize(25);
	m_HealthText.setFillColor(Color::White);
	m_HealthText.setPosition(25, 50);
	m_HealthText.setString("Health");

} // end function Hud()

  // =====================================================================

Text Hud::getMessage()
{

	return m_StartText;

} // end function getMessage()

  // =====================================================================

Text Hud::getGameoverMessage()
{

	return m_GameoverText;

} // end function getMessage()

  // =====================================================================

Text Hud::getWinMessage()
{

	return m_WinText;

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

Text Hud::getHealth()
{

	return m_HealthText;

} // end function setTime()

  // =====================================================================

Text Hud::getLives()
{

	return m_LivesText;

} // end function setTime()

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

void Hud::setHealth(String text)
{

	m_HealthText.setString(text);

} // end function setLevel()

  // =====================================================================

void Hud::setLives(String text)
{

	m_LivesText.setString(text);

} // end function setTime()

  // =====================================================================