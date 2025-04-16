#include <iostream>
#include <array>

int main()
{
	//std::srand(std::time(0)); // Ok
	std::srand(std::time(nullptr));

	// std::rand()
	{
		int randomNumber = std::rand();
		std::cout << randomNumber << std::endl;
		std::cout << RAND_MAX << std::endl << std::endl;

		for (int i = 0; i < 30; i++)
		{
			//int randBetweenZeroAndTen = rand() % 10;

			// formula for rand() with min and max
			int min = 10;
			int max = 15;
			int randBetweenZeroAndTen = rand() % (max - min + 1) + min;

			std::cout << randBetweenZeroAndTen << std::endl;
		}
	}


	// static one dimensional arrays
	{
		//int x { 123.12F }; // error, loosed data
		float y{ 123 }; // Ok. Conversion from less precise type to more precise type

		//int someDynamicSize = 10;
		int const size = 10;

		int arr[size]{};

		// random init
		for (int i = 0; i < size; i++)
		{
			arr[i] = rand() % (10 - 1 + 1) + 1;
		}

		// print
		for (int i = 0; i < size; i++)
		{
			std::cout << arr[i] << ", ";
		}
		std::cout << "\n\n";


		int min = std::min(arr[0], arr[size - 1]);
		int max = std::max(arr[0], arr[size - 1]);


		// how to know the size of array;
		int var = 10;
		std::cout << sizeof(var) << "\n";
		std::cout << sizeof(int) << "\n";
		std::cout << sizeof(float) << "\n";
		std::cout << sizeof(double) << "\n";
		std::cout << sizeof(char) << "\n";
		std::cout << sizeof(bool) << "\n";

		std::cout << sizeof(arr) << "\n\n"; // (!!!) 10 elements * byrtes of the type size

		int bytesInArray = sizeof(arr); // 10 el * 4 bytes
		int bytesInIntegerType = sizeof(int); // 4

		int foundedSize = bytesInArray / bytesInIntegerType;
		std::cout << foundedSize << "\n\n";


		// loop for each
		for (int el : arr)
		{
			std::cout << el << ", ";
		}
		std::cout << "\n\n";

	}


	// std::array
	{
		int const size = 20;
		std::array<float, size> arr{};
		arr[5] = 123;

		std::cout << arr.size() << "\n";

		// loop for each
		for (int el : arr)
		{
			std::cout << el << ", ";
		}
		std::cout << "\n\n\n\n\n";

	}


	// Завдання 5. Стиснути (зрушити елементи) масиву, 
	// видаливши з нього всі 0, і заповнити звільнені праворуч
	// елементи значеннями - 1.
	{
		int arr[] = { 1, 5, 0, 3, 7, 0, 9, 0, 6, 2, 0 };
		int size = sizeof(arr) / sizeof(int);

		std::cout << arr[size - 1] << "\n";

		for (int i = 0; i < size; i++)
		{
			std::cout << arr[i] << ", ";
		}
		std::cout << "\n";

		for (int i = 0; i < size; i++)
		{
			for (int j = i; j < size; j++)
			{
				if (j < size - 1 && arr[j] == 0)
				{
					int zero = arr[j];
					arr[j] = arr[j + 1];
					arr[j + 1] = zero;
				}
			}
		}

		// print
		for (int i = 0; i < size; i++)
		{
			std::cout << arr[i] << ", ";
		}
		std::cout << "\n\n";
	}



	// Завдання 3. В одновимірному масиві випадкових чисел, 
	// що складається з 10 елементів, обчислити: 
	// 1) кількість елементів масиву, рівних 0;
	// 2) суму елементів масиву, розміщених після останнього мінімального елемента, не нуля.
	{
		const int size = 10;

		int arr[size] = { 4, 7, 0, 3, 1, 9, 0, 1, 2, 3 };

		int countOfZeroElements = 0;

		for (int el : arr)
		{
			if (el == 0)
			{
				countOfZeroElements++;
			}
		}
		std::cout << "Count of zeroes: " << countOfZeroElements << "\n";

		int minElIndex = size - 1;
		int minEl = arr[size - 1];
		for (int i = size - 1; i >= 0; i--)
		{
			if (minEl > arr[i] && arr[i] != 0)
			{
				minEl = arr[i];
				minElIndex = i;
			}
		}

		int sum = 0;
		for (int i = minElIndex; i < size; i++)
		{
			sum += arr[i];
		}

		std::cout << sum << "\n\n";
	}
}





//// formula for rand() with min and max
//int min = 10;
//int max = 15;
//int randBetweenZeroAndTen = rand() % (max - min + 1) + min;