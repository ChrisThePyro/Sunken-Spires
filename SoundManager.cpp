#include "stdafx.h"
#include "SoundManager.h"
#include <SFML/Audio.hpp>

using namespace sf;

SoundManager::SoundManager()
{
	// Load the sound in to buffers from file.
	m_FallInWaterBuffer.loadFromFile("sound/fallinwater.wav");
	m_JumpBuffer.loadFromFile("sound/jump.wav");
	m_ReachGoalBuffer.loadFromFile("sound/reachgoal.wav");

	// Associate the sounds with the buffers.
	m_FallInWaterSound.setBuffer(m_FallInWaterBuffer);
	m_JumpSound.setBuffer(m_JumpBuffer);
	m_ReachGoalSound.setBuffer(m_ReachGoalBuffer);

	// When the player is 50 pixels away or cloaser, the sound is at full volume.
	float minDistance = 150;

	// The sound reduces steadily as the player moves further away.
	float attenuation = 15;

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