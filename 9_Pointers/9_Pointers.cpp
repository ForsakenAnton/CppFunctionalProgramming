
#include <iostream>

//void swap(int left, int right)
//{
//	int temp = left;
//	left = right;
//	right = temp;
//}

void swap(int& left, int& right)
{
	int temp = left;
	left = right;
	right = temp;
}

void swap(int* left, int* right)
{
	int temp = *left;
	*left = *right; // (!!!)
	*right = temp;

	left = nullptr;
	right = nullptr;
}

void initArr(int* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		//*(arr + i) = i * 10;
		arr[i] = i * 10;
	}
}

void printArr(int* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		//std::cout << *(arr + i) << ", ";
		std::cout << arr[i] << ", ";
	}

	std::cout << "\n\n";
}

template<int Cols>
void printMatrix(int (*arr)[Cols], int rows)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			std::cout << arr[i][j] << ", ";
		}

		std::cout << "\n";

	}

	std::cout << "\n\n";
}


// about nullptr and NULL
void checkIfPointerIsNull(int* p)
{
	if (p == nullptr)
	{
		std::cout << "nullptr\n";
	}
	if (p == NULL)
	{
		std::cout << "NULL\n";
	}
	if (p == 0)
	{
		std::cout << "0\n";
	}
}

int main()
{
	// pointers
	std::cout << "Pointers\n";

	int variable = 42;
	std::cout << "Value: " << variable << "\n";
	std::cout << "Value's Memory: " << &variable << "\n\n";

	int* pVariable = &variable;
	std::cout << "Variable's Memory (from pointer): " << pVariable << "\n";
	std::cout << "Pointer's Memory: " << &pVariable << "\n";
	std::cout << "Pointer's Value (from variable): " << *pVariable << "\n\n";

	*pVariable = 123;

	std::cout << *pVariable << "\n";
	std::cout << variable << "\n\n";

	int* anotherPointer = pVariable;

	*anotherPointer = 456;
	std::cout << *pVariable << "\n";
	std::cout << variable << "\n";
	std::cout << *anotherPointer << "\n\n";

	std::cout << pVariable << "\n";
	std::cout << &variable << "\n";
	std::cout << anotherPointer << "\n\n";

	std::cout << &pVariable << "\n";
	std::cout << &variable << "\n";
	std::cout << &anotherPointer << "\n\n";

	pVariable = nullptr;
	std::cout << &pVariable << "\n";
	std::cout << &variable << "\n";
	std::cout << &anotherPointer << "\n\n";

	if (pVariable != nullptr)
	{
		std::cout << *pVariable << "\n";
	}
	std::cout << variable << "\n";
	std::cout << *anotherPointer << "\n\n";
	std::cout << anotherPointer[0] << "\n\n";
	//std::cout << anotherPointer[1] << "\n\n";


	const int size = 5;
	int arr[size] = { 3, 4, 5, 6, 7 };
	int* pArr = arr; // 1 option
	//int* pArr = &arr[0]; // 2 option
	std::cout << pArr << "\n";
	std::cout << &pArr[1] << "\n";
	std::cout << arr << "\n";
	std::cout << &arr[0] << "\n";
	std::cout << *pArr << "\n";
	std::cout << pArr[0] << "\n\n";

	std::cout << *pArr << "\n";
	std::cout << *pArr + 123 << "\n";
	std::cout << *(pArr + 0) << "\n";
	std::cout << *(pArr + 1) << "\n";
	std::cout << *(pArr + 2) << "\n";
	std::cout << *(pArr + 3) << "\n";
	std::cout << *(pArr + 4) << "\n";

	// (!!!)
	for (int i = 0; i < size; i++)
	{
		std::cout
			<< pArr[i] << " - "
			<< *(pArr + i) << " - "
			<< arr[i] << " - "
			<< *(arr + i) << "\n";
	}
	std::cout << "\n\n";

	// (!!!)
	for (int i = 0; i < size; i++)
	{
		std::cout
			<< &pArr[i] << " - "
			<< &arr[i] << "\n";
	}
	std::cout << "\n\n";

	for (int i = 0; i < size; i++)
	{
		std::cout << *pArr++ << "\n";
	}

	pArr = pArr - size;

	std::cout << *pArr << "\n\n";


	int left = 3;
	int right = 4;
	::swap(left, right);
	std::cout << left << " - " << right << "\n\n";

	int* pLeft = &left;
	int* pRight = &right;
	::swap(pLeft, pRight);
	std::cout << left << " - " << right << "\n\n";
	std::cout << *pLeft << " - " << *pRight << "\n\n";


	::swap(left, right);
	std::cout << left << " - " << right << "\n\n";
	std::cout << *pLeft << " - " << *pRight << "\n\n";


	// ... continue work with arr and pArr above
	//initArr(arr, size);
	//printArr(arr, size);
	initArr(pArr, size);
	printArr(pArr, size);
	printArr(arr, size);



	// two-dimensional arrays and pointers;
	const int rows = 2;
	const int cols = 3;

	int matrix[rows][cols] =
	{
		{3, 4, 5},
		{6, 7, 8},
	};

	int (*pMatrix)[cols] = matrix;
	// pMatrix[0] == {3, 4, 5};
	// pMatrix[1] == {6, 7, 8};
	//pMatrix++;
	std::cout << pMatrix[0][0] << "\n";
	std::cout << pMatrix[0][1] << "\n";
	std::cout << pMatrix[0][2] << "\n";
	std::cout << pMatrix[1][0] << "\n";

	printArr(pMatrix[0], cols);
	printArr(pMatrix[1], cols);

	printMatrix(pMatrix, rows);



	// about nullptr and NULL
	int* p = nullptr;

	checkIfPointerIsNull(p);

	int var = 42;
	p = &var;
	checkIfPointerIsNull(p);
	*p = 100;
	checkIfPointerIsNull(p);
	p = nullptr; // NULL; //0;
	checkIfPointerIsNull(p);



	// references
}
