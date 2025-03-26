#include "Inventory.h"

Inventory::Inventory()
{
	mInventory["HNull"] = InventoryEntry{ AllItems::Get()->GetHealPtr("Null"), 0, ItemType::Heal };
	mInventory["Potion"] = InventoryEntry{ AllItems::Get()->GetHealPtr("Potion"), 0, ItemType::Heal };
	mInventory["SuperPotion"] = InventoryEntry{ AllItems::Get()->GetHealPtr("SuperPotion"), 0, ItemType::Heal };
	mInventory["HyperPotion"] = InventoryEntry{ AllItems::Get()->GetHealPtr("HyperPotion"), 0, ItemType::Heal };
	mInventory["MaxPotion"] = InventoryEntry{ AllItems::Get()->GetHealPtr("MaxPotion"), 0, ItemType::Heal };

	mInventory["PNull"] = InventoryEntry{ AllItems::Get()->GetPokeballPtr("Null"), 0, ItemType::Pokeball };
	mInventory["Pokeball"] = InventoryEntry{ AllItems::Get()->GetPokeballPtr("Pokeball"), 0, ItemType::Pokeball };
	mInventory["Superball"] = InventoryEntry{ AllItems::Get()->GetPokeballPtr("Superball"), 0, ItemType::Pokeball };
	mInventory["Hyperball"] = InventoryEntry{ AllItems::Get()->GetPokeballPtr("Hyperball"), 0, ItemType::Pokeball };
	mInventory["Masterball"] = InventoryEntry{ AllItems::Get()->GetPokeballPtr("Masterball"), 0, ItemType::Pokeball };
}

Inventory::~Inventory()
{

}

void Inventory::AddItemToInventory(string name, int number)
{
	mInventory[name].number += number;
}

int Inventory::GetItemNumberInInventory(string name)
{
	return mInventory[name].number;
}

void Inventory::RemoveItemFromInventory(string name)
{
	if (GetItemNumberInInventory(name) != 0)
	{
		mInventory[name].number--;
	}
}

void Inventory::Display(bool isShort) const
{
	for (pair<string, InventoryEntry> entry : mInventory)
	{
		if (entry.second.number != 0)
		{
			cout << entry.first << " : " << entry.second.number << endl;
		}
	}
}
