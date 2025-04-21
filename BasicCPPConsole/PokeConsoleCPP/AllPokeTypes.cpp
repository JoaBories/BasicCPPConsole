#include "AllPokeTypes.h"

AllPokeTypes* AllPokeTypes::instancePtr = nullptr;

AllPokeTypes::AllPokeTypes()
{
	if (!instancePtr)
	{
		instancePtr = this;
	}
	//Type, Weak, Resist, Name
	mAllPokeTypes[Types::Null] = PokeType();
	mAllPokeTypes[Types::Combat] = PokeType(Types::Combat, { Types::Fly, Types::Psy }, { Types::Rock, Types::Insect }, "Combat");
	mAllPokeTypes[Types::Water] = PokeType(Types::Water, { Types::Electrik, Types::Plant }, { Types::Fire, Types::Combat, Types::Insect }, "Water");
	mAllPokeTypes[Types::Poison] = PokeType(Types::Poison, { Types::Combat, Types::Psy }, { Types::Plant, Types::Insect }, "Poison");
	mAllPokeTypes[Types::Fire] = PokeType(Types::Fire, { Types::Water, Types::Rock, Types::Ground}, { Types::Plant, Types::Fire, Types::Insect }, "Fire");
	mAllPokeTypes[Types::Insect] = PokeType(Types::Insect, { Types::Poison, Types::Fire, Types::Rock }, { Types::Combat, Types::Ground, Types::Plant }, "Insect");
	mAllPokeTypes[Types::Normal] = PokeType(Types::Normal, { Types::Combat }, { Types::Specter }, "Normal");
	mAllPokeTypes[Types::Plant] = PokeType(Types::Plant, { Types::Fire, Types::Insect, Types::Poison, Types::Ice, Types::Fly }, { Types::Water, Types::Electrik, Types::Plant, Types::Ground }, "Plant");
	mAllPokeTypes[Types::Fly] = PokeType(Types::Fly, { Types::Electrik, Types::Rock, Types::Ice }, { Types::Insect, Types::Plant, Types::Combat, Types::Ground }, "Fly");
}

AllPokeTypes::~AllPokeTypes()
{

}

AllPokeTypes* AllPokeTypes::Get()
{
	return instancePtr;
}

PokeType* AllPokeTypes::GetPokeTypePtr(Types type)
{
	return &mAllPokeTypes[type];
}
