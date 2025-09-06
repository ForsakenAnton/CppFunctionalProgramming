#pragma once
#include <iostream>

class UniqueSequence
{
private:
	int previous;

public:
	UniqueSequence() : previous(INT32_MIN)
	{ }

	bool operator()(int value)
	{
		if (previous == INT32_MIN)
		{
			previous = value;
			return true;
		}

		if (previous != value)
		{
			previous = value;
			return true;
		}

		return false;
	}

	void reset()
	{
		previous = INT32_MIN;
	}
};