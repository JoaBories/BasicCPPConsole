#include "AllPokemons.h"

#include <iostream>
using std::cout;
using std::endl;

AllPokemons* AllPokemons::instancePtr = nullptr;

AllPokemons::AllPokemons()
{
	if (!instancePtr)
	{
		instancePtr = this;
	}

	mAllPokemons["null"] = Pokemon();
	mAllPokemons["bulbasaur"] = Pokemon("bulbasaur", 45, 57, 57, 45, new Types[2]{ Types::Plant, Types::Poison }, new string[2]{ "Tackle", "VineWhip" });
	mAllPokemons["charmander"] = Pokemon("charmander", 39, 56, 47, 65, new Types[2]{ Types::Fire, Types::Null }, new string[2]{ "Ember", "FireBlast" });
	mAllPokemons["squirtle"] = Pokemon("squirtle", 44, 49, 65, 43, new Types[2]{ Types::Water, Types::Null }, new string[2]{ "Tackle", "WaterGun" });

	mAllPokemons["pidgey"] = Pokemon("pidgey", 40, 40, 38, 56, new Types[2]{ Types::Fly, Types::Normal }, new string[2]{ "Tackle", "WingAttack" });
	mAllPokemons["caterpie"] = Pokemon("caterpie", 45, 25, 28, 45, new Types[2]{ Types::Insect, Types::Null }, new string[2]{ "Tackle", "Bite" });
	mAllPokemons["rattata"] = Pokemon("rattata", 30, 41, 35, 72, new Types[2]{ Types::Normal, Types::Null }, new string[2]{ "Tackle", "Bite" });


}

AllPokemons::~AllPokemons()
{
}

AllPokemons* AllPokemons::Get()
{
	return instancePtr;
}

void AllPokemons::LoadAllTextures()
{
	for (pair<string, Pokemon> entry : mAllPokemons)
	{
		Image img = LoadImage(("resources/img/" + entry.first + ".png").c_str());
		Texture texture = LoadTextureFromImage(img);
		mAllPokemonsTextures[entry.first] = texture;

		UnloadImage(img);
	}
}

Texture AllPokemons::GetPokemonTexture(string name)
{
	return mAllPokemonsTextures[name];
}

Pokemon AllPokemons::GetPokemonCopy(string name)
{
	return mAllPokemons[name];
}

Pokemon* AllPokemons::GetPokemonPtr(string name)
{
	return &mAllPokemons[name];
}
