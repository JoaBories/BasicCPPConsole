#pragma once

#include "Ability.h"
#include <map>

using std::map;

class AllAbilities
{
private:
	map<string, Ability> mAllAbilities;

public:
	AllAbilities();
	~AllAbilities();

	static AllAbilities* instancePtr;
	static AllAbilities* Get();

	Ability* GetAbilityPtr(string name);
};

