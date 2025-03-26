#pragma once
#include "Item.h"
class Pokeball : public Item
{
private :
	float mCaptureRate;

public :
	Pokeball();
	Pokeball(string name, string description, int captureRate);
	~Pokeball();

	float GetCaptureRate() const;

	// Inherited via Item
	void Display() const override;
};

