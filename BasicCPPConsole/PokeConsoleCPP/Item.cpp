#include "Item.h"

Item::Item() :
	mName{ "Null" },
	mDescription{ "Null" }
{
}

Item::Item(string name, string description) : 
	mName{ name },
	mDescription{ description }
{
}

Item::~Item()
{
}

string Item::GetName() const
{
	return mName;
}

string Item::GetDescription() const
{
	return mDescription;
}

void Item::Display() const
{
	cout << mName << " | " << mDescription << endl;
}
