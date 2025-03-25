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

class Items
{
private :
	map<InventoryItems, string> mInventoryItemsNames;

public :
	Items();
	~Items();

	string GetInventoryItemName(InventoryItems item);

};

