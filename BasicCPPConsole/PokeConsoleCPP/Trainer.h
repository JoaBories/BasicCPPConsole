#pragma once

#include "Items.h"

#include <string>
#include <iostream>
#include <map>

using std::cout;
using std::endl;

using std::string;
using std::map;
using std::pair;

class Trainer
{
private :
	string mName;
	string mPokemons[6];
	map<InventoryItems, int> mInventory;
	Items mEnumerators;
	
public : 
	Trainer();
	~Trainer();

	string GetName();
	void SetName(string name);

	void DisplayInfos();
	void DisplayPokemons();
	void DisplayInventory();

	void AddItemToInventory(InventoryItems itemType, int number);
	void RemoveItemFromInventory(InventoryItems itemType, int number);
};

