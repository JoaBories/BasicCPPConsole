#include "AllAbilities.h"

AllAbilities* AllAbilities::instancePtr = nullptr;

AllAbilities::AllAbilities()
{
	if (!instancePtr)
	{
		instancePtr = this;
	}

	mAllAbilities["Null"] = Ability();

	mAllAbilities["Tackle"] = Ability("Tackle", Types::Normal, 40, 100); // Normal
	mAllAbilities["Bite"] = Ability("Bite", Types::Normal, 60, 100);

	mAllAbilities["BugBite"] = Ability("BugBite", Types::Insect, 60, 100); // Insect

	mAllAbilities["WingAttack"] = Ability("WingAttack", Types::Fly, 60, 100); // Fly

	mAllAbilities["VineWhip"] = Ability("VineWhip", Types::Plant, 45, 100); // Plant

	mAllAbilities["FireBlast"] = Ability("FireBlast", Types::Fire, 110, 85); // Fire
	mAllAbilities["Ember"] = Ability("Ember", Types::Fire, 40, 100);

	mAllAbilities["WaterGun"] = Ability("WaterGun", Types::Water, 40, 100); // Water


}

AllAbilities::~AllAbilities()
{

}

AllAbilities* AllAbilities::Get()
{
	return instancePtr;
}

Ability* AllAbilities::GetAbilityPtr(string name)
{
	return &mAllAbilities[name];
}