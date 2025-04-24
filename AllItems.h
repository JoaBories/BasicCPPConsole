#pragma once

#include "Heal.h"
#include "Pokeball.h"
#include <map>

using std::map;

class AllItems
{
private :
	map<string, Heal> mAllHeals;
	map<string, Pokeball> mAllPokeballs;

public :
	AllItems();
	~AllItems();

	static AllItems* instancePtr;
	static AllItems* Get();

	Heal* GetHealPtr(string name);
	Pokeball* GetPokeballPtr(string name);

};

