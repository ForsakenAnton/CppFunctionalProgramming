#include "Alice.h"

Alice::Alice(bool isMarried, bool hasAccesToTomAccount)
	: isMarried(false), hasAccesToTomAccount(false)
{
}

void Alice::marriage(Tom& tom)
{
	tom.isMarried = true;
	std::cout << "Married!\n";
}

void Alice::getAccessToTomAccount(Tom& tom)
{
	tom.hasAccesToTomAccount = true;
	std::cout << "Access to Tom's account granted!\n";
}

std::ostream& operator<<(std::ostream& os, const Alice& alice)
{
	os << "Married: " << alice.isMarried << "\n";
	os << "Access account: " << alice.hasAccesToTomAccount << "\n\n";

	return os;
}
