
#include <iostream>
#include<cstdarg>
using namespace std;


// Initialize and Print methods /////////////////////////
template <class T>
void initializeArray(T arr[], long size, int min, int max)
{
	// заповнюємо рандомними значеннями
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
	// якщо проведена спроба обчислити факторіал нуля...
	if (number < 1)
	{
		return 0; // то повертаємо 0
	}
	// якщо обчислюється факторіал одиниці,
	// саме тут виконується вихід із рекурсії.
	// (!!!) Тобто це і є умова вихіду з функції
	else if (number == 1)
	{
		return 1;
	}
	// будь-яке інше число викликає функцію заново
	// з формулою number - 1
	else
	{
		return number * getFactorial(number - 1); // 5 * 4 * 3...
		// По суті, код вище буде виглядати так:
		// Нехай number == 5, тоді... :
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
	// На вході — масив arr[], 
	// arr[size - 1] — його останній елемент.

	long i = 0; // i - це "лівий" індекс і використовуватися буде зліва направо
	long j = size - 1; // j - це "правий" індекс и використовуватися буде зправа наліво

	T middleEl = arr[size / 2]; // центральний елемент
	// тобто, наприклад, size == 8 або 9. Тоді 8/2 або 9/2 == 4 - індекс елемента.
	// А також, наприклад, size == 10, тоді 10/2 == 5 - індекс елемента.

	// процедура поділу 
	do // нижче умова i <= j
	{
		// доки елемент зліва від центру массиву (middleEl або arr[size / 2])
		// та менше центрального елементу массиву, то йдемо вправо (i++)
		while (arr[i] < middleEl)
		{
			i++;
		}

		// доки елемент зправа від центру массиву (middleEl або arr[size / 2])
		// та більше центрального елементу массиву, то йдемо вліво (i--)
		while (arr[j] > middleEl)
		{
			j--;
		}

		// якщо все іще i <= j, то:
		if (i <= j)
		{
			// міняемо єлементи місцями за індексами i та j
			T temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;

			// шагаємо вправо та вліво по кроку
			i++;
			j--;
		}

	} while (i <= j);

	/* рекурсивні виклики, якщо є що сортувати */
	// тобто, якщо зправа вліво ще не докрокували,
	// то визиваємо рекурсію - передаємо туди звісно ж масив,
	// а також j - вона послужить замість size та зменше 
	// діапазон роботи з цим масивом
	if (j > 0)
	{
		quickSortWithRecursion(arr, j);
	}

	// тобто, якщо зліва направо ще не докрокували,
	// то визиваємо рекурсію - передаємо туди звісно ж масив,
	// а також i - вона послужить замість size та зменше 
	// діапазон роботи з цим масивом
	// Езотеричний (ні, не екзотичний) виклик arr + i (масив + число, ага) - 
	// скоротить масив на i.
	// Тобто, наприклад, є масив {1, 2, 3, 4, 5} - тобто size == 5.
	// При передачі його у метод по типу methodName(arr, size) все буде як звичайно.
	// А при передачі як (arr + 3, size - 3) вийде частина масиву {4, 5}
	if (i < size)
	{
		quickSortWithRecursion(arr + i, size - i);
	}
}





// Двійковий пошук (Binary Search)
// Перш за все - бінарний пошук працює ТІЛЬКИ з відсортованим масивом
// Тому нижче для простоти - метод бульбашкового сортування

// Бульбашкове»  сортування
template <class T>
void bubbleSort(T arr[], long size)
{
	T tempElement;
	for (int i = 0; i < size; i++) // цикл від 0 до size
	{
		for (int j = size - 1; j > i; j--) // цикл від size - 1 до i
		{
			// отже, перший елемент тут це останній
			// так як цикл з кінця
			// отже, наступний ел. буде передостаннім.
			// Тоді:
			// якщо наступний ел. більший за поточний
			if (arr[j - 1] > arr[j])
			{
				tempElement = arr[j - 1]; // тимчасовий ел. запам'ятовує наступний
				arr[j - 1] = arr[j]; // наступний запам'ятовує поточний
				arr[j] = tempElement; // поточний запам'ятовує наступний (значення в tempElement)
			}
		}
	}
}



// Перш за все - бінарний пошук працює ТІЛЬКИ з відсортованим масивом
int binarySearch(int sortedArr[], int left, int right, int key)
{
	while (true)
	{
		// шукаємо центральний індекс у діапазоні left та right 
		int middleIndex = (left + right) / 2;

		// key - значення для пошуку такого ж значення у arr[]
		// якщо ключ менший за центральний элемент
		// то right забирає значення центрального елемента
		if (key < sortedArr[middleIndex])
		{
			right = middleIndex - 1;
		}
		// якщо ключ більший за центральний элемент
		// то left забирає значення центрального елемента
		else if (key > sortedArr[middleIndex])
		{
			left = middleIndex + 1;
		}
		// таким чином як 2 if та else if вище ми скорочуємо пошук
		// у 2 рази.
		// Наприклад size у масива == 100.
		// 100 / 2;
		// 50 / 2;
		// 25 / 2;
		// 12 / 2;
		// 6 / 2;
		// 3 / 2;
		// 1 / 2;
		// Вище вийшло максимум 7 операцій


		// якшо ключ == шукаємому значенню масиву - повертаємо його індекс
		else
		{
			return middleIndex;
		}

		// якщо зліва більше ніж справа - повертаємо -1
		if (left > right)
		{
			return -1;
		}
	}
}




// Функція, що приймає необмеженукількість параметрів
// треба підключити бібліотеку #include<cstdarg>

/*
   Для вказівки того, що функція приймає необмежену
   кількість параметрів, потрібно вказати ...
   У нашій функції є один відомий параметр — це
   numOfArgs
   Цей параметр містить число переданих змінних
   параметрів
*/

// numOfArgs - у даному випадку це кількість аргументів
// наприклад getMin(3, 5, 7, 9) - це numOfArgs == 3, а ... == 5, 7, 9
// Посилання на оф. документацію :
// https://learn.microsoft.com/ru-ru/cpp/c-runtime-library/reference/va-arg-va-copy-va-end-va-start?view=msvc-170
int getMin(int numOfArgs, ...) // numOfArgs - у даному випадку це кількість аргументів
{
	// об'являємо va
	va_list va;

	// ініціалізуємо va для проходу по списку параметрів
	// numOfArgs — найправіший відомий параметр, тобто кількість всих параметрів
	va_start(va, numOfArgs);
	// зараз va == першому параметру, перевірте за допомогою відладчика

	// отримуємо перше значення зі списку
	// та кажемо, що нехай min == першому параметру
	int min = va_arg(va, int);

	/*
	   Ми вже отримали перше значення зі списку.
	   Саме тому ми ведемо цикл до numOfArgs — 1
	*/
	for (int i = 0; i < numOfArgs - 1; i++)
	{
		// У циклі отримуємо одне значення за іншим
		int nextParameter = va_arg(va, int);

		// класична умова пошуку найменшого
		if (min > nextParameter)
		{
			min = nextParameter;
		}
	}

	// коректне завершення роботи зі змінними списку
	va_end(va);

	// повернення значення
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

	// після сортування 
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



	// Двійковий пошук (Binary Search)
	cout << "Binary Search:\n";
	int key;
	cout << "Enter any digit: ";
	cin >> key;

	cout << "Index - " << binarySearch(arr, 0, SIZE, key) << "\n\n\n";
	///////////////////////////////////////////////////////////////////


	// Приклад з передачею необмеженої кількості параметрів у метод
	// Функція, що приймає необмеженукількість параметрів
	// треба підключити бібліотеку #include <cstdarg>
	cout << "Example with params using library <cstdarg>\n";
	int result = getMin(5, 10, -33, -1, 4, 9); // 5 - у даному випадку це кількість аргументів
	cout << "Minimum is: " << result << "\n\n\n";

	// Such things 0_o...
}