#include "Trainer.h"

Trainer::Trainer() :
	mName{ "John Doe" }
{

}

Trainer::~Trainer()
{

}

string Trainer::GetName() const
{
	return mName;
}

void Trainer::SetName(string name)
{
	mName = name;
}

void Trainer::Display() const
{
	cout << mName << endl;
}
