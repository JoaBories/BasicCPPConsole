#include "AllPokeTypes.h"

AllPokeTypes* AllPokeTypes::instancePtr = new AllPokeTypes();

AllPokeTypes::AllPokeTypes()
{
	mAllPokeTypes[Types::Null] = PokeType(Types::Null, Types::Null, Types::Null, "");
	mAllPokeTypes[Types::Water] = PokeType(Types::Water, Types::Plant, Types::Fire, "Water");
	mAllPokeTypes[Types::Fire] = PokeType(Types::Fire, Types::Water, Types::Plant, "Fire");
	mAllPokeTypes[Types::Plant] = PokeType(Types::Plant, Types::Fire, Types::Water, "Plant");
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
