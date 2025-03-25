#pragma once

#include "Enumerators.h"

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
		Enumerators mEnumerators;
	
	public : 
		Trainer();
		~Trainer();
		void DisplayInfos();
		string GetName();
		void SetName(string name);
		void DisplayPokemons();
		void AddItemToInventory(InventoryItems itemType, int number);
		void RemoveItemFromInventory(InventoryItems itemType, int number);
		void DisplayInventory();



};

