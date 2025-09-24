#pragma once
#include <iostream>

class Pet
{
	private:
		std::string name;
		int age;

public:

	Pet(const std::string& name = "", int age = 0);

	void display() const;

	bool operator>=(const Pet& other) const
	{
		return this->age >= other.age;
	}

	bool operator>(const int& other) const
	{
		return this->age >= other;
	}

	friend std::ostream& operator<<(std::ostream& os, const Pet& pet);
};

