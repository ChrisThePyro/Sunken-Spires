#pragma once
#include <SFML/Graphics.hpp>
#include "LevelManager.h"
#include "TextureHolder.h"
#include "Character.h"
#include "SoundManager.h"
#include "HUD.h"

class Engine
{

private:

	TextureHolder TextureHolder;

	Character m_Character;

	LevelManager m_LevelManager;
	SoundManager m_SoundManager;

	Hud m_Hud;
	int m_FramesSinceLastHUDUpdate = 0;
	int m_TargetFramesPerHUDUpdate = 500;

	const int TILE_SIZE = 50;
	const int VERTS_IN_QUAD = 4;
	const int GRAVITY = 300;

	sf::RenderWindow m_RenderWindow;

	sf::View m_MainView;
	sf::View m_HudView;
	sf::View m_BGMainView;

	sf::Sprite m_BackgroundSprite;
	sf::Texture m_BackgroundTexture;

	bool m_Playing = false;

	float m_TimeRemaining = 0;
	sf::Time m_GameTimeTotal;

	bool m_NewLevel = true;

	sf::VertexArray m_VALevel;

	int** m_ArrayLevel = NULL;

	sf::Texture m_TextureTiles;

private:
	void input();
	void update(float dtAsSeconds);
	void draw();

	void loadLevel();

	// Detect collisions.
	bool detectCollisions(PlayableCharacter& Character);

public:

	Engine();

	void run();
};