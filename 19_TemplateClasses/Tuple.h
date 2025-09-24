#pragma once
#include <iostream>

template <typename F, typename S>
class Tuple
{
private:
	F first;
	S second;

public:
	Tuple(const F& first = F(), const S& second = S())
		: first(first), second(second)
	{
	}

	F getFirst() const
	{
		return first;
	}

	S getSecond() const
	{
		return second;
	}

	void setTuples(const F& first, const S& second)
	{
		this->first = first;
		this->second = second;
	}

	friend std::ostream& operator<<(std::ostream& os, const Tuple<F, S>& tuple)
	{
		os << "First: " << tuple.first << ", Second: " << tuple.second;
		return os;
	}
};