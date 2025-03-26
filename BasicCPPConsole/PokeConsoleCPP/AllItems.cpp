#include "AllItems.h"

AllItems* AllItems::instancePtr = nullptr;

AllItems::AllItems()
{
	if (!instancePtr)
	{
		instancePtr = this;
	}

	mAllHeals["Null"] = Heal();
	mAllHeals["Potion"] = Heal("Potion", "Restores Pokémon HP by 20", 20);
	mAllHeals["SuperPotion"] = Heal("SuperPotion", "Restores Pokémon HP by 50", 50);
	mAllHeals["HyperPotion"] = Heal("HyperPotion", "Restores Pokémon HP by 50", 120);
	mAllHeals["MaxPotion"] = Heal("MaxPotion", "Restores Pokémon HP by 50", 1000);

	mAllPokeballs["Null"] = Pokeball();
	mAllPokeballs["Pokeball"] = Pokeball("Pokeball", "A simple ball", 1);
	mAllPokeballs["Superball"] = Pokeball("SuperBall", "A good quality ball", 1.5f);
	mAllPokeballs["Hyperball"] = Pokeball("Hyperball", "A high grade ball", 2);
	mAllPokeballs["Masterball"] = Pokeball("Masterball", "The best ball", 255);
}

AllItems::~AllItems()
{

}

AllItems* AllItems::Get()
{
	return instancePtr;
}

Heal* AllItems::GetHealPtr(string name)
{
	return &mAllHeals[name];
}

Pokeball* AllItems::GetPokeballPtr(string name)
{
	return &mAllPokeballs[name];
}
