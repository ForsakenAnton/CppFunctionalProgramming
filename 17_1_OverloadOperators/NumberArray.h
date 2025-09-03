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
	NumberArray(const NumberArray& numberArr); // Copy ctor
	NumberArray(NumberArray&& numberArr) noexcept; // Move ctor
	~NumberArray();

	int getNumbersSize() const;


	Number& operator[] (int index);
	Number operator[] (int index) const;

	NumberArray& operator= (const NumberArray& numberArr);
};