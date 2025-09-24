#include "Pet.h"

Pet::Pet(const std::string& name, int age)
	: name(name), age(age)
{
}

void Pet::display() const
{
	std::cout << "Pet Name: " << name << ", Age: " << age << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Pet& pet)
{
	os << "Pet Name: " << pet.name << ", Age: " << pet.age;

	return os;
}
