#pragma once
#include <string>
#include "Manufacturer.h"

class Product
{
private:
	std::string name;
	double price;
	int accesoriesSize;
	std::string* accesories;
	Manufacturer manufacturer;

public:
	const bool isCertificated = true;
	static double discount;

	Product(
		const std::string& name,
		const double price,
		const int accesoriesSize,
		const std::string* accesories,
		const Manufacturer& manufacturer)
		:
		name{ name },
		price{ price },
		accesoriesSize{ accesoriesSize },
		accesories{ accesoriesSize > 0 ? new std::string[accesoriesSize] : nullptr },
		manufacturer{ manufacturer }
	{
		std::cout
			<< "Product Constructor for " << this
			<< " with accesories memory " << &accesories << "\n";

		for (int i = 0; i < accesoriesSize; i++)
		{
			this->accesories[i] = accesories[i];
		}
	}

	Product() : Product{ "no name", 0, 0, nullptr, Manufacturer{} }
	{

	}


	// Copy Constructor
	Product(const Product& product) :
		Product{ product.name, product.price, product.accesoriesSize, product.accesories, product.manufacturer }
	{
		std::cout << "Copy c-tor has just worked...\n";
	}

	void print()
	{
		std::cout << name << " - " << price << "\n";
		manufacturer.print();
		std::cout << "Accesories:\n";
		for (int i = 0; i < accesoriesSize; i++)
		{
			std::cout << "  " << accesories[i] << "\n";
		}
	}

	static void changeDiscount(double discount)
	{
		Product::discount = discount;
	}

	static void changeDiscountAndPrice(double discount, double price)
	{
		Product::discount = discount;
		//this.price = price;
	}


	~Product()
	{
		std::cout
			<< "~Product ~Destructor for " << this
			<< " with accesories memory " << &accesories << "\n";

		if (accesories != nullptr)
		{
			delete[] accesories;
			accesories = nullptr;
		}

		std::cout << "Accesories after delition: " << &accesories << "\n";
	}
};

double Product::discount = 100.99;