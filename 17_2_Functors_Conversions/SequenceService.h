#pragma once

static class SequenceService
{
public:
	template <int SIZE, typename Predicate>
	static bool isUniqueSequence(int (&arr)[SIZE], Predicate p)
	{
		for (int i = 0; i < SIZE; i++)
		{
			if (!p(arr[i]))
			{
				return false;
			}
		}

		return true;
	}
};