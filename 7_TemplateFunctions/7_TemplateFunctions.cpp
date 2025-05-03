
#define SUM(x, y) x + y
#define PRINT(param) std::cout << param << std::endl;
#define VEIRD_PRINT(param) << param << std::endl;
#define PI 3.14

#include <iostream>

template<typename T>
T sum(T left, T right);

template<typename T>
T minus(T left, T right);

template<>
std::string minus(std::string left, std::string right);


template<typename T, int ROWS, int COLS>
void initMatrix(T matrix[ROWS][COLS]);

template<typename T, int ROWS, int COLS>
void printMatrix(T matrix[ROWS][COLS]);

template<typename T, int ROWS, int COLS>
void printMatrixUsingRef(T (&matrix)[ROWS][COLS]);



template<typename T>
T sum(T left, T right)
{
	T result = left + right;

	return result;
}

template<typename T>
T minus(T left, T right)
{
	T result = left - right;

	return result;
}

template<>
std::string minus(std::string left, std::string right)
{
	int leftLength = left.length();
	int rightLength = right.length();

	std::string resultString = left.substr(0, leftLength - rightLength);

	return resultString;
}


template<typename T>
T minusUsing_IsSameMethod(T left, T right)
{
	std::cout << std::is_same<T, int>().value << "\n";

	T result = T{};

	if constexpr (std::is_same<T, int>().value ||
		std::is_same<T, double>().value ||
		std::is_same<T, float>().value ||
		std::is_same<T, char>().value)
	{
		result = left - right;
	}
	else if constexpr (std::is_same<T, std::string>().value)
	{
		int leftLength = left.length();
		int rightLength = right.length();

		result = left.substr(0, leftLength - rightLength);
	}


	return result;
}


template<typename T, int ROWS, int COLS> // ROWS and COLS are Non-Type parameters
void initMatrix(T matrix[ROWS][COLS])
{
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			if constexpr (std::is_same<T, int>().value)
			{
				matrix[i][j] = std::rand() % (10 - 1) + 1;
			}
			else if constexpr (
				std::is_same<T, double>().value ||
				std::is_same<T, float>().value)
			{
				matrix[i][j] = (T)std::rand() / RAND_MAX * 10;
			}
		}

		std::cout << "\n";
	}

	std::cout << "\n\n";
}

template<typename T, int ROWS, int COLS> // ROWS and COLS are Non-Type parameters
void printMatrix(T matrix[ROWS][COLS])
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


template<typename T, int ROWS, int COLS>
void printMatrixUsingRef(T(&matrix)[ROWS][COLS])
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


int main()
{
	std::srand(std::time(0));

	int sumResult = SUM(3, 4);

	std::cout << sumResult << "\n";
	std::cout << SUM(3.3, 4.4) << "\n";
	std::cout << SUM(3.3F, 4.4F) << "\n";
	std::cout << SUM('3', '4') << "\n";

	PRINT(123);
	std::cout VEIRD_PRINT(456) "\n\n\n\n";

	float pi = PI;
	//PI = 123.123; 4.14 = 123.123




	std::cout << sum(3, 4) << "\n";
	std::cout << sum(3.4, 4.4) << "\n";

	std::string str1 = "3.4";
	std::string str2 = "4.4";
	std::cout << sum(str1, str2) << "\n\n\n";


	std::cout << minus<int>(3, 4) << "\n";

	std::string first = "Templates in C++";
	std::string second = " in C++";
	std::cout << minus(first, second) << "\n";


	// is_same<T, ConcreteType>
	std::cout << minusUsing_IsSameMethod<int>(3, 4) << "\n";
	std::cout << minusUsing_IsSameMethod(first, second) << "\n";

	const int rows = 2;
	const int cols = 3;

	int integerArr[rows][cols] = {};
	initMatrix<int, rows, cols>(integerArr);
	printMatrix<int, rows, cols>(integerArr);

	float floatArr[rows][cols] = {};
	initMatrix<float, rows, cols>(floatArr);
	printMatrix<float, rows, cols>(floatArr);

	// off top
	printMatrixUsingRef(floatArr);
}
