#pragma once

#include <iostream>

using std::cout;
using std::endl;

class IDisplayable
{
public:
	virtual ~IDisplayable() {};

	virtual void Display(bool isShort) const = 0;
};

