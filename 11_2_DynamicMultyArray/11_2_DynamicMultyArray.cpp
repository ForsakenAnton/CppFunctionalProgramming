
#include <iostream>

template<typename T>
void allocateOneDimArr(T*& const arr, const int size)
{
	arr = new T[size] {};
}

template<typename T>
void deleteOneDimArr(T*& const arr)
{
	if (arr != nullptr)
	{
		delete[] arr;
		arr = nullptr;
	}
	else
	{
		std::cout << "Array is already removed!" << std::endl;
	}
}

template <typename T>
void initOneDimArr(T* const arr, const int size, T defaultValue = T())
{
	for (int i = 0; i < size; i++)
	{
		arr[i] = defaultValue == T() ? i : defaultValue;
	}
}

template <>
void initOneDimArr(double* const arr, int size, double defaultValue)
{
	for (int i = 0; i < size; i++)
	{
		arr[i] = defaultValue;
	}
}

template <typename T>
void printOneDimArr(T* const arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		std::cout << arr[i] << ", ";
	}
	std::cout << std::endl;
}


template<typename T>
void allocateTwoDimArr(T**& const pointer, const int rows, const int cols)
{
	pointer = new T * [rows] {};

	for (int i = 0; i < rows; i++)
	{
		allocateOneDimArr(pointer[i], cols);
	}
}

template<typename T>
void deleteTwoDimArr(T**& const arr, const int rows)
{
	if (arr != nullptr)
	{
		for (int i = 0; i < rows; i++)
		{
			deleteOneDimArr(arr[i]);
		}

		delete[] arr;
		arr = nullptr;
	}
	else
	{
		std::cout << "Array is already removed!" << std::endl;
	}
}

template <typename T>
void initTwoDimArr(T** const arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++)
	{
		initOneDimArr(arr[i], cols);
	}
}

template <typename T>
void printTwoDimArr(T** const arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++)
	{
		printOneDimArr(arr[i], cols);
	}
	std::cout << std::endl;
}


template<typename T>
void cloneOneDimArr(T* const dest, T* const src, const int size)
{
	for (int i = 0; i < size; i++)
	{
			dest[i] = src[i];
	}
}

template<typename T>
void cloneMatrix(T** const dest, T** const src, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			dest[i][j] = src[i][j];
		}
	}
}


template <typename T>
void insertRowIntoMatrix(
	T**& const arr, 
	int& rows, 
	const int cols,
	const int insertRowIndex,
	const T columnValue)
{
	if (insertRowIndex > rows || insertRowIndex < 0)
	{
		std::cout << "InsertRowIndex is out of range!" << std::endl;
		
		return;
	}


	T** newArr = nullptr;
	int newRows = rows + 1;
	allocateTwoDimArr(newArr, newRows, cols);

	for (int oldIndex = 0, newIndex = 0; newIndex < newRows; newIndex++)
	{
		if (newIndex == insertRowIndex)
		{
			initOneDimArr(newArr[newIndex], cols, columnValue);
			continue;
		}

		cloneOneDimArr(newArr[newIndex], arr[oldIndex], cols);
		oldIndex++;
	}

	deleteTwoDimArr(arr, rows);
	arr = newArr;
	rows++;
	//deleteTwoDimArr(newArr, newRows); // Wrong Way !!!!!
	newArr = nullptr; // not neccessary
}

int main()
{
	int rows = 4;
	int cols = 3;

	double** twoDimArr = nullptr;
	allocateTwoDimArr(twoDimArr, rows, cols);
	initTwoDimArr(twoDimArr, rows, cols);
	printTwoDimArr(twoDimArr, rows, cols);

	// Завдання 3. 
	// Написати функцію, 
	// що додає рядок двовимірному масиву в зазначену позицію.

	insertRowIntoMatrix(twoDimArr, rows, cols, 2, 2.0);
	printTwoDimArr(twoDimArr, rows, cols);

	insertRowIntoMatrix(twoDimArr, rows, cols, 2, 3.0);
	printTwoDimArr(twoDimArr, rows, cols);

	insertRowIntoMatrix(twoDimArr, rows, cols, -1, 123.0);
	printTwoDimArr(twoDimArr, rows, cols);

	insertRowIntoMatrix(twoDimArr, rows, cols, 10, 123.0);
	printTwoDimArr(twoDimArr, rows, cols);

	insertRowIntoMatrix(twoDimArr, rows, cols, 0, 4.0);
	printTwoDimArr(twoDimArr, rows, cols);

	insertRowIntoMatrix(twoDimArr, rows, cols, 8, 8.0);
	printTwoDimArr(twoDimArr, rows, cols);

	insertRowIntoMatrix(twoDimArr, rows, cols, 7, 8.0);
	printTwoDimArr(twoDimArr, rows, cols);

	deleteTwoDimArr(twoDimArr, rows);
	deleteTwoDimArr(twoDimArr, rows);
	deleteTwoDimArr(twoDimArr, rows);
}