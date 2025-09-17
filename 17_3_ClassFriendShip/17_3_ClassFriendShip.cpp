#include <iostream>
#include "Tom.h"
#include "Alice.h"

int main()
{
    Tom tom{ false, false };
    Alice alice{ false, false };

	std::cout << std::boolalpha << tom;

	alice.marriage(tom);
	alice.getAccessToTomAccount(tom);

	std::cout << std::boolalpha << tom;

	tom.marriage(alice);
	tom.getAccessToTomAccount(alice);

	std::cout << std::boolalpha << alice;
}
