#include "Items.h"

Items::Items()
{
	mInventoryItemsNames = {
		{ InventoryItems::Potion, "Potion" },
		{ InventoryItems::Pokeball, "Pokeball" }
	};
}

Items::~Items()
{

}

string Items::GetInventoryItemName(InventoryItems item)
{
	return mInventoryItemsNames[item];
}

