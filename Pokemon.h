#pragma once

#include "AllPokeTypes.h"
#include "AllAbilities.h"
#include "AllItems.h"
#include "raylib.h"

class Pokemon
{
private:
	string mName;
	int mMaxHp;
	int mHp;
	int mAttack;
	int mDefense;
	int mSpeed;
	Ability *mAbilities[2];
	PokeType *mTypes[2];

	//Texture LoadTextureFromSource();

public:
	Pokemon();
	Pokemon(string name, int maxHp, int attack, int defense, int speed,Types types[2], string abilities[2]);
	~Pokemon();

	Ability* GetAbilityPtrByIndex(int index) const;
	PokeType* GetTypePtrByIndex(int index) const;

	int GetDefense() const;
	int GetSpeed() const;
	string GetName() const;
	int GetHp() const;
	int GetMaxHp() const;

	bool isAlive() const;

	int Attack(int abilityIndex, Pokemon* target, int randomInt);
	void HealMe(Heal* heal);
	void TakeDamage(int damage);

	//void DisplayShort() const;
	//void DisplayLarge() const;
	//void DisplayAll() const;

};

