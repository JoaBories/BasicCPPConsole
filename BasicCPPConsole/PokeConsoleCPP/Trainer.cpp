#include "Trainer.h"

Trainer::Trainer() :
	mName{ "John Doe" }
{
	inventory = Inventory();
}

Trainer::Trainer(string name) :
	mName{ name }
{
	inventory = Inventory();
}

Trainer::~Trainer()
{

}

string Trainer::GetName() const
{
	return mName;
}

void Trainer::Display(bool isShort) const
{
	cout << mName << endl;
	inventory.Display(true);
}
