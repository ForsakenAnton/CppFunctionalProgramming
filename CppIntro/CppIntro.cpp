
#include <iostream>
//using namespace std;

int main()
{
	std::cout << "Hello World!\n";
	std::cout << 123 << "\n";

	std::cout << "Long long text..." <<
		"Long long text..." <<
		"Long long text..." <<
		"Long long text...\n\n";

	//std::boolalpha;
	std::cout << true << " and " << false << "\n";


	//data types
	// integers:
	//int
	int integer = 123;
	std::cout << integer << std::endl << std::endl;
	int maxInteger = INT32_MAX;
	int minInteger = INT32_MIN;
	std::cout << maxInteger << " and " << minInteger << "\n";

	// short
	short ahortInteger = 123;
	short maxShortInteger = INT16_MAX;
	short minShortInteger = INT16_MIN;
	std::cout << maxShortInteger << " and " << minShortInteger << "\n";

	//unsigned short
	unsigned short ushort = -1; //UINT16_MAX;
	std::cout << ushort << "\n";

	//unsigned int

	//long
	std::cout << INT64_MAX << " and " << INT64_MIN << "\n";


	// floating numbers
	float f = 100.111111111111111111111111111111F;
	double d = 100.111111111111111111111111111111;
	std::cout << f << "\n";
	std::cout << d << "\n";
	std::cout << FLT_MAX << " and " << FLT_MIN << "\n";
	std::cout << DBL_MAX << " and " << DBL_MIN << "\n";

	// char
	char symbolA = 'A'; // 65;
	std::cout << symbolA << "\n";
	std::cout << symbolA << "\n";

	// bool 
	bool isAuthorized = true;
	bool isOpened = false;

	// off top
	char str[10] = "Hello";
	std::string classStr = "Hello from the class string";
	// /////////////////////



	// cin
	//int number;
	//std::cout << "Enter the number: ";
	//std::cin >> number;
	//std::cout << number << "\n";

	//int x;
	//int y;
	//std::cout << "Enter the x and then y using space between variables: ";
	//std::cin >> x >> y;
	//std::cout << x << " " << y << "\n";




	float money = 1000.99F;
	money = money - 320.55F;
	std::cout << money << "\n";
	std::cout << money - 'A' << "\n";
	std::cout << money << "\n";


	const double PI = 3.14;
	const double EARTH_SPEED_AROUND_SUN = 30.1;

	const double productPrice = 100;
	//productPrice = 200;




	std::cout << "Text" << "\n";
	std::cout << "1\tText" << "\n";
	std::cout << "12\tText" << "\n";
	std::cout << "123\tText" << "\n";
	std::cout << "1234\tText" << "\n";
	std::cout << "12345\tText" << "\n";
	std::cout << "123456\tText" << "\n";
	std::cout << "1234567\tText" << "\n";
	std::cout << "12345678\tText" << "\n";
	std::cout << "123456789\tText" << "\n";
	std::cout << "1234567890\tText" << "\n";



	// First Task
	{
		int x = 123;
		int y = 456;
		// TODO...
	}

	// Second Task
	{
		int x = 123;
		int y = 456;
		// TODO...
	}
}

// std - standard
// cout - console out
// cin - console input

// "\n" == std::endl
