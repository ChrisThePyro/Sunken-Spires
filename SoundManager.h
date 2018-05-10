#pragma once
#include <SFML/Audio.hpp>

class SoundManager
{

private:
	sf::SoundBuffer m_FallInWaterBuffer;
	sf::SoundBuffer m_JumpBuffer;
	sf::SoundBuffer m_ReachGoalBuffer;

	sf::Sound m_FallInWaterSound;
	sf::Sound m_JumpSound;
	sf::Sound m_ReachGoalSound;

public:
	SoundManager();

	void playFallInWater();
	void playJump();
	void playReachGoal();
};