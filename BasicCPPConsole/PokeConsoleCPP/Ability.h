#pragma once

#include "AllPokeTypes.h"
#include <string>

using std::string;

class Ability
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

	void DisplayShort() const;
	void DisplayAll() const;

};

