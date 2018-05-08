#pragma once
#include "PlayableCharacter.h"

class Character : public PlayableCharacter
{
public:

	Character();

	bool virtual handleInput();

};

