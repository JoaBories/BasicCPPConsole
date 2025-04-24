#include "Pokeball.h"
#include <iostream>

using std::cout;
using std::endl;

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
