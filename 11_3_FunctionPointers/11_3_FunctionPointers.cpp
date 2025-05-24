
#include <iostream>

//auto multiple(int a, int b, bool convertToDouble) -> double
auto multiple(int a, int b, bool convertToDouble) -> decltype(3.3F + 123.0F);

void filterAndPrintElementsLessThen(const int* arr, int size, int targetElement);
void filterAndPrintElementsMoreThen(const int* arr, int size, int targetElement);

void filterAndPrintElementsByCondition(const int* arr, int size, int comparer, bool (*condition)(int, int));
bool isLessThan(int number, int comparer);
bool isMoreThan(int number, int comparer);

template <typename T, typename Predicate>
void filterAndPrintElementsByCondition(const T* arr, int size, int comparer, Predicate condition);

int main()
{
	srand(time(nullptr));

	// auto and decltype
	{
		auto value1 = 10; // int
		auto value2 = 10.9; // double
		auto value3 = 10.9F; // float
		auto value4 = value3; // float

		//auto value5; // Compile Error

		int integer = 123;
		auto pointerInteger = &integer; // int*. Ok

		int anotherInteger = 456;
		const int& referenceInteger = anotherInteger;
		//auto variable = referenceInteger; // int. Not Ok
		decltype(referenceInteger) variable = referenceInteger; // const int&. Ok

		decltype(123) x = 456; // int 456.
		std::cout << x << std::endl;

		decltype(42.12) y; // double uninitialized. Ok

		size_t size = 123456789; // size_t == unsigned long long

		unsigned int unsignedInt = 123456789; 
		typedef decltype (unsignedInt) my_type; // my_type == unsigned int

		my_type var = 100500;
		unsigned int var2 = 100500;
		std::cout << typeid(var).name() << std::endl;
		std::cout << typeid(var2).name() << std::endl;
	}

	// auto and decltype in methods
	{
		std::cout << multiple(3, 4, true) << "\n";
		std::cout << multiple(3, 4, false) << "\n";

		auto floatVar = multiple(3, 4, false); // float

		std::cout << "\n\n\n";
	}



	// function pointers
	{
		const int size = 10;
		int arr[size] = {  4, 5, 1, 7, 8, 2, 3, 6, 9, 10 };

		filterAndPrintElementsLessThen(arr, size, 5);
		filterAndPrintElementsMoreThen(arr, size, 5);


		bool (*condition) (int x, int y);

		condition = isLessThan;
		filterAndPrintElementsByCondition(arr, size, 5, condition);

		condition = isMoreThan;
		filterAndPrintElementsByCondition(arr, size, 5, condition);

		filterAndPrintElementsByCondition(arr, size, 5, isLessThan);
		filterAndPrintElementsByCondition(arr, size, 5, isMoreThan);

		std::cout << "\n\n\n==========================================\n";

		bool (*conditions[2]) (int, int) = { isLessThan, isMoreThan };

		for (int i = 0; i < 10; i++)
		{
			int index = rand() % 2;
			filterAndPrintElementsByCondition(arr, size, 5, conditions[index]);
		}


		filterAndPrintElementsByCondition<int, bool(*)(int, int)>(arr, size, 5, isLessThan);
		filterAndPrintElementsByCondition<int, bool(*)(int, int)>(arr, size, 5, isMoreThan);
	}
}




auto multiple(int a, int b, bool convertToDouble) -> decltype(3.3F + 123.0F)
{
	if (convertToDouble)
	{
		return a * b;
	}

	return (double)a * b;
}

void filterAndPrintElementsLessThen(const int* arr, int size, int targetElement)
{
	for (int i = 0; i < size; i++)
	{
		if (arr[i] < targetElement)
		{
			std::cout << arr[i] << ", ";
		}
	}

	std::cout << std::endl << std::endl;
}


void filterAndPrintElementsMoreThen(const int* arr, int size, int targetElement)
{
	for (int i = 0; i < size; i++)
	{
		if (arr[i] > targetElement)
		{
			std::cout << arr[i] << ", ";
		}
	}

	std::cout << std::endl << std::endl;
}

void filterAndPrintElementsByCondition(
	const int* arr, int size, int comparer, bool(*condition)(int, int))
{
	for (int i = 0; i < size; i++)
	{
		if (condition(arr[i], comparer))
		{
			std::cout << arr[i] << ", ";
		}
	}

	std::cout << std::endl << std::endl;
}

bool isLessThan(int number, int comparer)
{
	return number < comparer;
}

bool isMoreThan(int number, int comparer)
{
	return number > comparer;
}

template<typename T, typename Predicate>
void filterAndPrintElementsByCondition(const T* arr, int size, int comparer, Predicate condition)
{
	for (int i = 0; i < size; i++)
	{
		if (condition(arr[i], comparer))
		{
			std::cout << arr[i] << ", ";
		}
	}

	std::cout << std::endl << std::endl;
}
