#include "Enumerators.h"

Enumerators::Enumerators()
{
	mInventoryItemsNames = {
		{ InventoryItems::Potion, "Potion" },
		{ InventoryItems::Pokeball, "Pokeball" }
	};
}

Enumerators::~Enumerators()
{

}

string Enumerators::GetInventoryItemName(InventoryItems item)
{
	return mInventoryItemsNames[item];
}

