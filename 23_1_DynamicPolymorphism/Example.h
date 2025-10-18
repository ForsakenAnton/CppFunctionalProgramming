#pragma once
#include <iostream>

static class StringHelper
{
public:
	StringHelper() = delete;

	static void toUpperCase(std::string& value)
	{
		auto ch = new char[value.length() + 1];
		strcpy_s(ch, value.length() + 1, value.c_str());

		_strupr_s(ch, value.length() + 1);

		value = ch;

		delete[] ch;
	}

	static void printBorder(char borderSymbol, int borderWidth = 1, int borderLength = 30)
	{
		for (size_t i = 0; i < borderLength; i++)
		{
			std::cout << borderSymbol;
		}
		std::cout << "\n";
	}
};

class Printer
{
protected:
	std::string text;

	virtual void printText()
	{
		std::cout << text << "\n";
	}

public:
	explicit Printer(const std::string& text) : text{ text }
	{
	}

	virtual void print()
	{
		this->printText();
	}
};

class UpperCasePrinter : public Printer
{
protected:
	void printText() override
	{
		StringHelper::toUpperCase(text);
		Printer::printText();
	}

public:
	explicit UpperCasePrinter(const std::string& text) : Printer{ text }
	{
	}
};

class BloquotePrinter : public Printer
{
protected:
	char borderSymbol;

public:
	BloquotePrinter(const std::string& text, char borderSymbol) : 
		Printer{ text },
		borderSymbol{ borderSymbol }
	{
	}

	virtual void print() override
	{
		StringHelper::printBorder(borderSymbol);
		this->printText();
		StringHelper::printBorder(borderSymbol);
	}
};

class BloquoteUpperCasePrinter : public BloquotePrinter
{
protected:
	void printText() override
	{
		StringHelper::toUpperCase(text);
		Printer::printText();
	}

public:
	BloquoteUpperCasePrinter(const std::string& text, char borderSymbol) :
		BloquotePrinter{ text, borderSymbol }
	{
	}
};

void example()
{
	Printer* simplePrinter = new Printer{ "I hate mechanic keyboards!!111" };
	simplePrinter->print();
	std::cout << "\n";

	Printer* upperCasePrinter = new UpperCasePrinter{ "lower to upper" };
	upperCasePrinter->print();
	std::cout << "\n";

	Printer* bloquotePrinter = new BloquotePrinter{ "Some Bloquote Text", '%'};
	bloquotePrinter->print();
	std::cout << "\n";

	BloquotePrinter* bloquoteUpperCasePrinter = new BloquoteUpperCasePrinter
	{
		"Bloquote Upper Case Printer" ,
		'#'
	};

	bloquoteUpperCasePrinter->print();
	std::cout << "\n";

	delete simplePrinter;
	delete upperCasePrinter;
	delete bloquotePrinter;
	delete bloquoteUpperCasePrinter;
}