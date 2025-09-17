#include <iostream>

int main()
{
	{
		int val = 42;
		int* p1 = &val; // pointer to value 42
		int* p2 = &val; // pointer to value 42
		int* p3 = p2;	// pointer to value 42. It's not pointer to p2

		std::cout
			<< p3 // address of 42
			<< " - "
			<< *p3 // value 42 
			<< std::endl;

		p2 = nullptr;
		p1 = nullptr;

		// вище у нас не поінтери на val, а поінтери на одну й ту ж адресу


		int** pointerToPointer = &p3; // pointer to pointer to value 42
		std::cout << pointerToPointer // address of p3
			<< " - "
			<< *pointerToPointer // address of 42
			<< " - "
			<< **pointerToPointer // value 42
			<< std::endl;


		int arr[] = { 1, 2, 3 };
		//int* pArr = arr; // poinrer on the first element of array
		int* pArr = &arr[0]; // poinrer on the first element of array (the same operation)
		pArr++; // now pointer on the second element of array

		pArr--; // now pointer on the first element of array

		//delete[] pArr; // Runtime Error - we can delete only memory allocated by new
	}


	{
		int* pValue = new int{ 123 };
		int* pArr = new int[10] { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

		int* p = pArr;
		delete pValue;
		delete[] p;

		std::cout << "";
	}
}
