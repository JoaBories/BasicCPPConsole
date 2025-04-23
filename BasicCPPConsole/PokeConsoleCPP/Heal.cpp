#include "Heal.h"

#include <iostream>

using std::cout;
using std::endl;

Heal::Heal() : 
	Item{ },
	mAmount{ 0 }
{

}

Heal::Heal(string name, string description, int amount) :
	Item{ name, description },
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
