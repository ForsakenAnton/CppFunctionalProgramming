#pragma once

class Device
{
public:
	std::string name;

	explicit(true) Device(const std::string& name) : name(name)
	{
	}

	void show() const
	{
		std::cout << "Device Name: " << name << std::endl;
	}
};

class Printer : public Device
{
public:
	explicit(true) Printer(const std::string& name) : Device{ name }
	{
	}

	void print() const
	{
		std::cout << "Printing from " << name << std::endl;
	}
};

class Scanner : public Device
{
public:
	explicit(true) Scanner(const std::string& name) : Device{ name }
	{
	}

	void scan() const
	{
		std::cout << "Scanninng from " << name << std::endl;
	}
};

class MultiFunctionalDevice : public Printer, public Scanner
{
public:
	explicit(true) MultiFunctionalDevice(const std::string& name) :
		Printer{ name + " as Printer" },
		Scanner{ name + "as Scanner" }
	{
	}

	void showAll() const
	{
		//show(); // ambigious

		Device::show();
		Printer::show();
		Scanner::show();
	}
};


void multipleInheritance()
{
	MultiFunctionalDevice mfd{ "HP MultiFunctional" };
	mfd.showAll();

	std::cout << mfd.Device::name << std::endl;
	std::cout << mfd.Printer::name << std::endl;
	std::cout << mfd.Scanner::name << std::endl;

	//std::cout << mfd.name << std::endl; // ambigious
}