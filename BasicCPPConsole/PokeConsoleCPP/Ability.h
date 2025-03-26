#pragma once

#include "AllPokeTypes.h"
#include <string>

#include "IDisplayable.h"

using std::string;

class Ability : public IDisplayable
{
private:
	string mName;
	PokeType *mType;

	int mPower;
	int mAccuracy;

public:
	Ability();
	Ability(string name, Types type, int power, int accuracy);

	~Ability();

	string GetName() const ;
	PokeType* GetTypePtr();
	int GetPower() const ;
	int GetAccuracy() const ;

	// Inherited via IDisplayable
	void Display(bool isShort) const override;

};

