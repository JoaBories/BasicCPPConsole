#include "Ability.h"

Ability::Ability() :
	mName{ "" },
	mCategory{ "Null" },
	mPower{ 0 },
	mAccuracy{ 0 },
	mStatToChange{ Stats::Null },
	mAmountToChange{ 0 },
	mApplyOnMyself{ false }
{
	mType = AllPokeTypes::Get()->GetPokeTypePtr(Types::Null);
}

Ability::Ability(string name, Types type, int power, int accuracy) : 
	mName{ name },
	mCategory{ "Physical" },
	mPower{ power },
	mAccuracy{ accuracy },
	mStatToChange{ Stats::Null },
	mAmountToChange{ 0 },
	mApplyOnMyself{ false }
{
	mType = AllPokeTypes::Get()->GetPokeTypePtr(type);
}

Ability::Ability(string name, Types type, Stats statToChange, int amountToChange, bool applyOnMyself) :
	mName{ name },
	mCategory{ "Status"},
	mPower{ 0 },
	mAccuracy{ 0 },
	mStatToChange{ statToChange },
	mAmountToChange{ amountToChange },
	mApplyOnMyself{ applyOnMyself }
{
	mType = AllPokeTypes::Get()->GetPokeTypePtr(type);
}

Ability::Ability( string name, Types type, string category, int power, int accuracy, Stats statToChange, int amountToChange, bool applyOnMyself ) :
	mName{ name },
	mCategory{ category },
	mPower{ power },
	mAccuracy{ accuracy },
	mStatToChange{ statToChange },
	mAmountToChange{ amountToChange },
	mApplyOnMyself{ applyOnMyself }
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

string Ability::GetCategory() const
{
	return mCategory;
}

int Ability::GetPower() const
{
	return mPower;
}

int Ability::GetAccuracy() const
{
	return mAccuracy;
}

Stats Ability::GetStatToChange() const
{
	return mStatToChange;
}

int Ability::GetAmountToChange() const
{
	return mAmountToChange;
}

bool Ability::GetApplyOnMyself() const
{
	return mApplyOnMyself;
}

void Ability::Display() const
{
	cout << mName << " | " << mType->GetName() << " | " << mCategory << endl;
}
