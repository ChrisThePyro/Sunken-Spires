#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Hud
{

private:
	// HUD text / font members.
	Font m_Font;
	Text m_StartText;
	Text m_GameoverText;
	Text m_WinText;
	Text m_TimeText;
	Text m_LevelText;
	Text m_LivesText;
	Text m_ScoreText;
	Text m_HealthText;

public:
	// HUD functions.
	Hud();
	Text getMessage();
	Text getGameoverMessage();
	Text getWinMessage();
	Text getLevel();
	Text getTime();
	Text getLives();
	Text getHealth();

	// HUD voids / returns.
	void setLevel(String text);
	void setTime(String text);
	void setLives(String text);
	void setHealth(String text);

}; // end class Hud#pragma once.
