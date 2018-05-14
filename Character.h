#pragma once
#include "PlayableCharacter.h"

class SoundManager;

class Character : public PlayableCharacter
{
public:

	Character();

	bool virtual handleInput();

	void SetSoundManager(SoundManager* _SoundManager);

private:
	// Pointers to managers
	SoundManager* m_SoundManager;

};

