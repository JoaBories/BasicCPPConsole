#pragma once

#include <string>

using std::string;

enum class Types
{
	Null,
	Water,
	Fire,
	Plant
};

class PokeType
{

private :
	Types mType;
	Types mWeakTo;
	Types mResistTo;
	string mName;

public :
	PokeType();
	PokeType(Types type, Types weak, Types resist, string name);
	~PokeType();

	Types GetType() const ;
	Types GetWeakNess() const ;
	Types GetResistance() const ;
	string GetName() const ;
};

