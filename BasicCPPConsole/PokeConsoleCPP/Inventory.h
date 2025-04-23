#pragma once

#include "AllItems.h"

using std::pair;

struct InventoryEntry
{
	Item* item;
	int number;
	ItemType type;
};

class Inventory
{
private:
	map<string, InventoryEntry> mInventory;

public:
	Inventory();
	~Inventory();

	void AddItemToInventory(string name, int number);
	int GetItemNumberInInventory(string name);
	int GetSize() const;
	void RemoveItemFromInventory(string name);

	// Inherited via IDisplayable
	void Display() const;
};

