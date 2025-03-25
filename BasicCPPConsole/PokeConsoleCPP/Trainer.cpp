#include "Trainer.h"

Trainer::Trainer() :

	mName("John Doe"),
	mEnumerators()
{
	mInventory[InventoryItems::Pokeball] = 0;
	mInventory[InventoryItems::Potion] = 0;
}

Trainer::~Trainer()
{

}

void Trainer::DisplayInfos()
{
	cout << mName << endl;
	DisplayPokemons();
	DisplayInventory();
}

string Trainer::GetName()
{
	return mName;
}

void Trainer::SetName(string name)
{
	mName = name;
}

void Trainer::DisplayPokemons()
{

}

void Trainer::AddItemToInventory(InventoryItems itemType, int number)
{
	mInventory[itemType] += number;
}

void Trainer::RemoveItemFromInventory(InventoryItems itemType, int number)
{
	if (mInventory[itemType] >= number) {
		mInventory[itemType] -= number;
	}
	else {
		mInventory[itemType] = 0;
	}
}

void Trainer::DisplayInventory()
{
	for (pair<InventoryItems, int> item : mInventory) {
		cout << mEnumerators.GetInventoryItemName(item.first) << " | " << item.second << endl;
	}
}
