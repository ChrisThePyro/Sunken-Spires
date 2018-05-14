#pragma once
#include <SFML/Graphics.hpp>

class PlayableCharacter
{
protected:
	// Floats, sprites and booleans.
	sf::Sprite m_Sprite;
	float m_JumpDuration;
	bool m_IsJumping;
	bool m_IsFalling;
	bool m_LeftPressed;
	bool m_RightPressed;
	float m_TimeThisJump;
	bool m_JustJumped = false;

private:

	// Gravity, speed and positions.
	float m_Gravity;
	float m_Speed = 400;

	// Player bounding.
	sf::FloatRect m_Feet;
	sf::FloatRect m_Head;
	sf::FloatRect m_Right;
	sf::FloatRect m_Left;

	// Player Texture.
	sf::Texture m_Texture;

public:

	sf::Vector2f m_Position;

	void setValues();
	void spawn(sf::Vector2f startPosition, float gravity);
	void respawn(sf::Vector2f startPosition, float gravity);
	bool virtual handleInput() = 0;
	std::vector<sf::Vector2i> m_ImmuneBlocks;
	bool m_Win = false;

	int m_Health;
	int m_Lives;

	PlayableCharacter();

	sf::FloatRect getPosition();

	sf::FloatRect getFeet();
	sf::FloatRect getHead();
	sf::FloatRect getRight();
	sf::FloatRect getLeft();

	sf::Sprite getSprite();

	void stopFalling(float position);
	void stopRight(float position);
	void stopLeft(float position);
	void stopJump();
	int getHealth();
	int getLives();
	sf::Vector2f getCentre();

	void update(float elapsedTime);
};
