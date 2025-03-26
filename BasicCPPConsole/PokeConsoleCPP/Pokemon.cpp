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

	for (int i = 0; i < 4; i++)
	{
		mAbilities[i] = AllAbilities::Get()->GetAbilityPtr("Null");
	}
}

Pokemon::Pokemon(string name, int maxHp, int attack, int defense, int speed, Types types[2], string abilities[4]) :
	mName{ name },
	mMaxHp{ maxHp },
	mHp{ mMaxHp },
	mAttack{ attack },
	mDefense{ defense },
	mSpeed{ speed }
{
	mTypes[0] = AllPokeTypes::Get()->GetPokeTypePtr(types[0]);
	mTypes[1] = AllPokeTypes::Get()->GetPokeTypePtr(types[1]);

	for (int i = 0; i < 4; i++)
	{
		mAbilities[i] = AllAbilities::Get()->GetAbilityPtr(abilities[i]);
	}
}

Pokemon::~Pokemon()
{
}

void Pokemon::Display() const
{
	cout << mName << endl;
	cout << mHp << "/" << mMaxHp << " HP" << endl;
	cout << "Attack : " << mAttack << endl;
	cout << "Defense : " << mDefense << endl;
	cout << mTypes[0]->GetName() << " | " << mTypes[1]->GetName() << endl;
	cout << "Abilities : " << endl;
	for (int i = 0; i < 4; i++)
	{
		mAbilities[i]->Display();
	}
}
