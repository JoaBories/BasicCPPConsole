#pragma once

#include "Pokemon.h"
#include "AllItems.h"
#include "Inventory.h"

class Trainer : public IDisplayable
{
private:
	string mName;
	Pokemon mPokemons[6];
	
public: 
	Trainer();
	~Trainer();

	string GetName() const;
	void SetName(string name);

	Inventory inventory;

	// Inherited via IDisplayable
	void Display(bool isShort) const override;
};

