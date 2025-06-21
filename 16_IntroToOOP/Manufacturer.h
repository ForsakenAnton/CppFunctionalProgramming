#pragma once
#include <iostream>
#include <string>

class Manufacturer
{
	std::string name;
	// other fields

public:

	Manufacturer() : Manufacturer{ "ShakeAndBake" }
	{
	}

	Manufacturer(const std::string& name) : name{ name }
	{
		std::cout<< "Manufacturer Constructor for " << this << "\n";
	}

	void print()
	{
		std::cout << "Country name: " << name << "\n";
	}

	~Manufacturer() 
	{
		std::cout << "~Manufacturer ~Deststructor for " << this << "\n";
	}
};