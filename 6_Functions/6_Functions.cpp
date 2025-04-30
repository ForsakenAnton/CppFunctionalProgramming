
#include <iostream>
#include <Windows.h>

void greeting(std::string text, bool isTabulation, int times = 5);
int plus(int left, int right, bool convertToABS = false);
double plus(double left, double right);
int toABS(int);

void changeValue(int value);

// arrays and methods...
void initArr(int arr[], int size, int min = 1, int max = 10);
void printArr(int arr[], int size);

void initMatrix(int matrix[][4], int rows, int cols, int min = 1, int max = 10);
void printMatrix(int matrix[][4], int rows, int cols);

template<int ROWS, int COLS>
void printMatrix(int matrix[ROWS][COLS]);

int main()
{
	std::srand(std::time(nullptr));

	SetConsoleOutputCP(1251); // cout
	SetConsoleCP(1251); // cin

	greeting("hello", true, 10);
	greeting("Hello 5 times", false);
	greeting("Hello 100500 times", false, 100500);

	int plusResult = plus(3, 4);
	std::cout << "plusResult: " << plusResult << "\n";
	std::cout << "plusResult: " << plus(3, 4) << "\n";
	std::cout << "plusResult: " << plus(-3, -4, false) << "\n";
	std::cout << "plusResult: " << plus(-3, -4, true) << "\n";
	std::cout << "plusResult: " << plus(3.0, 4.0) << "\n";

	int value = 123;
	changeValue(value);
	std::cout << value << "\n\n\n";

	// arrays and methods...
	const int size = 3;
	const int rows = 3;
	const int cols = 4;

	int arr[size] = {};
	initArr(arr, size);
	printArr(arr, size);



	int matrix[rows][cols] = {};
	initMatrix(matrix, rows, cols);
	printMatrix(matrix, rows, cols);

	// call templated printMatrix<int, int>(arr[int][int])
	printMatrix<rows, cols>(matrix);
}


void greeting(std::string text, bool isTabulation, int times)
{
	const int maxTimes = 20;

	for (int i = 0; i < times; i++)
	{
		if (i == maxTimes)
		{
			//break;
			return;
		}

		isTabulation ?
			std::cout << "\t" << text << "\n" :
			std::cout << text << "\n";
	}

	std::cout << "End of 'greeting()'\n\n";
}

int plus(int left, int right, bool convertToABS)
{
	static int callMethodCount = 0;

	if (convertToABS)
	{
		left = toABS(left);
		right = toABS(right);
	}

	int result = left + right;

	callMethodCount++;

	return result;
}

double plus(double left, double right)
{
	double result = left + right;

	return result;
}

int toABS(int value)
{
	return std::abs(value);
}

void changeValue(int value) // copy of variable
{
	value = 456;
}



// arrays and methods...

void initArr(int arr[], int size, int min, int max)
{
	for (int i = 0; i < size; i++)
	{
		arr[i] = std::rand() % (max - min) + min;
	}
}

void printArr(int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		std::cout << arr[i] << ", ";
	}

	std::cout << "\n\n";
}

void initMatrix(int matrix[][4], int rows, int cols, int min, int max)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			matrix[i][j] = std::rand() % (max - min) + min;
		}
	}
}

void printMatrix(int matrix[][4], int rows, int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			std::cout << matrix[i][j] << ", ";
		}

		std::cout << "\n";
	}

	std::cout << "\n\n";
}

template<int ROWS, int COLS> 
void printMatrix(int matrix[ROWS][COLS])
{
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			std::cout << matrix[i][j] << ", ";
		}

		std::cout << "\n";
	}

	std::cout << "\n\n";
}
