
#include <iostream>
#include<cstdarg>
using namespace std;


// Initialize and Print methods /////////////////////////
template <class T>
void initializeArray(T arr[], long size, int min, int max)
{
	// ���������� ���������� ����������
	for (int i = 0; i < size; i++)
	{
		arr[i] = rand() % (max - min + 1) + min;
	}

	cout << "\n\n\n";
}

template <class T>
void printArray(T arr[], long size, string tip = "No sorted array:\n")
{
	cout << tip;

	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}

	cout << "\n\n";
}
/////////////////////////////////////////////////////////





// Recursion Example
long int getFactorial(long int number)
{
	// ���� ��������� ������ ��������� �������� ����...
	if (number < 1)
	{
		return 0; // �� ��������� 0
	}
	// ���� ������������ �������� �������,
	// ���� ��� ���������� ����� �� ������.
	// (!!!) ����� �� � � ����� ������ � �������
	else if (number == 1)
	{
		return 1;
	}
	// ����-��� ���� ����� ������� ������� ������
	// � �������� number - 1
	else
	{
		return number * getFactorial(number - 1); // 5 * 4 * 3...
		// �� ���, ��� ���� ���� ��������� ���:
		// ����� number == 5, ���... :
		// 5 * getFactorial( (5 - 1) *
		//  getFactorial( (4 - 1) *
		//  getFactorial( (3 - 1) * 
		//  getFactorial( (2 - 1) *
		//  ... return 1; ))) );
	}
}



// Quick Sort Example
template <class T>
void quickSortWithRecursion(T arr[], long size)
{
	// �� ���� � ����� arr[], 
	// arr[size - 1] � ���� ������� �������.

	long i = 0; // i - �� "����" ������ � ����������������� ���� ���� �������
	long j = size - 1; // j - �� "������" ������ � ����������������� ���� ������ �����

	T middleEl = arr[size / 2]; // ����������� �������
	// �����, ���������, size == 8 ��� 9. ��� 8/2 ��� 9/2 == 4 - ������ ��������.
	// � �����, ���������, size == 10, ��� 10/2 == 5 - ������ ��������.

	// ��������� ����� 
	do // ����� ����� i <= j
	{
		// ���� ������� ���� �� ������ ������� (middleEl ��� arr[size / 2])
		// �� ����� ������������ �������� �������, �� ����� ������ (i++)
		while (arr[i] < middleEl)
		{
			i++;
		}

		// ���� ������� ������ �� ������ ������� (middleEl ��� arr[size / 2])
		// �� ����� ������������ �������� �������, �� ����� ���� (i--)
		while (arr[j] > middleEl)
		{
			j--;
		}

		// ���� ��� ��� i <= j, ��:
		if (i <= j)
		{
			// ������ �������� ������ �� ��������� i �� j
			T temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;

			// ������ ������ �� ���� �� �����
			i++;
			j--;
		}

	} while (i <= j);

	/* ��������� �������, ���� � �� ��������� */
	// �����, ���� ������ ���� �� �� �����������,
	// �� �������� ������� - �������� ���� ����� � �����,
	// � ����� j - ���� ��������� ������ size �� ������ 
	// ������� ������ � ��� �������
	if (j > 0)
	{
		quickSortWithRecursion(arr, j);
	}

	// �����, ���� ���� ������� �� �� �����������,
	// �� �������� ������� - �������� ���� ����� � �����,
	// � ����� i - ���� ��������� ������ size �� ������ 
	// ������� ������ � ��� �������
	// ����������� (�, �� ����������) ������ arr + i (����� + �����, ���) - 
	// ��������� ����� �� i.
	// �����, ���������, � ����� {1, 2, 3, 4, 5} - ����� size == 5.
	// ��� �������� ���� � ����� �� ���� methodName(arr, size) ��� ���� �� ��������.
	// � ��� �������� �� (arr + 3, size - 3) ����� ������� ������ {4, 5}
	if (i < size)
	{
		quickSortWithRecursion(arr + i, size - i);
	}
}





// �������� ����� (Binary Search)
// ���� �� ��� - ������� ����� ������ Ҳ���� � ������������ �������
// ���� ����� ��� �������� - ����� ������������� ����������

// �����������  ����������
template <class T>
void bubbleSort(T arr[], long size)
{
	T tempElement;
	for (int i = 0; i < size; i++) // ���� �� 0 �� size
	{
		for (int j = size - 1; j > i; j--) // ���� �� size - 1 �� i
		{
			// ����, ������ ������� ��� �� �������
			// ��� �� ���� � ����
			// ����, ��������� ��. ���� ������������.
			// ���:
			// ���� ��������� ��. ������ �� ��������
			if (arr[j - 1] > arr[j])
			{
				tempElement = arr[j - 1]; // ���������� ��. �����'����� ���������
				arr[j - 1] = arr[j]; // ��������� �����'����� ��������
				arr[j] = tempElement; // �������� �����'����� ��������� (�������� � tempElement)
			}
		}
	}
}



// ���� �� ��� - ������� ����� ������ Ҳ���� � ������������ �������
int binarySearch(int sortedArr[], int left, int right, int key)
{
	while (true)
	{
		// ������ ����������� ������ � ������� left �� right 
		int middleIndex = (left + right) / 2;

		// key - �������� ��� ������ ������ � �������� � arr[]
		// ���� ���� ������ �� ����������� �������
		// �� right ������ �������� ������������ ��������
		if (key < sortedArr[middleIndex])
		{
			right = middleIndex - 1;
		}
		// ���� ���� ������ �� ����������� �������
		// �� left ������ �������� ������������ ��������
		else if (key > sortedArr[middleIndex])
		{
			left = middleIndex + 1;
		}
		// ����� ����� �� 2 if �� else if ���� �� ��������� �����
		// � 2 ����.
		// ��������� size � ������ == 100.
		// 100 / 2;
		// 50 / 2;
		// 25 / 2;
		// 12 / 2;
		// 6 / 2;
		// 3 / 2;
		// 1 / 2;
		// ���� ������ �������� 7 ��������


		// ���� ���� == �������� �������� ������ - ��������� ���� ������
		else
		{
			return middleIndex;
		}

		// ���� ���� ����� �� ������ - ��������� -1
		if (left > right)
		{
			return -1;
		}
	}
}




// �������, �� ������ ����������������� ���������
// ����� ��������� �������� #include<cstdarg>

/*
   ��� ������� ����, �� ������� ������ ����������
   ������� ���������, ������� ������� ...
   � ����� ������� � ���� ������ �������� � ��
   numOfArgs
   ��� �������� ������ ����� ��������� ������
   ���������
*/

// numOfArgs - � ������ ������� �� ������� ���������
// ��������� getMin(3, 5, 7, 9) - �� numOfArgs == 3, � ... == 5, 7, 9
// ��������� �� ��. ������������ :
// https://learn.microsoft.com/ru-ru/cpp/c-runtime-library/reference/va-arg-va-copy-va-end-va-start?view=msvc-170
int getMin(int numOfArgs, ...) // numOfArgs - � ������ ������� �� ������� ���������
{
	// ��'������� va
	va_list va;

	// ���������� va ��� ������� �� ������ ���������
	// numOfArgs � ���������� ������ ��������, ����� ������� ���� ���������
	va_start(va, numOfArgs);
	// ����� va == ������� ���������, �������� �� ��������� ���������

	// �������� ����� �������� � ������
	// �� ������, �� ����� min == ������� ���������
	int min = va_arg(va, int);

	/*
	   �� ��� �������� ����� �������� � ������.
	   ���� ���� �� ������ ���� �� numOfArgs � 1
	*/
	for (int i = 0; i < numOfArgs - 1; i++)
	{
		// � ���� �������� ���� �������� �� �����
		int nextParameter = va_arg(va, int);

		// �������� ����� ������ ����������
		if (min > nextParameter)
		{
			min = nextParameter;
		}
	}

	// �������� ���������� ������ � ������� ������
	va_end(va);

	// ���������� ��������
	return min;
}


int main()
{
	srand(time(0));

	// Recursion Example
	cout << "Recursion Example\n";
	cout << getFactorial(5) << "\n\n";
	// /////////////////////////////////////////////////////////////////

	const long SIZE = 10;
	int arr[SIZE];

	initializeArray(arr, SIZE, 0, 9);
	printArray(arr, SIZE);

	// Quick Sort Example
	cout << "quickSortWithRecursion:\n";
	quickSortWithRecursion(arr, SIZE);

	printArray(arr, SIZE, "Sorted array:\n");
	////////////////////////////////////////////////////////////////


	initializeArray(arr, SIZE, 0, 9);
	printArray(arr, SIZE);

	// Bubble Sort Example
	cout << "bubbleSort:\n";
	bubbleSort(arr, SIZE);

	// ���� ���������� 
	printArray(arr, SIZE, "Sorted array:\n");
	////////////////////////////////////////////////////////////////



	//// This is a very simple example how is working binary search
	//int x = 100000000;

	//while (x != 1)
	//{
	//	x = x / 2;
	//	cout << x << endl;
	//}
	// ////////////////////////////////////////////////////////////

	//// This is a very simple example how is working linear search
	//for (int i = 0; i < x; i++)
	//{
	//	if (i == 99999999)
	//	{
	//		cout << "i == " << i << endl;
	//	}
	//}



	// �������� ����� (Binary Search)
	cout << "Binary Search:\n";
	int key;
	cout << "Enter any digit: ";
	cin >> key;

	cout << "Index - " << binarySearch(arr, 0, SIZE, key) << "\n\n\n";
	///////////////////////////////////////////////////////////////////


	// ������� � ��������� ���������� ������� ��������� � �����
	// �������, �� ������ ����������������� ���������
	// ����� ��������� �������� #include <cstdarg>
	cout << "Example with params using library <cstdarg>\n";
	int result = getMin(5, 10, -33, -1, 4, 9); // 5 - � ������ ������� �� ������� ���������
	cout << "Minimum is: " << result << "\n\n\n";

	// Such things 0_o...
}