#include "Ability.h"
#include <iostream>

using std::cout;
using std::endl;

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

void Ability::DisplayShort() const
{
	cout << "[" << mName << " / " << mType->GetName() << "] ";
}

void Ability::DisplayAll() const
{
	cout << "Ability: " << mName << " | ";
	cout << "Type: " << mType->GetName() << " | ";
	cout << "Power: " << mPower << " | ";
	cout << "Accuracy: " << mAccuracy << " | ";
}
