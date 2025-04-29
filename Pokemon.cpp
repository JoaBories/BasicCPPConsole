#include "Pokemon.h"
#include <iostream>

using std::cout;
using std::endl;

Pokemon::Pokemon() :
	mName{ "" },
	mMaxHp{ 0 },
	mHp{ 0 },
	mAttack{ 0 },
	mDefense{ 0 },
	mSpeed{ 0 }
{
	mTypes[0] = AllPokeTypes::Get()->GetPokeTypePtr(Types::Null);
	mTypes[1] = AllPokeTypes::Get()->GetPokeTypePtr(Types::Null);

	mAbilities[0] = AllAbilities::Get()->GetAbilityPtr("Null");
	mAbilities[1] = AllAbilities::Get()->GetAbilityPtr("Null");
}

Pokemon::Pokemon(string name, int maxHp, int attack, int defense, int speed, Types types[2], string abilities[2]) :
	mName{ name },
	mMaxHp{ maxHp },
	mHp{ mMaxHp },
	mAttack{ attack },
	mDefense{ defense },
	mSpeed{ speed }
{
	mTypes[0] = AllPokeTypes::Get()->GetPokeTypePtr(types[0]);
	mTypes[1] = AllPokeTypes::Get()->GetPokeTypePtr(types[1]);

	mAbilities[0] = AllAbilities::Get()->GetAbilityPtr(abilities[0]);
	mAbilities[1] = AllAbilities::Get()->GetAbilityPtr(abilities[1]);
}

Pokemon::~Pokemon()
{
}

Ability* Pokemon::GetAbilityPtrByIndex(int index) const
{
	return mAbilities[index];
}

PokeType* Pokemon::GetTypePtrByIndex(int index) const
{
	return mTypes[index];
}

int Pokemon::GetDefense() const
{
	return mDefense;
}

int Pokemon::GetSpeed() const
{
	return mSpeed;
}

string Pokemon::GetName() const
{
	return mName;
}

int Pokemon::GetHp() const
{
	return mHp;
}

int Pokemon::GetMaxHp() const
{
	return mMaxHp;
}

bool Pokemon::isAlive() const
{
	return (mHp > 0);
}

int Pokemon::Attack(int abilityIndex, Pokemon* target, int randomInt)
{
	if (randomInt > mAbilities[abilityIndex]->GetAccuracy())
	{
		return 0;
	}

	Types abilityType = Types::Null;
	abilityType = mAbilities[abilityIndex]->GetTypePtr()->GetType();

	float defense = target->GetDefense();
	float attackDef = mAttack / defense;

	float stab = ((abilityType == mTypes[0]->GetType()) || (abilityType == mTypes[1]->GetType())) ? 1.5f : 1;
	float weak = 1;

	PokeType* targetType1 = target->GetTypePtrByIndex(0);
	PokeType* targetType2 = target->GetTypePtrByIndex(1);

	vector<Types> weakness;
	weakness = targetType1->GetWeakNess();
	for (Types weakn : targetType2->GetWeakNess())
	{
		weakness.push_back(weakn);
	}
	vector<Types> resistance;
	resistance = targetType1->GetResistance();
	for (Types res : targetType2->GetResistance())
	{
		weakness.push_back(res);
	}

	for (Types weakn : weakness)
	{
		weak *= (weakn == abilityType) ? 2 : 1;
	}
	for (Types res : resistance)
	{
		weak *= (res == abilityType) ? 0.5f : 1;
	}

	int damage = ((5 * mAbilities[abilityIndex]->GetPower() * attackDef) / 50 + 2) * stab * weak;

	target->TakeDamage(damage);

	return weak;
}

void Pokemon::HealMe(Heal* heal)
{
	mHp += heal->GetAmount();
	mHp = (mHp >= mMaxHp) ? mMaxHp : mHp;
}

void Pokemon::TakeDamage(int damage)
{
	mHp -= damage;
	mHp = mHp <= 0 ? 0 : mHp;
}
