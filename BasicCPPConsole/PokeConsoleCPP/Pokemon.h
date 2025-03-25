#pragma once

#include "AllPokeTypes.h"
#include "AllAbilities.h"

class Pokemon
{
private :
	string mName;
	int mMaxHp;
	int mHp;
	int mAttack;
	int mDefense;
	int mSpeed;
	Ability *mAbilities[4];
	PokeType *mTypes[2];

public:
	Pokemon();
	Pokemon(string name, int maxHp, int attack, int defense, int speed,Types types[2], string abilities[4]);
	~Pokemon();
	void DisplayInfos();

};

