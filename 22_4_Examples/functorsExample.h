#pragma once
#include <iostream>

class Multiplier
{
private:
	double factor;

public:
	explicit(false) Multiplier(double factor) : factor{ factor }
	{
	}

	double operator() (double value) const
	{
		return value * factor;
	}
};

class PowerMultiplier : public Multiplier
{
public:
	explicit(false) PowerMultiplier(double factor) : Multiplier{ factor }
	{
	}

	double operator() (double value) const
	{
		double result = Multiplier::operator()(value);

		return result * result;
	}
};

void functorsExample()
{
	Multiplier doubler = 2.0;
	PowerMultiplier powerDoubler = 2.0;

	std::cout << "Doubler of 5: " << doubler(5.0) << "\n"; // Outputs 10
	std::cout << "Power Doubler of 5: " << powerDoubler(5.0) << "\n"; // Outputs 100

	std::cout << "\n\n";
}