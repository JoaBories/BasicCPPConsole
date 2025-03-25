#pragma once

#include "AllPokeTypes.h"
#include "Ability.h"

class Pokemon
{
private :
	string mName;
	int mMaxHp;
	int mHp;
	int mAttack;
	int mDefense;
	int mSpeed;
	//Ability mAbilities[4];
	PokeType* mTypes[2];
	//PokeType *mFirstType;
	//PokeType *mSecondType;

public:
	Pokemon();
	Pokemon(string name, int maxHp, int attack, int defense, int speed,Types type1, Types type2);
	~Pokemon();
	void DisplayInfos();

};

