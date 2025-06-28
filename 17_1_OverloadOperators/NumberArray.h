#pragma once
#include <iostream>
#include <vector>

#include "Number.h"

class NumberArray
{
private:
	int numbersSize;
	Number* pNumbers;

	std::vector<Number> vNumbers;

	void init();

public:
	explicit NumberArray(int numbersSize);
	NumberArray(const NumberArray& numberArr);
	~NumberArray();

	int getNumbersSize() const;


	Number& operator[] (int index);
	Number operator[] (int index) const;

	NumberArray& operator= (const NumberArray& numberArr);
};