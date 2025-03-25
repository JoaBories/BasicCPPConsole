#include "PokeType.h"

PokeType::PokeType()
{
	mType = Types::Null;
	mWeakTo = Types::Null;
	mResistTo = Types::Null;
	mName = "Normal";
}

PokeType::PokeType(Types type, Types weak, Types resist, string name)
{
	mType = type;
	mWeakTo = weak;
	mResistTo = resist;
	mName = name;
}

PokeType::~PokeType()
{

}

Types PokeType::GetWeakNess()
{
	return mWeakTo;
}

Types PokeType::GetResistance()
{
	return mResistTo;
}

string PokeType::GetName()
{
	return mName;
}
