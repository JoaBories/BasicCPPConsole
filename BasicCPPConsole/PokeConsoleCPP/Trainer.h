#pragma once

#include "Pokemon.h"

class Trainer : public IDisplayable
{
private :
	string mName;
	string mPokemons[6];
	
public : 
	Trainer();
	~Trainer();

	string GetName() const;
	void SetName(string name);


	// Inherited via IDisplayable
	void Display() const override;
};

