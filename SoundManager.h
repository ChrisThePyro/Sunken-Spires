#pragma once
#include <SFML/Audio.hpp>

class SoundManager
{

private:
	// Seting up sound buffers.
	sf::SoundBuffer m_FallInWaterBuffer;
	sf::SoundBuffer m_JumpBuffer;
	sf::SoundBuffer m_ReachGoalBuffer;
	sf::SoundBuffer m_WalkingBuffer;
	sf::SoundBuffer m_WavesBuffer;
	sf::SoundBuffer m_OuchBuffer;

	// Setting up sounds.
	sf::Sound m_FallInWaterSound;
	sf::Sound m_JumpSound;
	sf::Sound m_ReachGoalSound;
	sf::Sound m_WalkingSound;
	sf::Sound m_WavesSound;
	sf::Sound m_OuchSound;



public:
	SoundManager();

	// Setting up sound functions.
	void playFallInWater();
	void playJump();
	void playReachGoal();
	void playWalking();
	void stopWalking();
	void PlayWaves();
	void PlayOuch();
};