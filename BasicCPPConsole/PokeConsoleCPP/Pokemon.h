#pragma once

#include "AllPokeTypes.h"
#include "AllAbilities.h"
#include "AllItems.h"

class Pokemon : public IDisplayable
{
private:
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

	Ability* GetAbilityPtrByIndex(int index);
	PokeType* GetTypePtrByIndex(int index);

	int GetDefense() const;

	void Attack(Ability* ability, Pokemon* target);
	void HealMe(Heal* heal);
	void TakeDamage(int damage);

	// Inherited via IDisplayable
	void Display(bool isShort) const override;

};

