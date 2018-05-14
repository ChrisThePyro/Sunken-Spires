#include "stdafx.h"
#include "SoundManager.h"
#include <SFML/Audio.hpp>

using namespace sf;

SoundManager::SoundManager()
{
	// Load the sound in to buffers from file.
	m_FallInWaterBuffer.loadFromFile("sound/fallinwater.wav");
	m_JumpBuffer.loadFromFile("sound/jump.wav");
	m_ReachGoalBuffer.loadFromFile("sound/door.wav");
	m_WalkingBuffer.loadFromFile("sound/footsteps.wav");
	m_WavesBuffer.loadFromFile("sound/waves.wav");
	m_OuchBuffer.loadFromFile("sound/ouch.wav");

	// Associate the sounds with the buffers.
	m_FallInWaterSound.setBuffer(m_FallInWaterBuffer);
	m_JumpSound.setBuffer(m_JumpBuffer);
	m_ReachGoalSound.setBuffer(m_ReachGoalBuffer);
	m_WalkingSound.setBuffer(m_WalkingBuffer);
	m_WavesSound.setBuffer(m_WavesBuffer);
	m_OuchSound.setBuffer(m_OuchBuffer);

} // End SoundManager() constructor.

void SoundManager::playFallInWater()
{
	m_FallInWaterSound.setRelativeToListener(true);
	m_FallInWaterSound.play();
}

void SoundManager::playJump()
{
	m_JumpSound.setRelativeToListener(true);
	m_JumpSound.play();
}

void SoundManager::playReachGoal()
{
	m_ReachGoalSound.setRelativeToListener(true);
	m_ReachGoalSound.play();
}

void SoundManager::playWalking()
{
	m_WalkingSound.setRelativeToListener(true);
	if (m_WalkingSound.getStatus() != sf::SoundSource::Playing)
	{
		m_WalkingSound.play();
	}
}

void SoundManager::stopWalking()
{
	m_WalkingSound.stop();
}

void SoundManager::PlayWaves()
{
	m_WavesSound.play();
}

void SoundManager::PlayOuch()
{
	m_OuchSound.play();
}
