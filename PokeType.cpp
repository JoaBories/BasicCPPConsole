 #include "PokeType.h"

PokeType::PokeType()
{
	mType = Types::Null;
	mWeakTo.push_back(Types::Null);
	mResistTo.push_back(Types::Null);
	mName = "Normal";
}

PokeType::PokeType(Types type, vector<Types> weak, vector<Types> resist, string name)
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

vector<Types> PokeType::GetWeakNess() const
{
	return mWeakTo;
}

vector<Types> PokeType::GetResistance() const
{
	return mResistTo;
}

string PokeType::GetName() const
{
	return mName;
}
