#pragma once

#include "AllPokeTypes.h"
#include <string>

#include "IDisplayable.h"

using std::string;

enum class Stats
{
	Null,
	Attack,
	Defense,
	Speed
};

class Ability : public IDisplayable
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

	string GetName() const ;
	string GetCategory() const ;
	int GetPower() const ;
	int GetAccuracy() const ;
	Stats GetStatToChange() const ;
	int GetAmountToChange() const ;
	bool GetApplyOnMyself() const ;

	// Inherited via IDisplayable
	void Display() const override;

};

