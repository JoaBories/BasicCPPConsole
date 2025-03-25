#include "AllAbilities.h"

AllAbilities* AllAbilities::instancePtr = new AllAbilities();

AllAbilities::AllAbilities()
{
	mAllAbilities["Null"] = Ability();
	mAllAbilities["Flame Burst"] = Ability("Flame Burst", Types::Fire, 70, 100);
	mAllAbilities["Withdraw"] = Ability("Withdraw", Types::Water, Stats::Defense, 6, true);
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
	if (mAllAbilities.find(name) == mAllAbilities.end())
	{
		return &mAllAbilities["Null"];
	}

	return &mAllAbilities[name];
}