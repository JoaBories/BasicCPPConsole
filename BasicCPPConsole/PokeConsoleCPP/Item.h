#pragma once

#include <string>
#include "IDisplayable.h"

using std::string;

enum class ItemType
{
	Heal,
	Pokeball
};

class Item : public IDisplayable
{
protected :
	string mName;
	string mDescription;

public :
	Item();
	Item(string Name, string description);
	~Item();

	string GetName() const;
	string GetDescription() const;

	// Inherited via IDisplayable
	void Display(bool isShort) const override;
};

