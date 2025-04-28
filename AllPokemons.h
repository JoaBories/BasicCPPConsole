#pragma once
#include "Pokemon.h"
using std::pair;

class AllPokemons
{
private:
	map<string, Pokemon> mAllPokemons;
	map<string, Texture> mAllPokemonsTextures;

public:
	AllPokemons();
	~AllPokemons();

	static AllPokemons* instancePtr;
	static AllPokemons* Get();

	void LoadAllTextures();
	Texture GetPokemonTexture(string name);

	Pokemon GetPokemonCopy(string name);
	Pokemon* GetPokemonPtr(string name);
};

