#pragma once

#include "AllItems.h"

using std::pair;

struct InventoryEntry
{
	Item* item;
	int number;
	ItemType type;
};

class Inventory : public IDisplayable
{
private:
	map<string, InventoryEntry> mInventory;

public:
	Inventory();
	~Inventory();

	void AddItemToInventory(string name, int number);
	int GetItemNumberInInventory(string name);
	void RemoveItemFromInventory(string name);

	// Inherited via IDisplayable
	void Display(bool isShort) const override;
};

