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

Types PokeType::GetType() const
{
	return mType;
}

Types PokeType::GetWeakNess() const
{
	return mWeakTo;
}

Types PokeType::GetResistance() const
{
	return mResistTo;
}

string PokeType::GetName() const
{
	return mName;
}
