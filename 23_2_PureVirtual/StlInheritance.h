#pragma once
#include <iostream>
#include <vector>


class IntVector : public std::vector<int>
{
public:
	void printRange(int start, int end)
	{
		if (start >= this->size() || end >= this->size())
		{
			return;
		}

		for (int i = start; i <= end; i++)
		{
			std::cout << this->at(i) << "\n";
		}
	}
};

class MyString : public std::string
{
public:
	MyString()
	{
		this->assign("");
	}

	explicit(false) MyString(const char* right)
	{
		this->assign(right);
	}

	void toUpper()
	{
		for (auto it = this->begin(); it < this->end(); it++)
		{
			*it = (char)toupper(*it);
		}
	}
};

using int_vector = IntVector;
using my_string = MyString;

void stlInheritance()
{
	int_vector intV;
	intV.push_back(1);
	intV.push_back(2);
	intV.push_back(3);
	intV.push_back(4);
	intV.push_back(5);
	intV.push_back(6);

	intV.printRange(2, 5);

	my_string ms = "My String";
	std::cout << ms << "\n";
	ms.toUpper();
	std::cout << ms << "\n";
}