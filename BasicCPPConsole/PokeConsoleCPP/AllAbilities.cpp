#include "AllAbilities.h"

AllAbilities* AllAbilities::instancePtr = nullptr;

AllAbilities::AllAbilities()
{
	if (!instancePtr)
	{
		instancePtr = this;
	}

	mAllAbilities["Null"] = Ability();
	mAllAbilities["Flame Burst"] = Ability("Flame Burst", Types::Fire, 70, 100);
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