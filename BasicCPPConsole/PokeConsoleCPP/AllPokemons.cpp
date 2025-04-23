#include "AllPokemons.h"

AllPokemons* AllPokemons::instancePtr = nullptr;

AllPokemons::AllPokemons()
{
	if (!instancePtr)
	{
		instancePtr = this;
	}

	mAllPokemons["Null"] = Pokemon();
	mAllPokemons["Bulbasaur"] = Pokemon("bulbasaur", 45, 57, 57, 45, new Types[2]{ Types::Plant, Types::Poison }, new string[2]{ "Tackle", "VineWhip" });
	mAllPokemons["Charmander"] = Pokemon("charmander", 39, 56, 47, 65, new Types[2]{ Types::Fire, Types::Null }, new string[2]{ "Ember", "FireBlast" });
	mAllPokemons["Squirtle"] = Pokemon("squirtle", 44, 49, 65, 43, new Types[2]{ Types::Water, Types::Null }, new string[2]{ "Tackle", "WaterGun" });

	mAllPokemons["Pidgey"] = Pokemon("pidgey", 40, 40, 38, 56, new Types[2]{ Types::Fly, Types::Normal }, new string[2]{ "Tackle", "WingAttack" });
	mAllPokemons["Caterpie"] = Pokemon("caterpie", 45, 25, 28, 45, new Types[2]{ Types::Insect, Types::Null }, new string[2]{ "Tackle", "Bite" });
	mAllPokemons["Rattata"] = Pokemon("rattata", 30, 41, 35, 72, new Types[2]{ Types::Normal, Types::Null }, new string[2]{ "Tackle", "Bite" });


}

AllPokemons::~AllPokemons()
{
}

AllPokemons* AllPokemons::Get()
{
	return instancePtr;
}

Pokemon AllPokemons::GetPokemonCopy(string name)
{
	return mAllPokemons[name];
}

Pokemon* AllPokemons::GetPokemonPtr(string name)
{
	return &mAllPokemons[name];
}
