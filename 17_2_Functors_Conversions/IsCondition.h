#pragma once
#include "NumberCondition.h"

class IsCondition
{
	public:
	
	bool operator()(NumberCondition condition, int number) const
	{
		switch (condition)
		{
		default:
		case IS_EVEN:
			return number % 2 == 0;	
			break;

		case IS_ODD:
			return number % 2 != 0;
			break;

		case IS_SIMPLE:
			if (number < 2)
			{
				return false;
			}

			for (int i = 2; i * i <= number; ++i)
			{
				if (number % i == 0)
				{
					return false;
				}
			}

			return true;
			break;
		}
	}
};