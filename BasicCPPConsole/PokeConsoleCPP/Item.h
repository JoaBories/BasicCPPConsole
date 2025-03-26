#pragma once

#include <string>
#include "IDisplayable.h"

using std::string;

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
	void Display() const override;
};

