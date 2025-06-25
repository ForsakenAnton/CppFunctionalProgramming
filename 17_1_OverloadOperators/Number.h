#pragma once
#include <string>

class Number
{
private: // (public !!!)
	double value;
	std::string valueString = "";

	const std::string one[20] =
	{ 
		"", "one ", "two ", "three ", "four ",
		"five ", "six ", "seven ", "eight ",
		"nine ", "ten ", "eleven ", "twelve ",
		"thirteen ", "fourteen ", "fifteen ",
		"sixteen ", "seventeen ", "eighteen ",
		"nineteen " 
	};

	const std::string ten[10] =
	{ 
		"", "", "twenty ", "thirty ", "forty ",
		"fifty ", "sixty ", "seventy ", "eighty ", "ninety " 
	};

	// n is 1- or 2-digit number
	std::string numToWords(int n, std::string s);

	// Function to print a given number in words
	std::string convertToWords(long n);

	void setValue(double value);
	void setValueString(const std::string& valueString);
	void setValueString();

public:
	Number(double value);
	Number();
	~Number();

	double getValue() const;
	std::string getValueString() const;

	// left here is this (!!!)
	Number operator+ (const double& rightValue);
	Number operator+ (const Number& right);
	Number operator- (const Number& right);
	Number operator* (const Number& right);
	Number operator/ (const Number& right);

	bool operator == (const Number& right);
	bool operator != (const Number& right);
	bool operator > (const Number& right);
	bool operator < (const Number& right);

	Number& operator++ ();
	Number& operator-- ();
	const Number operator++ (int _);
	const Number operator-- (int _);


	// Friend Examples ////////////////////////////////////////////////////////////////
	//friend Number operator+ (const Number& left, const Number& right);
	//friend int operator+ (const double& left, const Number& right); // Ok
	//friend Number operator+ (const Number& left, const double& right); // Ok
	//friend Number operator+ (const double& left, const double& right); // Compile Error
	///////////////////////////////////////////////////////////////////////////////////
};
