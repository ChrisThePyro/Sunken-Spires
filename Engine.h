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

	// Sets up texture holder.
	TextureHolder TextureHolder;

	// Sets up character.
	Character m_Character;

	// Sets up Level and Sound manager.
	LevelManager m_LevelManager;
	SoundManager m_SoundManager;

	// Sets up HUD.
	Hud m_Hud;
	int m_FramesSinceLastHUDUpdate = 0;
	int m_TargetFramesPerHUDUpdate = 500;

	// Set up world data.
	const int TILE_SIZE = 50;
	const int VERTS_IN_QUAD = 4;
	const int GRAVITY = 300;

	// Sets up Renderwinodw, views and backgrounds.
	sf::RenderWindow m_RenderWindow;

	sf::View m_MainView;
	sf::View m_HudView;
	sf::View m_BGMainView;

	sf::Sprite m_BackgroundSprite;
	sf::Texture m_BackgroundTexture;

	// Sets playing boolean to false.
	bool m_Playing = false;

	// Sets up game time.
	float m_TimeRemaining = 0;
	sf::Time m_GameTimeTotal;

	// Sets up level.
	bool m_NewLevel = true;

	sf::VertexArray m_VALevel;

	int** m_ArrayLevel = NULL;

	sf::Texture m_TextureTiles;

private:
	// Sets up void functions.
	void input();
	void update(float dtAsSeconds, PlayableCharacter& character);
	void draw(PlayableCharacter& character);

	void loadLevel();

	// Detect collisions.
	bool detectCollisions(PlayableCharacter& Character);

public:

	Engine();

	void run();
};