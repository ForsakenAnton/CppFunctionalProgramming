#pragma once

class IsEven
{
public:
	bool operator()(int number) const
	{
		return number % 2 == 0;
	}
};