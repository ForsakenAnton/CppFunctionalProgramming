#include "NumberArray.h"

void NumberArray::init()
{
	for (int i = 0; i < numbersSize; i++)
	{
		// TODO add operator = to Number class
		double randValue = std::rand() % 100;

		pNumbers[i] = randValue;
		vNumbers.push_back(randValue);
	}
}

NumberArray::NumberArray(int numbersSize) :
	numbersSize{ numbersSize },
	pNumbers{ numbersSize != 0 ? new Number[numbersSize]{} : nullptr }
{
	init();

	std::cout << "Create Object: " << this << "\n";
	std::cout << "Create array: " << pNumbers << "\n\n";
}

// Copy ctor
NumberArray::NumberArray(const NumberArray& numberArr) :
	numbersSize{ numberArr.numbersSize },
	pNumbers{ numberArr.numbersSize > 0 ? new Number[numberArr.numbersSize] : nullptr },
	vNumbers{ numberArr.vNumbers }
{
	std::cout << "Create Object: " << this << "\n";
	std::cout << "Create array: " << pNumbers << "\n\n";

	for (int i = 0; i < this->numbersSize; i++)
	{
		this->pNumbers[i] = numberArr[i];
	}
}

// Move ctor
NumberArray::NumberArray(NumberArray&& numberArr) noexcept :
	numbersSize{ numberArr.numbersSize },
	pNumbers{ numberArr.pNumbers },
	vNumbers{ numberArr.vNumbers }
{
	numberArr.numbersSize = 0;
	numberArr.pNumbers = nullptr;
	numberArr.vNumbers.clear();
}



NumberArray::~NumberArray()
{
	std::cout << "Delete Object: " << this << "\n";

	if (pNumbers != nullptr)
	{
		std::cout << "Delete array: " << pNumbers << "\n\n";

		delete[] pNumbers;
		pNumbers = nullptr;
	}
	else
	{
		std::cout << "Array " << pNumbers << " is already deleted\n\n";
	}
}

int NumberArray::getNumbersSize() const
{
	return numbersSize;
}

Number& NumberArray::operator[](int index)
{
	if (index < 0 || index >= numbersSize)
	{
		throw std::exception{ "Index is out of range" };
	}

	return pNumbers[index];
}

Number NumberArray::operator[](int index) const
{
	if (index < 0 || index >= numbersSize)
	{
		throw std::exception{ "Index is out of range" };
	}

	return pNumbers[index];
}

NumberArray& NumberArray::operator=(const NumberArray& numberArr)
{
	if (this == &numberArr) // memory == memory
	{
		return *this;
	}

	if (numberArr.numbersSize == 0)
	{
		this->numbersSize = 0;
		if (this->pNumbers != nullptr)
		{
			delete[] this->pNumbers;
			this->pNumbers = nullptr;
		}
	}
	else if (this->numbersSize != numberArr.numbersSize)
	{
		if (this->pNumbers != nullptr)
		{
			delete[] pNumbers;
		}

		this->numbersSize = numberArr.numbersSize;
		this->pNumbers = new Number[numberArr.numbersSize];
	}

	for (int i = 0; i < this->numbersSize; i++)
	{
		this->pNumbers[i] = numberArr[i];
	}


	this->vNumbers = numberArr.vNumbers;

	return *this;
}
