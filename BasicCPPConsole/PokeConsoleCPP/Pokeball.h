#pragma once
#include "Item.h"
class Pokeball : public Item
{
private :
	float mCaptureRate;

public :
	Pokeball();
	Pokeball(string name, string description, float captureRate);
	~Pokeball();

	float GetCaptureRate() const;
};

