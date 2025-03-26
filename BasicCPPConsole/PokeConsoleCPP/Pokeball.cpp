#include "Pokeball.h"

Pokeball::Pokeball() :
	Item{ "Null", "Null" },
	mCaptureRate{ 0 }
{

}

Pokeball::Pokeball(string name, string description, float captureRate) : 
	Item{ name, description },
	mCaptureRate{ captureRate }
{

}

Pokeball::~Pokeball()
{
}

float Pokeball::GetCaptureRate() const
{
	return mCaptureRate;
}

void Pokeball::Display() const
{
	cout << mName << " | " << mDescription << " | " << mCaptureRate << endl;
}
