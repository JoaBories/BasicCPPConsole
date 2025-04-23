#pragma once

#include <string>

using std::string;

enum class ItemType
{
	Heal,
	Pokeball
};

class Item
{
protected :
	string mName;
	string mDescription;

public :
	Item();
	Item(string Name, string description);
	~Item();

	string GetName() const;
	string GetDescription() const;
};

