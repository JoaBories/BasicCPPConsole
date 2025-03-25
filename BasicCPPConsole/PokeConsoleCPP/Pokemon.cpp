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
}

Pokemon::Pokemon(string name, int maxHp, int attack, int defense, int speed, Types type1, Types type2) :
	mName{ name },
	mMaxHp{ maxHp },
	mHp{ mMaxHp },
	mAttack{ attack },
	mDefense{ defense },
	mSpeed{ speed }
{
	mTypes[0] = AllPokeTypes::Get()->GetPokeTypePtr(type1);
	mTypes[1] = AllPokeTypes::Get()->GetPokeTypePtr(type2);
}

Pokemon::~Pokemon()
{
}

void Pokemon::DisplayInfos()
{
	cout << mName << endl;
	cout << mHp << "/" << mMaxHp << " HP" << endl;
	cout << "Attack : " << mAttack << endl;
	cout << "Defense : " << mDefense << endl;
	cout << mTypes[0]->GetName() << " | " << mTypes[1]->GetName() << endl;
}
