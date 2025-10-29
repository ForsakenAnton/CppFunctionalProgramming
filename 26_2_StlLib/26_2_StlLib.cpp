
#include <iostream>
#include <functional>
#include <algorithm>

// const_cast
void constCastExample(const int* value)
{
	auto constValue = value;
	//*constValue = 123; // Compiler error: cannot modify a const value

	int* nonConstValue = const_cast<int*>(value);
	*nonConstValue = 100; // Modifying the value
}

// const_cast
void constCastWithRefExample(const int& value)
{
	//auto constValue = value;
	//constValue = 123;
	// 
	// alternate to save cons and & without auto using 
	//decltype(value) constRefValue = value;
	//constRefValue = 123; // Compiler error: cannot modify a const value

	int& nonConstValue = const_cast<int&>(value);
	nonConstValue = 200; // Modifying the value
}

void reinterpretCastExample()
{
	int value = 42;
	void* voidPtr = &value;
	int* intPtr = reinterpret_cast<int*>(voidPtr);
	std::cout << *intPtr << "\n";

	// and vice versa operation
	int* anotherIntPtr = &value;

	// example with char*
	char* charPtr = reinterpret_cast<char*>(anotherIntPtr);
	// and vice versa operation
	int* intPtrFromChar = reinterpret_cast<int*>(charPtr);

}

int main()
{
	//const_cast
	{
		int value = 42;
		constCastExample(&value);
		std::cout << value << "\n";

		constCastWithRefExample(value);
		std::cout << value << "\n";
	}

	//reinterpret_cast
	{
		reinterpretCastExample();
	}

	// std::functors examples
	{
		std::plus<> add;
		std::cout << "10 + 20 = " << add(10, 20) << "\n";
		std::cout << "10.1 + 20.2 = " << add(10.1, 20.2) << "\n";

		std::minus<> sub;
		std::cout << "20 - 10 = " << sub(20, 10) << "\n";
		std::cout << sub("qwerty", 'c') << "\n";

		std::logical_and<> logicalAnd;
		std::cout << "true && false = " << logicalAnd(true, false) << "\n";
		std::cout << "true && false = " << logicalAnd(1 == 1, 2 == 3) << "\n";
	}


	{
		const int size = 10;
		int arr[size] = { 0, 3, 3, 3, 4, 5, 6, 7, 8, 9 };

		auto startIt = std::begin(arr);

		auto endFiveIt = std::end(arr);
		std::advance(endFiveIt, -5); // move iterator 5 positions back

		int* findedRes = std::find(startIt, endFiveIt, 3);

		std::cout << std::count(arr, arr +10, 3) << "\n";
		std::cout << std::count(startIt, endFiveIt, 3) << "\n";

		//std::binary_search

		std::replace(startIt, endFiveIt, 3, 33);
		//std::replace_copy()

		std::reverse(startIt, endFiveIt);

		std::cout << "";

		std::random_shuffle(std::begin(arr), std::end(arr));
		for (size_t i = 0; i < size; i++)
		{
			std::cout << arr[i] << ", ";
		}
		std::cout << "\n";

		std::sort(std::begin(arr), std::end(arr), std::greater<>());
		for (size_t i = 0; i < size; i++)
		{
			std::cout << arr[i] << ", ";
		}
		std::cout << "\n";
	}
}
