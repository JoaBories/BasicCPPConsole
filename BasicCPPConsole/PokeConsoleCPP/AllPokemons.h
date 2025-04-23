#pragma once
#include "Pokemon.h"

class AllPokemons
{
private:
	map<string, Pokemon> mAllPokemons;

public:
	AllPokemons();
	~AllPokemons();

	static AllPokemons* instancePtr;
	static AllPokemons* Get();

	Pokemon GetPokemonCopy(string name);
	Pokemon* GetPokemonPtr(string name);
};

