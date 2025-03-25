#pragma once

#include "AllPokeTypes.h"
#include <string>

#include <iostream>

using std::cout;
using std::endl;

using std::string;

enum class Stats
{
	Null,
	Attack,
	Defense,
	Speed
};

class Ability
{
private:
	string mName;
	PokeType *mType;
	string mCategory;

	int mPower;
	int mAccuracy;

	Stats mStatToChange;
	int mAmountToChange;
	bool mApplyOnMyself;

public:
	Ability();
	Ability(string name, Types type, int power, int accuracy);
	Ability(string name, Types type, Stats statToChange, int amountToChange, bool applyOnMyself);
	Ability(string name, Types type, string category, int power, int accuracy, Stats statToChange, int amountToChange, bool applyOnMyself);

	~Ability();

	string GetName();
	string GetCategory();
	int GetPower();
	int GetAccuracy();
	Stats GetStatToChange();
	int GetAmountToChange();
	bool GetApplyOnMyself();

	void InfoAbility();

};

