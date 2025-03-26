#include "Heal.h"

Heal::Heal() : 
	Item{ },
	mAmount{ 0 }
{

}

Heal::Heal(string name, string desciption, int amount) :
	Item{ name, desciption },
	mAmount{ amount }
{

}

Heal::~Heal()
{
}

int Heal::GetAmount() const
{
	return mAmount;
}

void Heal::Display() const
{
	cout << mName << " | " << mDescription << " | " << mAmount << endl;
}
