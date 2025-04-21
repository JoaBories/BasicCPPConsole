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

Ability* Pokemon::GetAbilityPtrByIndex(int index)
{
	return mAbilities[index];
}

PokeType* Pokemon::GetTypePtrByIndex(int index)
{
	return mTypes[index];
}

int Pokemon::GetDefense() const
{
	return mDefense;
}

void Pokemon::Attack(Ability* ability, Pokemon* target)
{
	Types abilityType = Types::Null;
	abilityType = ability->GetTypePtr()->GetType();

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

	int damage = ((14 * ability->GetPower() * attackDef) / 50 + 2) * stab * weak;

	target->TakeDamage(damage);
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

void Pokemon::Display(bool isShort) const
{
	if (isShort)
	{
		string typesString = "";
		typesString += (mTypes[0]->GetName() != "Null") ? mTypes[0]->GetName() : "";
		typesString += (typesString == "" && mTypes[1]->GetName() != "Null") ? mTypes[1]->GetName() : (mTypes[1]->GetName() != "Null") ? "-" + mTypes[1]->GetName() : "";
		string abilityShortString = "";
		for (int i = 0; i < 2; i++)
		{
			abilityShortString += (mAbilities[i]->GetName() != "Null") ? "0" : ".";
		}

		cout << mName << " | " << mHp << "/" << mMaxHp << " HP | " << typesString << " | " << abilityShortString << endl;
	}
	else
	{
		cout << mName << endl;
		cout << mHp << "/" << mMaxHp << " HP" << endl;
		cout << "Attack : " << mAttack << endl;
		cout << "Defense : " << mDefense << endl;
		cout << mTypes[0]->GetName() << " | " << mTypes[1]->GetName() << endl;
		cout << "Abilities : " << endl;
		for (int i = 0; i < 2; i++)
		{
			if (mAbilities[i]->GetName() != "Null")
			{
				mAbilities[i]->Display(true);
			}
		}
	}
}
