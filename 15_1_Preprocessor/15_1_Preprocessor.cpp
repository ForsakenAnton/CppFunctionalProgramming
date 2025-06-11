
#define SUM(left, right) left + right

#define POW(numb, power) int result = numb; \
for(int i = 1; i < power; i++) \
{ \
result *= numb; \
} \

#define PI 3.14
#define MAX_CONNECTIONS 100
#define PROGRAM_NAME "Preprocessor"

#define TEST_STAGE
//#define PROD_STAGE

#include <iostream>

#pragma region Main Region

int main()
{
#pragma region SumRegion
	int sum = SUM(3, 4);
	std::cout << sum << "\n";
	std::cout << SUM(3, 4) << "\n";
	//int cinOperand;
	//std::cin >> cinOperand;
	//std::cout << SUM(cinOperand, cinOperand) << "\n";
#pragma endregion



	int numb = 2;
	POW(numb, 4);
	std::cout << numb << "\n";
	std::cout << result << "\n";


	std::cout << PI << "\n";
	std::cout << PROGRAM_NAME << "\n";

	auto pi = PI; //OK
	//PI = 3.14; // Compile Error. PI is a constant


#ifdef PROD_STAGE
	std::cout << "Program works in the production stage!\n\n";
#endif // TEST_STAGE 

#ifdef TEST_STAGE
	std::cout << "Program works in the test stage!\n\n";
#endif // TEST_STAGE


	const bool isActive = false;
	const int number = 100;
	const double dNumber = 42.42;

#if dNumber
	std::cout << "#If works!\n\n";
#endif // 0

#if number
	std::cout << "#If works!\n\n";
#endif // 0

#if isActive
	std::cout << "#If works!\n\n";
#endif // 0

#if MAX_CONNECTIONS == 100
	std::cout << "#If works!\n\n";
#define E 2.7123
#endif // 0

	std::cout << E << "\n\n";

	enum class Operations
	{
		Off,
		On,
		Paused
	};

	Operations op = Operations::On;

#if op == 1
	std::cout << "#If works!\n\n";
#endif // 0


	int x = 10;
	if (x == 10)
	{
#define X 10
	}
	else
	{
#define Y 20
	}

	std::cout << X << " - " << Y << "\n\n";


//#line 35

	std::cout << "...\n";
	std::cout << "...\n";
	std::cout << "...\n";

#undef PI

#ifdef PI
	std::cout << "PI is defined\n";
#endif // PI

#define PI 3.14

#ifndef PI
#error "PI is undef...";
#endif // PI

}
#pragma endregion
