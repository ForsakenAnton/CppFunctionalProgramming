#include "Tom.h"
#include "Alice.h"

Tom::Tom(bool isMarried, bool hasAccesToTomAccount)
	: isMarried(false), hasAccesToTomAccount(false)
{
}

void Tom::marriage(Alice& alice)
{
	alice.isMarried = true;
	std::cout << "Married!\n";
}

void Tom::getAccessToTomAccount(Alice& alice)
{
	std::cout << "Has no access to Alice's account granted!\n";
}

std::ostream& operator<<(std::ostream& os, const Tom& tom)
{
	os << "Married: " << tom.isMarried << "\n";
	os << "Access account: " << tom.hasAccesToTomAccount << "\n\n";

	return os;
}
