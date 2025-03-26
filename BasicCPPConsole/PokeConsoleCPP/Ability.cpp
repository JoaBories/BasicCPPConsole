#include "Ability.h"

Ability::Ability() :
	mName{ "Null" },
	mPower{ 0 },
	mAccuracy{ 0 }
{
	mType = AllPokeTypes::Get()->GetPokeTypePtr(Types::Null);
}

Ability::Ability(string name, Types type, int power, int accuracy) : 
	mName{ name },
	mPower{ power },
	mAccuracy{ accuracy }
{
	mType = AllPokeTypes::Get()->GetPokeTypePtr(type);
}

Ability::~Ability()
{
}

string Ability::GetName() const
{
	return mName;
}

PokeType* Ability::GetTypePtr()
{
	return mType;
}

int Ability::GetPower() const
{
	return mPower;
}

int Ability::GetAccuracy() const
{
	return mAccuracy;
}

void Ability::Display(bool isShort) const
{
	cout << mName << " | " << mType->GetName() << endl;
}
