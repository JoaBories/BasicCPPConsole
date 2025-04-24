#pragma once

#include "PokeType.h"
#include <map>

using std::map;

class AllPokeTypes
{
private :
	map<Types, PokeType> mAllPokeTypes;
	
public :
	AllPokeTypes();
	~AllPokeTypes();

	static AllPokeTypes* instancePtr;
	static AllPokeTypes* Get();

	PokeType* GetPokeTypePtr(Types type);

};

