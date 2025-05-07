
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <algorithm>
#include <chrono>
using namespace std;

// ������� ������, �� �� ��������� �������� <chrono>
// ���������� ��� ����������� ��� ��������� ������� ������
// std::chrono::steady_clock::time_point - �� ���, ���� �����������, ���
// ��� �� ��� ����� ������� ����� auto, ����, ����� � ���:
// auto getTime() { ... }

std::chrono::steady_clock::time_point getCurrentTime()
{
	auto currentTime = std::chrono::high_resolution_clock::now();
	return currentTime;
}

std::chrono::microseconds calculateDuration(
	std::chrono::steady_clock::time_point end_time,
	std::chrono::steady_clock::time_point start_time)
{
	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time);
	return duration;
}
// /////////////////////////////////////////////////////////////////////////////////////////////

// ����������� �� ������ ����� /////////////////////////
template <class T>
void initializeArray(T arr[], long size)
{
	// ���������� ����������� ����������
	for (int i = 0; i < size; i++)
	{
		arr[i] = rand() % 100;
	}

	cout << "\n\n\n";
}

template <class T>
void printArray(T arr[], long size, string tip = "Non sorted array:\n")
{
	cout << tip;

	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}

	cout << "\n\n";
}
/////////////////////////////////////////////////////////

// ���������� �������
template <typename T, int size>
void selectSort(T (&a)[size], bool asc = true)
{
	int indexOfMinElement; // ������ ���������� �������� ������
	T minElementOfArr; // ��������� ������� ������

	for (int i = 0; i < size; i++)
	{
		indexOfMinElement = i; // ����� ������ ���������� �������� ������ == i
		minElementOfArr = a[i]; // ����� ��������� ������� ������ == a[i]

		// ���� ������ ���������� �������� 
		for (int j = i + 1; j < size; j++)
		{
			if (asc ? a[j] < minElementOfArr : a[j] > minElementOfArr) // �������� ��������� ��. ������� ������
			{
				indexOfMinElement = j; // �����'������� ���� ������
				minElementOfArr = a[j]; // �����'������� ���� ��������
			}
		}

		// ���� ������ ��������, � ����� ��� ����������, �� �������
		// �������, ���� (�������) ������������� � ����������� ����
		if (indexOfMinElement != i)
		{
			// � ������� � ��������� ��������� ���������
			// �������� �������, � ����� ��� ����������
			a[indexOfMinElement] = a[i];

			// � �������, � ����� ��� ����������
			// �������� ��������� ��������� �������
			a[i] = minElementOfArr;
		}
	}
}

// ����������� ����������
template <class T, int size>
void bubbleSort(T (&a)[size])
{
	T tempElement;
	for (int i = 0; i < size; i++) // ���� �� 0 �� size
	{
		for (int j = size - 1; j > i; j--) // ���� �� size - 1 �� i
		{
			// ����, ������ ������� ��� �� �������
			// ��� �� ���� � ����
			// ������ ��������� ������� ���� ������������.
			// ���:
			// ���� ��������� ������� ������ �� ��������
			if (a[j - 1] > a[j])
			{
				tempElement = a[j - 1]; // ���������� ������� �����'����� ���������
				a[j - 1] = a[j]; // ��������� �����'����� ��������
				a[j] = tempElement; // �������� �����'����� ��������� (�������� � tempElement)
			}
		}
	}
}

// ������-���������� (���������� ����������)
template <class T, int size>
void shakerSort(T (&a)[size])
{
	long index = size - 1;

	// ��� ������� ������, �� �� � ������������
	long leftIndex = 1;
	long rightIndex = size - 1;
	T tempElement;

	do
	{
		// ���� �� rightIndex �� > 0
		for (int i = rightIndex; i > 0; i--)
		{
			// ����, ������ ������� ��� �� �������
			// ��� �� ���� � ����
			// ������ ��������� ������� ���� ������������.
			// ���:
			// ���� ��������� ������� ������ �� ��������
			if (a[i - 1] > a[i])
			{
				tempElement = a[i - 1]; // ���������� ������� �����'����� ���������
				a[i - 1] = a[i]; // ��������� �����'����� ��������
				a[i] = tempElement; // �������� �����'����� ��������� (�������� � tempElement)

				index = i; // index �����'����� �������� i (������ ��� ������� ��������)
			}
		}

		// ����� � ���������� �������� ����,
		// ���� leftIndex ���� �������� index + 1
		leftIndex = index + 1;

		// ���� �� 1 �� <= rightIndex
		for (int i = 1; i <= rightIndex; i++)
		{
			// ���� ��������� ������� ������ �� ��������
			if (a[i - 1] > a[i])
			{
				tempElement = a[i - 1]; // ���������� ������� �����'����� ���������
				a[i - 1] = a[i]; // ��������� �����'����� ��������
				a[i] = tempElement; // �������� �����'����� ��������� (�������� � tempElement)

				index = i; // index �����'����� �������� i (������ ��� �������� ��������)
			}
		}
		rightIndex = index - 1;
	} while (leftIndex < rightIndex);
}

// ���������� ���������
template <class T, int size>
void insertSort(T (&a)[size])
{
	T currentElement;
	long i, j;
	// ���� �������, i � ����� ������� 
	for (i = 0; i < size; i++)
	{
		currentElement = a[i];
		// ����� ���� �������� � ������ �����������
		// ����� ���� j �����'����� ��������� ������ (i - 1)
		// � ���� >= 0
		// � ����� ���� ����� ����� �������, ��� � ����� ���
		// ������� ����� - ���� ��������� ������� ������ �� ��������
		// (���� �� ���� ������ �� ��� ������ �� ���� a[-1])
		// ����� ��� � ����-����� ������� ������������ j
		for (j = i - 1; j >= 0 && a[j] > currentElement; j--)
		{
			// ������� ������� ������� ���� �� �����
			// ����� �������� ������ ���������� �������� ��������� ��������
			a[j + 1] = a[j];
		}

		// ���� ��������, �������� �������
		// ����� � �������� ������� �������� ������ 
		// � ����-����� ������� ���������� �������� ��������� ��������
		a[j + 1] = currentElement;
	}
}


template <class T>
void setMin(T a[], long size)
{
	T min = a[0]; // ����� min ���� ������ ���������

	// ��������� ���������
	for (int i = 1; i < size; i++)
	{
		if (a[i] < min)
		{
			min = a[i];
		}
	}

	a[0] = min; // � �������� ���� �� ����� ���� � �����
}

// �������� ������ (� ���������� ���������)
template <class T, int size>
void insertSortGuarded(T (&a)[size])
{
	T currentElement;
	long i, j;

	// �������� ������ ������ �������
	T backup = a[0];

	// ������� �� ��������� 
	setMin(a, size);

	// ����������� ����� 
	for (i = 1; i < size; i++)
	{
		currentElement = a[i];

		// ����� ���� �������� � ������ �����������
		// �� ���� j �����'����� ��������� ������ (i - 1)
		// � ���� >= 0
		// � ����� ���� ����� ����� �������, ��� � ����� ���
		// ������� ����� - ���� ��������� ������� ������ �� ��������
		// (���� �� ���� ������ �� ��� ������ �� ���� a[-1])
		// ����� ��� � ����-����� ������� ������������ j
		for (j = i - 1; a[j] > currentElement; j--)
		{
			// �������� ������ ���������� �������� ��������� ��������
			a[j + 1] = a[j];
		}

		// � �������� ������� �������� ������
		// � ����-����� ������� ���������� �������� ��������� ��������
		a[j + 1] = currentElement;
	}

	// �������� backup �� ��������� ����
	for (j = 1; j < size && a[j] < backup; j++)
	{
		// ����, ������� ����� �� 1 ���� ����
		// ���� a[j] < backup (����� ��� ������������!)
		// ���������, [min, 2, 4, 6, 8] ����� [2, 4, 6, 8, ...]

		a[j - 1] = a[j];
	}

	// ������� ��������
	// �, ������, ����� [2, 4, 6, 8, backup]!
	a[j - 1] = backup;
}


void main()
{
	srand(static_cast<unsigned long>(time(nullptr)));
	//const long SIZE = 5; // ��� �������
	const long SIZE = 1000; // ��� �������� ��������� �������� ���� ����������
	int arr[SIZE];

	// ��� ���������� �������� ��������� ������� ���������
	// ���� � ������, �� ���������� �� ��������
	std::chrono::steady_clock::time_point startTime;
	std::chrono::steady_clock::time_point endTime;
	//std::chrono::microseconds duration; // �� ������� - ���� ����� � cout << �� ������

	// ���������� ����������� ���������� �� �������� �� �����
	initializeArray(arr, SIZE);
	printArray(arr, SIZE);

	// ���������� �������
	cout << "selectSort:\n";
	startTime = getCurrentTime();
	selectSort<int, SIZE>(arr);
	//selectSort<int, SIZE>(arr, false);
	endTime = getCurrentTime();
	cout << "Duration: " << calculateDuration(endTime, startTime).count() << " microseconds\n\n";

	// ���� ����������
	printArray(arr, SIZE, "Sorted array:\n");
	////////////////////////////////////////////////////////////////////////////



		// ����� ���������� ����������� ���������� �� �������� �� �����
	initializeArray(arr, SIZE);
	printArray(arr, SIZE);

	// �����������  ����������
	cout << "bubbleSort:\n";
	startTime = getCurrentTime();
	bubbleSort<int, SIZE>(arr);
	endTime = getCurrentTime();
	cout << "Duration: " << calculateDuration(endTime, startTime).count() << " microseconds\n\n";

	// ���� ����������
	printArray(arr, SIZE, "Sorted array:\n");
	////////////////////////////////////////////////////////////////////////////



		// ����� ���������� ����������� ���������� �� �������� �� �����
	initializeArray(arr, SIZE);
	printArray(arr, SIZE);

	// ������-����������(���������� ����������)
	cout << "shakerSort:\n";
	startTime = getCurrentTime();
	shakerSort(arr);
	endTime = getCurrentTime();
	cout << "Duration: " << calculateDuration(endTime, startTime).count() << " microseconds\n\n";

	// ���� ����������
	printArray(arr, SIZE, "Sorted array:\n");
	////////////////////////////////////////////////////////////////////////////



		// ����� ���������� ����������� ���������� �� �������� �� �����
	initializeArray(arr, SIZE);
	printArray(arr, SIZE);

	// ���������� ���������
	cout << "insertSort:\n";
	startTime = getCurrentTime();
	insertSort(arr);
	endTime = getCurrentTime();
	cout << "Duration: " << calculateDuration(endTime, startTime).count() << " microseconds\n\n";

	// ���� ����������
	printArray(arr, SIZE, "Sorted array:\n");
	////////////////////////////////////////////////////////////////////////////



		// ����� ���������� ����������� ���������� �� �������� �� �����
	initializeArray(arr, SIZE);
	printArray(arr, SIZE);

	// �������� ������ (� ���������� ���������)
	cout << "insertSortGuarded:\n";
	startTime = getCurrentTime();
	insertSortGuarded(arr);
	endTime = getCurrentTime();
	cout << "Duration: " << calculateDuration(endTime, startTime).count() << " microseconds\n\n";

	// ���� ����������
	printArray(arr, SIZE, "Sorted array:\n");
	////////////////////////////////////////////////////////////////////////////
}






//#include <iostream>
//#include <stdlib.h>
//#include <time.h>
//#include <string>
//#include <algorithm>
//#include <chrono>
//using namespace std;
//
//// ��������������� ������, ������� � ������� ���������� <chrono>
//// ������� ��� ���������� ����� ���������� ������� ������
//// std::chrono::steady_clock::time_point - ��� ������������ ���, ��
//// �� �� ��� ������ �������� ����� auto, ��� ��� ����� � ���:
//// auto getTime() { ... }
//
//std::chrono::steady_clock::time_point getCurrentTime()
//{
//	auto currentTime = std::chrono::high_resolution_clock::now();
//	return currentTime;
//}
//
//std::chrono::microseconds calculateDuration(
//	std::chrono::steady_clock::time_point end_time, 
//	std::chrono::steady_clock::time_point start_time)
//{
//	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time);
//	return duration;
//}
//// /////////////////////////////////////////////////////////////////////////////////////////////
//
//
//// Initialize and Print methods /////////////////////////
//template <class T>
//void initializeArray(T arr[], long size)
//{
//	// ��������� ���������� ����������
//	for (int i = 0; i < size; i++)
//	{
//		arr[i] = rand() % 100;
//	}
//
//	cout << "\n\n\n";
//}
//
//template <class T>
//void printArray(T arr[], long size, string tip = "No sorted array:\n")
//{
//	cout << tip;
//
//	for (int i = 0; i < size; i++)
//	{
//		cout << arr[i] << " ";
//	}
//
//	cout << "\n\n";
//}
///////////////////////////////////////////////////////////
//
//
//
//// ���������� �������
//template <class T>
//void selectSort(T a[], long size)
//{
//	int indexOfMinElement; // ������ ������������ ��. �������
//	T minElementOfArr; // ����������� ��. �������
//
//	for (int i = 0; i < size; i++)
//	{
//		indexOfMinElement = i; // ����� ������ ������������ ��. ������� == i
//		minElementOfArr = a[i]; // �����  ����������� ��.������� == a[i]
//
//		// ���� ������ ���������� �������� 
//		for (int j = i + 1; j < size; j++)
//		{
//			if (a[j] < minElementOfArr) // ���������� ������� ���. ������� �������
//			{
//				indexOfMinElement = j; // ���������� ��� ������
//				minElementOfArr = a[j]; // ���������� ��� ��������
//			}
//		}
//
//		// ���� ������ ��������, � �������� ��� ���������� �� �����
//		// �������, ������� (��������) ������������� �� ���������� �����
//		if (indexOfMinElement != i)
//		{
//			// � ������� � ��������� ����������� ���������
//			// ���������� �������, � �������� ��� ����������
//			a[indexOfMinElement] = a[i];
//
//			// � �������, � �������� ��� ����������
//			// ���������� ��������� ����������� �������
//			a[i] = minElementOfArr;
//		}
//	}
//}
//
//
//
//// �����������  ����������
//template <class T>
//void bubbleSort(T a[], long size)
//{
//	T tempElement;
//	for (int i = 0; i < size; i++) // ���� � 0 �� size
//	{
//		for (int j = size - 1; j > i; j--) // ���� �� size - 1 �� i
//		{
//			// ����, ������ ������� ����� ��� ���������
//			// ��� ��� ���� � �����
//			// ������ ��������� ��. ����� �������������.
//			// �����:
//			// ���� ��������� ��. ������ ��������
//			if (a[j - 1] > a[j])
//			{
//				tempElement = a[j - 1]; // ��������� ��. ���������� ���������
//				a[j - 1] = a[j]; // ��������� ���������� �������
//				a[j] = tempElement; // ������� ���������� ��������� (�������� � tempElement)
//			}
//		}
//	}
//}
//
//
//
//// ������-����������(���������� ����������)
//template <class T>
//void shakerSort(T a[], long size)
//{
//	long index = size - 1;
//
//	// ��� ������� ������, �� �� � ������������
//	long leftIndex = 1;
//	long rightIndex = size - 1;
//	T tempElement;
//
//	do
//	{
//		// ���� �� rightIndex �� > 0
//		for (int i = rightIndex; i > 0; i--)
//		{
//			// ����, ������ ������� ����� ��� ���������
//			// ��� ��� ���� � �����
//			// ������ ��������� ��. ����� �������������.
//			// �����:
//			// ���� ��������� ��. ������ ��������
//			if (a[i - 1] > a[i])
//			{
//				tempElement = a[i - 1]; // ��������� ��. ���������� ���������
//				a[i - 1] = a[i]; // ��������� ���������� �������
//				a[i] = tempElement; // ������� ���������� ��������� (�������� � tempElement)
//
//				index = i; // index ���������� ������� i (������ ��� �������� ��������)
//			}
//		}
//
//		// ������ � ����������� �������� ���,
//		// ������� leftIndex ���� �������� index + 1
//		leftIndex = index + 1;
//
//		// ���� �� 1 �� <= rightIndex
//		for (int i = 1; i <= rightIndex; i++)
//		{
//			// ���� ���������� ��. ������ ��������
//			if (a[i - 1] > a[i])
//			{
//				tempElement = a[i - 1]; // ��������� ��. ���������� ����������
//				a[i - 1] = a[i]; // ���������� ���������� �������
//				a[i] = tempElement; // ������� ���������� ���������� (�������� � tempElement)
//
//				index = i; // index ���������� ������� i (������ ��� �������� ��������)
//			}
//		}
//		rightIndex = index - 1;
//	} while (leftIndex < rightIndex);
//}
//
//
//
//// ���������� ���������
//template <class T>
//void insertSort(T a[], long size)
//{
//	T currentElement;
//	long i, j;
//	// ���� �������, i � ����� ������� 
//	for (i = 0; i < size; i++)
//	{
//		currentElement = a[i];
//		// ����� ���� �������� � ������ �����������
//		// �� ���� ���� j ���������� ���������� ������ (i - 1)
//		// � ��� >= 0
//		// � ��� �� ���� ������ ������� ��������, ����� � ������ �����
//		// ��������� ������ - ���� ���������� ��. ������ ��������
//		// (������� �� ����� ������ �� ������� ������� �� ���� a[-1])
//		// ��� �� ����� � ����� ������ ���������������� j
//		for (j = i - 1; j >= 0 && a[j] > currentElement; j--)
//		{
//			// ������� ������� ������� ���� �� �����
//			// �� ���� �������� ������ ����������� �������� �������� ��.
//			a[j + 1] = a[j];
//		}
//
//		// ���� ��������, �������� �������
//		// �� ���� � �������� ����� �������� ������ 
//		// � ����� ������ ����������� �������� �������� ��.
//		a[j + 1] = currentElement;
//	}
//}
//
//
//
//
//template <class T>
//void setMin(T a[], long size)
//{
//	T min = a[0]; // ����� min ����� ������ ��.
//
//	// ������� ����� �����������
//	for (int i = 1; i < size; i++)
//	{
//		if (a[i] < min)
//		{
//			min = a[i];
//		}
//	}
//
//	a[0] = min; // � ���������� ��� �� ������ ����� � �������
//}
//
//// �������� ������ (� ���������� ���������)
//template <class T>
//void insertSortGuarded(T a[], long size)
//{
//	T currentElement;
//	long i, j;
//
//	// �������� ������ ������ �������
//	T backup = a[0];
//
//	// ������� �� ��������� 
//	setMin(a, size);
//
//	// ���������� ����� 
//	for (i = 1; i < size; i++)
//	{
//		currentElement = a[i];
//
//		// ����� ���� �������� � ������ �����������
//		// �� ���� ���� j ���������� ���������� ������ (i - 1)
//		// � ��� >= 0
//		// � ��� �� ���� ������ ������� ��������, ����� � ������ �����
//		// ��������� ������ - ���� ���������� ��. ������ ��������
//		// (������� �� ����� ������ �� ������� ������� �� ���� a[-1])
//		// ��� �� ����� � ����� ������ ���������������� j
//		for (j = i - 1; a[j] > currentElement; j--)
//		{
//			// �������� ������ ����������� �������� �������� ��.
//			a[j + 1] = a[j];
//		}
//
//		// � �������� ����� �������� ������
//		// � ����� ������ ����������� �������� �������� ��.
//		a[j + 1] = currentElement;
//	}
//
//	// �������� backup �� ��������� ����
//	for (j = 1; j < size && a[j] < backup; j++)
//	{
//		// �� ���� ������� ������ �� 1 ��� �����
//		// ���� a[j] < backup (������ �� ��� ������������!)
//		// �������� [min, 2, 4, 6, 8] ������ [2, 4, 6, 8, ...]
//
//		a[j - 1] = a[j];
//	}
//
//	// ������� ��������
//	// � ������� ������ ������ [2, 4, 6, 8, backup] !
//	a[j - 1] = backup;
//}
//
//
//
//void main()
//{
//	srand(static_cast<unsigned long>(time(nullptr)));
//	const long SIZE = 10; // ��� �������
//	//const long SIZE = 1000; // ��� �������� ���������� ���������� ���� ����������
//	int arr[SIZE];
//
//	// ��� ���������� �������� ���������� ��������� ����������
//	// ���� ���� ������, ������� ���������� ��� ��������
//	std::chrono::steady_clock::time_point startTime;
//	std::chrono::steady_clock::time_point endTime;
//	//std::chrono::microseconds duration; // �� ����� - ����� ���� � cout << �� ������
//
//	// ��������� ���������� ���������� � ������� �� �����
//	initializeArray(arr, SIZE);
//	printArray(arr, SIZE);
//
//	// ���������� �������
//	cout << "selectSort:\n";
//	startTime = getCurrentTime();
//	selectSort(arr, SIZE);
//	endTime = getCurrentTime();
//	cout << "Duration: " << calculateDuration(endTime, startTime).count() << " microseconds\n\n";
//
//	// ����� ����������
//	printArray(arr, SIZE, "Sorted array:\n");
//	////////////////////////////////////////////////////////////////////////////
//
//
//
//		// ����� ��������� ���������� ���������� � ������� �� �����
//	initializeArray(arr, SIZE);
//	printArray(arr, SIZE);
//
//	// �����������  ����������
//	cout << "bubbleSort:\n";
//	startTime = getCurrentTime();
//	bubbleSort(arr, SIZE);
//	endTime = getCurrentTime();
//	cout << "Duration: " << calculateDuration(endTime, startTime).count() << " microseconds\n\n";
//
//	// ����� ����������
//	printArray(arr, SIZE, "Sorted array:\n");
//	////////////////////////////////////////////////////////////////////////////
//
//
//
//		// ����� ��������� ���������� ���������� � ������� �� �����
//	initializeArray(arr, SIZE);
//	printArray(arr, SIZE);
//
//	// ������-����������(���������� ����������)
//	cout << "shakerSort:\n";
//	startTime = getCurrentTime();
//	shakerSort(arr, SIZE);
//	endTime = getCurrentTime();
//	cout << "Duration: " << calculateDuration(endTime, startTime).count() << " microseconds\n\n";
//
//	// ����� ����������
//	printArray(arr, SIZE, "Sorted array:\n");
//	////////////////////////////////////////////////////////////////////////////
//
//
//
//		// ����� ��������� ���������� ���������� � ������� �� �����
//	initializeArray(arr, SIZE);
//	printArray(arr, SIZE);
//
//	// ���������� ���������
//	cout << "insertSort:\n";
//	startTime = getCurrentTime();
//	insertSort(arr, SIZE);
//	endTime = getCurrentTime();
//	cout << "Duration: " << calculateDuration(endTime, startTime).count() << " microseconds\n\n";
//
//	// ����� ����������
//	printArray(arr, SIZE, "Sorted array:\n");
//	////////////////////////////////////////////////////////////////////////////
//
//
//
//		// ����� ��������� ���������� ���������� � ������� �� �����
//	initializeArray(arr, SIZE);
//	printArray(arr, SIZE);
//
//	// �������� ������ (� ���������� ���������)
//	cout << "insertSortGuarded:\n";
//	startTime = getCurrentTime();
//	insertSortGuarded(arr, SIZE);
//	endTime = getCurrentTime();
//	cout << "Duration: " << calculateDuration(endTime, startTime).count() << " microseconds\n\n";
//
//	// ����� ����������
//	printArray(arr, SIZE, "Sorted array:\n");
//	////////////////////////////////////////////////////////////////////////////
//}