#include "Number.h"

// Private

std::string Number::numToWords(int n, std::string s)
{
	std::string str = "";
	// if n is more than 19, divide it
	if (n > 19)
		str += ten[n / 10] + one[n % 10];
	else
		str += one[n];

	// if n is non-zero
	if (n)
		str += s;

	return str;
}

std::string Number::convertToWords(long n)
{
	// stores word representation of given number n
	std::string out;

	// handles digits at ten millions and hundred
	// millions places (if any)
	out += numToWords((n / 10000000), "crore ");

	// handles digits at hundred thousands and one
	// millions places (if any)
	out += numToWords(((n / 100000) % 100), "lakh ");

	// handles digits at thousands and tens thousands
	// places (if any)
	out += numToWords(((n / 1000) % 100), "thousand ");

	// handles digit at hundreds places (if any)
	out += numToWords(((n / 100) % 10), "hundred ");

	if (n > 100 && n % 100)
		out += "and ";

	// handles digits at ones and tens places (if any)
	out += numToWords((n % 100), "");

	//Handling the n=0 case
	if (out == "")
		out = "zero";

	return out;
}

void Number::setValue(double value)
{
	this->value = value;
	setValueString();
}

void Number::setValueString(const std::string& valueString)
{
	this->valueString = valueString;
}

void Number::setValueString()
{
	int nominant = value;
	int denominant = round((value - nominant) * 1000);

	valueString = convertToWords(nominant);

	if (denominant != 0)
	{
		valueString += "point ";
		valueString += convertToWords(denominant);
	}
}


// Public

Number::Number(double value) : value{ value }
{
	setValueString();
}

Number::Number() : Number{ 0.0 }
{
}

Number::~Number()
{
}

double Number::getValue() const
{
	return value;
}

std::string Number::getValueString() const
{
	return valueString;
}

Number Number::operator+(const double& rightValue)
{
	return Number{ this->value + rightValue };
}

Number Number::operator+(const Number& right)
{
	return Number{ this->value + right.value };
}

inline Number Number::operator-(const Number& right)
{
	return Number{ this->value - right.value };
}

inline Number Number::operator*(const Number& right)
{
	return Number{ this->value * right.value };
}

inline Number Number::operator/(const Number& right)
{
	return right.value == 0
		? Number{ }
	: Number{ this->value / right.value };
}

bool Number::operator==(const Number& right)
{
	return this->value == right.value;
}

bool Number::operator!=(const Number& right)
{
	return this->value != right.value;
}

bool Number::operator>(const Number& right)
{
	return this->value >= right.value;
}

bool Number::operator<(const Number& right)
{
	return this->value <= right.value;
}

// prefix
Number& Number::operator++ ()
{
	this->setValue(this->value + 1);

	return *this;
}

// prefix
Number& Number::operator-- ()
{
	this->setValue(this->value - 1);

	return *this;
}

// postfix
const Number Number::operator++ (int)
{
	Number temporaryObj{ value };

	//this->setValue(this->value + 1);
	++(*this);

	return temporaryObj;
}

// postfix
const Number Number::operator-- (int)
{
	Number temporaryObj{ value };

	//this->setValue(this->value - 1);
	--(*this);

	return temporaryObj;
}

Number& Number::operator=(const Number& number)
{
	this->value = number.value;
	this->valueString = number.valueString;

	return *this;
}


// Friend Examples ////////////////////////////////////////////////////////////////
//Number operator+ (const Number& left, const Number& right)
//{
//	return Number{ left.value + right.value };
//}
///////////////////////////////////////////////////////////////////////////////////

// friend
std::ostream& operator<<(std::ostream& out, const Number& number)
{
	out << "Value: " << number.value << "\n";
	out << "ValueString: " << number.valueString << "\n";

	return out;
}

std::istream& operator>>(std::istream& in, Number& number)
{
	double value;
	std::cout << "Enter the value: ";
	in >> value;

	number.setValue(value);

	return in;
}
