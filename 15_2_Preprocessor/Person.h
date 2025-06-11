#pragma once
#include <iostream>
#include <string>

struct Person
{
	std::string name;
	int age;

	void info() const;

	template <typename TSomething>
	bool equalPersonWithSomething(const TSomething& sth);
};

template<typename TSomething>
bool Person::equalPersonWithSomething(const TSomething& sth)
{
	// TODO implementation
	return true;
}
