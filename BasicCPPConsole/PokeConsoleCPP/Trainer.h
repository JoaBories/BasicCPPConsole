#pragma once

#include "Pokemon.h"
#include "AllItems.h"
#include "Inventory.h"

class Trainer : public IDisplayable
{
private:
	string mName;
	Inventory mInventory;
	Pokemon mPokemons[6];
	
public: 
	Trainer();
	~Trainer();

	string GetName() const;
	void SetName(string name);

	// Inherited via IDisplayable
	void Display() const override;
};

