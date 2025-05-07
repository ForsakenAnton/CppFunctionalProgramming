
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <algorithm>
#include <chrono>
using namespace std;

// Допоміжні методи, які за допомогою бібліотеки <chrono>
// допоможуть нам розрахувати час виконання кожного методу
// std::chrono::steady_clock::time_point - це тип, який повертається, так
// Але ви вже знаєте ключове слово auto, отже, можна і так:
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

// Ініціалізація та методи друку /////////////////////////
template <class T>
void initializeArray(T arr[], long size)
{
	// заповнюємо випадковими значеннями
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

// Сортування вибором
template <typename T, int size>
void selectSort(T (&a)[size], bool asc = true)
{
	int indexOfMinElement; // індекс мінімального елемента масиву
	T minElementOfArr; // мінімальний елемент масиву

	for (int i = 0; i < size; i++)
	{
		indexOfMinElement = i; // нехай індекс мінімального елемента масиву == i
		minElementOfArr = a[i]; // нехай мінімальний елемент масиву == a[i]

		// цикл вибору найменшого елемента 
		for (int j = i + 1; j < size; j++)
		{
			if (asc ? a[j] < minElementOfArr : a[j] > minElementOfArr) // фактично знаходимо мін. елемент масиву
			{
				indexOfMinElement = j; // запам'ятовуємо його індекс
				minElementOfArr = a[j]; // запам'ятовуємо його значення
			}
		}

		// якщо індекс елемента, з якого все починалось, не дорівнює
		// індексу, який (можливо) перезаписався у внутрішньому циклі
		if (indexOfMinElement != i)
		{
			// в елемент з знайденим мінімальним значенням
			// записуємо елемент, з якого все починалось
			a[indexOfMinElement] = a[i];

			// в елемент, з якого все починалось
			// записуємо знайдений мінімальний елемент
			a[i] = minElementOfArr;
		}
	}
}

// Бульбашкове сортування
template <class T, int size>
void bubbleSort(T (&a)[size])
{
	T tempElement;
	for (int i = 0; i < size; i++) // цикл від 0 до size
	{
		for (int j = size - 1; j > i; j--) // цикл від size - 1 до i
		{
			// отже, перший елемент тут це останній
			// так як цикл з кінця
			// означає наступний елемент буде передостаннім.
			// Тоді:
			// якщо наступний елемент більший за поточний
			if (a[j - 1] > a[j])
			{
				tempElement = a[j - 1]; // тимчасовий елемент запам'ятовує наступний
				a[j - 1] = a[j]; // наступний запам'ятовує поточний
				a[j] = tempElement; // поточний запам'ятовує наступний (значення в tempElement)
			}
		}
	}
}

// Шейкер-сортування (сортування змішуванням)
template <class T, int size>
void shakerSort(T (&a)[size])
{
	long index = size - 1;

	// межі частини масиву, що не є відсортованою
	long leftIndex = 1;
	long rightIndex = size - 1;
	T tempElement;

	do
	{
		// цикл від rightIndex до > 0
		for (int i = rightIndex; i > 0; i--)
		{
			// отже, перший елемент тут це останній
			// так як цикл з кінця
			// означає наступний елемент буде передостаннім.
			// Тоді:
			// якщо наступний елемент більший за поточний
			if (a[i - 1] > a[i])
			{
				tempElement = a[i - 1]; // тимчасовий елемент запам'ятовує наступний
				a[i - 1] = a[i]; // наступний запам'ятовує поточний
				a[i] = tempElement; // поточний запам'ятовує наступний (значення в tempElement)

				index = i; // index запам'ятовує поточний i (індекс вже МЕНШОГО елемента)
			}
		}

		// сенсу з найменшого починати немає,
		// тому leftIndex даємо значення index + 1
		leftIndex = index + 1;

		// цикл від 1 до <= rightIndex
		for (int i = 1; i <= rightIndex; i++)
		{
			// якщо попередній елемент більший за поточний
			if (a[i - 1] > a[i])
			{
				tempElement = a[i - 1]; // тимчасовий елемент запам'ятовує попередній
				a[i - 1] = a[i]; // попередній запам'ятовує поточний
				a[i] = tempElement; // поточний запам'ятовує попередній (значення в tempElement)

				index = i; // index запам'ятовує поточний i (індекс вже БІЛЬШОГО елемента)
			}
		}
		rightIndex = index - 1;
	} while (leftIndex < rightIndex);
}

// Сортування вставками
template <class T, int size>
void insertSort(T (&a)[size])
{
	T currentElement;
	long i, j;
	// цикл проходів, i — номер проходу 
	for (i = 0; i < size; i++)
	{
		currentElement = a[i];
		// пошук місця елемента в готовій послідовності
		// тобто якщо j запам'ятовує попередній індекс (i - 1)
		// і вона >= 0
		// а також якщо перше умова істинна, тоді і тільки тоді
		// спрацює друга - якщо попередній елемент більший за поточний
		// (тому не буде виходу за межі масиву по типу a[-1])
		// також тут в будь-якому випадку ініціалізується j
		for (j = i - 1; j >= 0 && a[j] > currentElement; j--)
		{
			// зсуваємо елемент направо поки не дійшли
			// тобто елементу справа присвоюємо значення поточного елементу
			a[j + 1] = a[j];
		}

		// місце знайдено, вставити елемент
		// тобто в кінцевому підсумку елементу справа 
		// в будь-якому випадку присвоюємо значення поточного елементу
		a[j + 1] = currentElement;
	}
}


template <class T>
void setMin(T a[], long size)
{
	T min = a[0]; // нехай min буде першим елементом

	// знаходимо найменший
	for (int i = 1; i < size; i++)
	{
		if (a[i] < min)
		{
			min = a[i];
		}
	}

	a[0] = min; // і записуємо його на перше місце в масиві
}

// Принципи методу (зі сторожевим елементом)
template <class T, int size>
void insertSortGuarded(T (&a)[size])
{
	T currentElement;
	long i, j;

	// зберегти старий перший елемент
	T backup = a[0];

	// замінити на мінімальний 
	setMin(a, size);

	// відсортувати масив 
	for (i = 1; i < size; i++)
	{
		currentElement = a[i];

		// пошук місця елемента в готовій послідовності
		// то якщо j запам'ятовує попередній індекс (i - 1)
		// і вона >= 0
		// а також якщо перше умова істинна, тоді і тільки тоді
		// спрацює друга - якщо попередній елемент більший за поточний
		// (тому не буде виходу за межі масиву по типу a[-1])
		// також тут в будь-якому випадку ініціалізується j
		for (j = i - 1; a[j] > currentElement; j--)
		{
			// елементу справа присвоюємо значення поточного елементу
			a[j + 1] = a[j];
		}

		// в кінцевому підсумку елементу справа
		// в будь-якому випадку присвоюємо значення поточного елементу
		a[j + 1] = currentElement;
	}

	// вставити backup на правильне місце
	for (j = 1; j < size && a[j] < backup; j++)
	{
		// отже, зсуваємо масив на 1 крок вліво
		// якщо a[j] < backup (масив вже відсортований!)
		// Наприклад, [min, 2, 4, 6, 8] стане [2, 4, 6, 8, ...]

		a[j - 1] = a[j];
	}

	// вставка елемента
	// і, нарешті, стане [2, 4, 6, 8, backup]!
	a[j - 1] = backup;
}


void main()
{
	srand(static_cast<unsigned long>(time(nullptr)));
	//const long SIZE = 5; // для відладки
	const long SIZE = 1000; // для швидкості виконання окремого виду сортування
	int arr[SIZE];

	// для обчислення швидкості виконання окремих сортувань
	// вище є методи, які повертають ці значення
	std::chrono::steady_clock::time_point startTime;
	std::chrono::steady_clock::time_point endTime;
	//std::chrono::microseconds duration; // не потрібно - вивід прямо в cout << із методу

	// заповнюємо випадковими значеннями та виводимо на екран
	initializeArray(arr, SIZE);
	printArray(arr, SIZE);

	// Сортування вибором
	cout << "selectSort:\n";
	startTime = getCurrentTime();
	selectSort<int, SIZE>(arr);
	//selectSort<int, SIZE>(arr, false);
	endTime = getCurrentTime();
	cout << "Duration: " << calculateDuration(endTime, startTime).count() << " microseconds\n\n";

	// після сортування
	printArray(arr, SIZE, "Sorted array:\n");
	////////////////////////////////////////////////////////////////////////////



		// ЗНОВУ заповнюємо випадковими значеннями та виводимо на екран
	initializeArray(arr, SIZE);
	printArray(arr, SIZE);

	// Бульбашкове»  сортування
	cout << "bubbleSort:\n";
	startTime = getCurrentTime();
	bubbleSort<int, SIZE>(arr);
	endTime = getCurrentTime();
	cout << "Duration: " << calculateDuration(endTime, startTime).count() << " microseconds\n\n";

	// після сортування
	printArray(arr, SIZE, "Sorted array:\n");
	////////////////////////////////////////////////////////////////////////////



		// ЗНОВУ заповнюємо випадковими значеннями та виводимо на екран
	initializeArray(arr, SIZE);
	printArray(arr, SIZE);

	// шейкер-сортування(сортування змішуванням)
	cout << "shakerSort:\n";
	startTime = getCurrentTime();
	shakerSort(arr);
	endTime = getCurrentTime();
	cout << "Duration: " << calculateDuration(endTime, startTime).count() << " microseconds\n\n";

	// після сортування
	printArray(arr, SIZE, "Sorted array:\n");
	////////////////////////////////////////////////////////////////////////////



		// ЗНОВУ заповнюємо випадковими значеннями та виводимо на екран
	initializeArray(arr, SIZE);
	printArray(arr, SIZE);

	// Сортування вставками
	cout << "insertSort:\n";
	startTime = getCurrentTime();
	insertSort(arr);
	endTime = getCurrentTime();
	cout << "Duration: " << calculateDuration(endTime, startTime).count() << " microseconds\n\n";

	// після сортування
	printArray(arr, SIZE, "Sorted array:\n");
	////////////////////////////////////////////////////////////////////////////



		// ЗНОВУ заповнюємо випадковими значеннями та виводимо на екран
	initializeArray(arr, SIZE);
	printArray(arr, SIZE);

	// Принципи методу (зі сторожевим елементом)
	cout << "insertSortGuarded:\n";
	startTime = getCurrentTime();
	insertSortGuarded(arr);
	endTime = getCurrentTime();
	cout << "Duration: " << calculateDuration(endTime, startTime).count() << " microseconds\n\n";

	// після сортування
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
//// Вспомагательные методы, которые с помощью библиотеки <chrono>
//// поможет нам рассчитать время выполнения каждого метода
//// std::chrono::steady_clock::time_point - это возвращающий тип, да
//// Но вы уже знаете ключевое слово auto, так что можно и так:
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
//	// заполняем рандомными значениями
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
//// Сортування вибором
//template <class T>
//void selectSort(T a[], long size)
//{
//	int indexOfMinElement; // индекс минимального эл. массива
//	T minElementOfArr; // минимальный эл. массива
//
//	for (int i = 0; i < size; i++)
//	{
//		indexOfMinElement = i; // пусть индекс минимального эл. массива == i
//		minElementOfArr = a[i]; // пусть  минимальный эл.массива == a[i]
//
//		// цикл вибору найменшого елемента 
//		for (int j = i + 1; j < size; j++)
//		{
//			if (a[j] < minElementOfArr) // фактически находим мин. элемент массива
//			{
//				indexOfMinElement = j; // запоминаем его индекс
//				minElementOfArr = a[j]; // запоминаем его значение
//			}
//		}
//
//		// если индекс элемента, с которого все начиналось не равен
//		// индексу, который (возможно) перезаписался во внутреннем цикле
//		if (indexOfMinElement != i)
//		{
//			// в элемент с найденным минимальным значением
//			// запичываем элемент, с которого все начиналось
//			a[indexOfMinElement] = a[i];
//
//			// в элемент, с которого все начиналось
//			// записываем найденный минимальный элемент
//			a[i] = minElementOfArr;
//		}
//	}
//}
//
//
//
//// Бульбашкове»  сортування
//template <class T>
//void bubbleSort(T a[], long size)
//{
//	T tempElement;
//	for (int i = 0; i < size; i++) // цикл с 0 до size
//	{
//		for (int j = size - 1; j > i; j--) // цикл от size - 1 до i
//		{
//			// итак, первый элемент сдесь это последний
//			// так как цикл с конца
//			// значит следующий эл. будет предпоследним.
//			// Тогда:
//			// если следующий эл. больше текущего
//			if (a[j - 1] > a[j])
//			{
//				tempElement = a[j - 1]; // временный эл. запоминает следующий
//				a[j - 1] = a[j]; // следующий запоминает текущий
//				a[j] = tempElement; // текущий запоминает следующий (значение в tempElement)
//			}
//		}
//	}
//}
//
//
//
//// шейкер-сортування(сортування змішуванням)
//template <class T>
//void shakerSort(T a[], long size)
//{
//	long index = size - 1;
//
//	// межі частини масиву, що не є відсортованою
//	long leftIndex = 1;
//	long rightIndex = size - 1;
//	T tempElement;
//
//	do
//	{
//		// цикл от rightIndex до > 0
//		for (int i = rightIndex; i > 0; i--)
//		{
//			// итак, первый элемент сдесь это последний
//			// так как цикл с конца
//			// значит следующий эл. будет предпоследним.
//			// Тогда:
//			// если следующий эл. больше текущего
//			if (a[i - 1] > a[i])
//			{
//				tempElement = a[i - 1]; // временный эл. запоминает следующий
//				a[i - 1] = a[i]; // следующий запоминает текущий
//				a[i] = tempElement; // текущий запоминает следующий (значение в tempElement)
//
//				index = i; // index запоминает текуший i (индекс уже МЕНЬШЕГО элемента)
//			}
//		}
//
//		// смысла с наименьшего начинать нет,
//		// поэтому leftIndex даем значение index + 1
//		leftIndex = index + 1;
//
//		// цикл от 1 до <= rightIndex
//		for (int i = 1; i <= rightIndex; i++)
//		{
//			// если предыдущий эл. больше текущего
//			if (a[i - 1] > a[i])
//			{
//				tempElement = a[i - 1]; // временный эл. запоминает предыдущий
//				a[i - 1] = a[i]; // предыдущий запоминает текущий
//				a[i] = tempElement; // текущий запоминает предыдущий (значение в tempElement)
//
//				index = i; // index запоминает текуший i (индекс уже БОЛЬШЕГО элемента)
//			}
//		}
//		rightIndex = index - 1;
//	} while (leftIndex < rightIndex);
//}
//
//
//
//// Сортування вставками
//template <class T>
//void insertSort(T a[], long size)
//{
//	T currentElement;
//	long i, j;
//	// цикл проходів, i — номер проходу 
//	for (i = 0; i < size; i++)
//	{
//		currentElement = a[i];
//		// пошук місця елемента в готовій послідовності
//		// то есть если j запоминает предыдущий индекс (i - 1)
//		// и она >= 0
//		// а так же если первое условие истинное, тогда и только тогда
//		// сработает второе - если предыдущий эл. больше текущего
//		// (поэтому не будет выхода за пределы массива по типу a[-1])
//		// так же сдесь в любом случае инициализируется j
//		for (j = i - 1; j >= 0 && a[j] > currentElement; j--)
//		{
//			// зрушуємо елемент направо поки не дійшли
//			// то есть элементу справа присваиваем значение тукещего эл.
//			a[j + 1] = a[j];
//		}
//
//		// місце знайдено, вставити елемент
//		// то есть в конечном итоге элементу справа 
//		// в любом случае присваиваем значение тукещего эл.
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
//	T min = a[0]; // пусть min будет первый эл.
//
//	// находим самый минимальный
//	for (int i = 1; i < size; i++)
//	{
//		if (a[i] < min)
//		{
//			min = a[i];
//		}
//	}
//
//	a[0] = min; // и записываем его на первое место в массиве
//}
//
//// Принципи методу (зі сторожевим елементом)
//template <class T>
//void insertSortGuarded(T a[], long size)
//{
//	T currentElement;
//	long i, j;
//
//	// зберегти старий перший елемент
//	T backup = a[0];
//
//	// замінити на мінімальний 
//	setMin(a, size);
//
//	// вісортувати масив 
//	for (i = 1; i < size; i++)
//	{
//		currentElement = a[i];
//
//		// пошук місця елемента в готовій послідовності
//		// то есть если j запоминает предыдущий индекс (i - 1)
//		// и она >= 0
//		// а так же если первое условие истинное, тогда и только тогда
//		// сработает второе - если предыдущий эл. больше текущего
//		// (поэтому не будет выхода за пределы массива по типу a[-1])
//		// так же сдесь в любом случае инициализируется j
//		for (j = i - 1; a[j] > currentElement; j--)
//		{
//			// элементу справа присваиваем значение тукещего эл.
//			a[j + 1] = a[j];
//		}
//
//		// в конечном итоге элементу справа
//		// в любом случае присваиваем значение тукещего эл.
//		a[j + 1] = currentElement;
//	}
//
//	// вставити backup на правильне місце
//	for (j = 1; j < size && a[j] < backup; j++)
//	{
//		// то есть двигаем массив на 1 шаг влево
//		// если a[j] < backup (массив то уже отсортирован!)
//		// Например [min, 2, 4, 6, 8] станет [2, 4, 6, 8, ...]
//
//		a[j - 1] = a[j];
//	}
//
//	// вставка елемента
//	// и наконец станет станет [2, 4, 6, 8, backup] !
//	a[j - 1] = backup;
//}
//
//
//
//void main()
//{
//	srand(static_cast<unsigned long>(time(nullptr)));
//	const long SIZE = 10; // для отладки
//	//const long SIZE = 1000; // для скорости выполнения отдельного вида сортировки
//	int arr[SIZE];
//
//	// для вычисления скорости выполнения отдельных сортировок
//	// выше есть методы, которые возвращают эти значения
//	std::chrono::steady_clock::time_point startTime;
//	std::chrono::steady_clock::time_point endTime;
//	//std::chrono::microseconds duration; // не нужна - вывод прям в cout << из метода
//
//	// заполняем рандомными значениями и выводим на экран
//	initializeArray(arr, SIZE);
//	printArray(arr, SIZE);
//
//	// Сортування вибором
//	cout << "selectSort:\n";
//	startTime = getCurrentTime();
//	selectSort(arr, SIZE);
//	endTime = getCurrentTime();
//	cout << "Duration: " << calculateDuration(endTime, startTime).count() << " microseconds\n\n";
//
//	// после сортировки
//	printArray(arr, SIZE, "Sorted array:\n");
//	////////////////////////////////////////////////////////////////////////////
//
//
//
//		// СНОВА заполняем рандомными значениями и выводим на экран
//	initializeArray(arr, SIZE);
//	printArray(arr, SIZE);
//
//	// Бульбашкове»  сортування
//	cout << "bubbleSort:\n";
//	startTime = getCurrentTime();
//	bubbleSort(arr, SIZE);
//	endTime = getCurrentTime();
//	cout << "Duration: " << calculateDuration(endTime, startTime).count() << " microseconds\n\n";
//
//	// после сортировки
//	printArray(arr, SIZE, "Sorted array:\n");
//	////////////////////////////////////////////////////////////////////////////
//
//
//
//		// СНОВА заполняем рандомными значениями и выводим на экран
//	initializeArray(arr, SIZE);
//	printArray(arr, SIZE);
//
//	// шейкер-сортування(сортування змішуванням)
//	cout << "shakerSort:\n";
//	startTime = getCurrentTime();
//	shakerSort(arr, SIZE);
//	endTime = getCurrentTime();
//	cout << "Duration: " << calculateDuration(endTime, startTime).count() << " microseconds\n\n";
//
//	// после сортировки
//	printArray(arr, SIZE, "Sorted array:\n");
//	////////////////////////////////////////////////////////////////////////////
//
//
//
//		// СНОВА заполняем рандомными значениями и выводим на экран
//	initializeArray(arr, SIZE);
//	printArray(arr, SIZE);
//
//	// Сортування вставками
//	cout << "insertSort:\n";
//	startTime = getCurrentTime();
//	insertSort(arr, SIZE);
//	endTime = getCurrentTime();
//	cout << "Duration: " << calculateDuration(endTime, startTime).count() << " microseconds\n\n";
//
//	// после сортировки
//	printArray(arr, SIZE, "Sorted array:\n");
//	////////////////////////////////////////////////////////////////////////////
//
//
//
//		// СНОВА заполняем рандомными значениями и выводим на экран
//	initializeArray(arr, SIZE);
//	printArray(arr, SIZE);
//
//	// Принципи методу (зі сторожевим елементом)
//	cout << "insertSortGuarded:\n";
//	startTime = getCurrentTime();
//	insertSortGuarded(arr, SIZE);
//	endTime = getCurrentTime();
//	cout << "Duration: " << calculateDuration(endTime, startTime).count() << " microseconds\n\n";
//
//	// после сортировки
//	printArray(arr, SIZE, "Sorted array:\n");
//	////////////////////////////////////////////////////////////////////////////
//}