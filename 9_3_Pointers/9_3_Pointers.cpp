
#include <iostream>

int* allocateMemoryArrayAndGetPointer(int size);
void allocateMemoryArrayForRefPointer(int*& pointer, int size);

void initArr(int* arr, const int size);
void printArr(int* arr, const int size);

void addElementToTheEndOfArray(int*& arr, int& size, int el);

void deleteMemoryArray(int*& arr);

int main()
{
	int size = 5;

	int* pArr = allocateMemoryArrayAndGetPointer(size);

	int* pAnotherArr;
	allocateMemoryArrayForRefPointer(pAnotherArr, size);

	initArr(pArr, size);
	initArr(pAnotherArr, size);
	printArr(pArr, size);
	printArr(pAnotherArr, size);

	addElementToTheEndOfArray(pArr, size, 60);
	printArr(pArr, size);
	//printArr(pAnotherArr, size);

	deleteMemoryArray(pArr);
	deleteMemoryArray(pArr);
	deleteMemoryArray(pAnotherArr);
	deleteMemoryArray(pAnotherArr);
	deleteMemoryArray(pAnotherArr);
	deleteMemoryArray(pAnotherArr);
	deleteMemoryArray(pAnotherArr);
}

int* allocateMemoryArrayAndGetPointer(int size)
{
	int* p = new int[size] {};

	return p;
}

void allocateMemoryArrayForRefPointer(int*& pointer, int size)
{
	pointer = new int[size];
}

void initArr(int* arr, const int size)
{
	for (int i = 0; i < size; i++)
	{
		arr[i] = (i + 1) * 10;
	}
}

void printArr(int* arr, const int size)
{
	for (int i = 0; i < size; i++)
	{
		std::cout << arr[i] << ", ";
	}

	std::cout << "\n\n";
}

void addElementToTheEndOfArray(int*& arr, int& size, int el)
{

	int* tempArr = new int[size];
	for (int i = 0; i < size; i++)
	{
		tempArr[i] = arr[i];
	}

	deleteMemoryArray(arr);

	int newSize = size + 1;
	allocateMemoryArrayForRefPointer(arr, newSize);

	for (int i = 0; i < size; i++)
	{
		arr[i] = tempArr[i];
	}

	arr[newSize - 1] = el;
	size++;

	deleteMemoryArray(tempArr);
}

void deleteMemoryArray(int*& arr)
{
	if (arr != nullptr)
	{
		delete[] arr;
		arr = nullptr;
	}
}
