#pragma once

#include <string>
#include <map>

using std::map;
using std::string;


enum class InventoryItems
{
	Potion,
	Pokeball
};

class Enumerators
{
private :
	map<InventoryItems, string> mInventoryItemsNames;

public :
	Enumerators();
	~Enumerators();

	string GetInventoryItemName(InventoryItems item);

};

