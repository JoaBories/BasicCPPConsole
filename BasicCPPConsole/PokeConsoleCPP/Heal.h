#pragma once

#include "Item.h"

class Heal : public Item 
{
private:
	int mAmount;

public:
	Heal();
	Heal(string name, string desciption, int amount);
	~Heal();

	int GetAmount() const;

	// Inherited via Item
	void Display(bool isShort) const override;
};

