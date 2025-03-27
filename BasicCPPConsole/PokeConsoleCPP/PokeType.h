#pragma once

#include <string>
#include <vector>

using std::string;
using std::vector;

enum class Types
{
	Null,
	Combat,
	Dragon,
	Water,
	Electrik,
	Fire,
	Plant
};

class PokeType
{

private :
	Types mType;
	vector<Types> mWeakTo;
	vector<Types> mResistTo;
	string mName;

public :
	PokeType();
	PokeType(Types type, vector<Types> weak, vector<Types> resist, string name);
	~PokeType();

	Types GetType() const ;
	vector<Types> GetWeakNess() const ;
	vector<Types> GetResistance() const ;
	string GetName() const ;
};

