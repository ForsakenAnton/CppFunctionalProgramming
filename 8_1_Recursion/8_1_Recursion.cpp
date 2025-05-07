
#include <iostream>

void sayHello(int times)
{
	if (times == 0)
	{
		return;
	}

	std::cout << "Before. times == " << times << "\n";

	sayHello(times - 1);

	std::cout << "After. times == " << times << "\n";
}

int getSumOfArrayElements(int arr[], const int size)
{
	if (size == 0)
	{
		return 0;
	}

	return arr[0] + getSumOfArrayElements(arr + 1, size - 1);
}


int getSumOfArrayElementsAlternateVersion(int arr[], const int size, int sum = 0)
{
	if (size == 0)
	{
		return sum;
	}

	sum += arr[0];

	getSumOfArrayElementsAlternateVersion(arr + 1, size - 1, sum);
}


int getMinSumFromSequence(
	int arr[],
	const int size,
	int currentIndex,
	int sequenceSum,
	const int sequenceLength,
	int min = INT32_MAX)
{
	if (size < sequenceLength)
	{
		return min;
	}

	if (currentIndex < sequenceLength)
	{
		sequenceSum += arr[currentIndex];
		getMinSumFromSequence(arr, size, currentIndex + 1, sequenceSum, sequenceLength, min);
	}
	else
	{
		if (min > sequenceSum)
		{
			min = sequenceSum;
		}

		getMinSumFromSequence(arr + 1, size - 1, 0, 0, sequenceLength, min);
	}
	
}


int main()
{
	{
		sayHello(3);

		const int size = 5;
		int arr[size] = { 3, 4, 5, 6, 7 };
		std::cout << getSumOfArrayElements(arr, size) << "\n";
		std::cout << getSumOfArrayElementsAlternateVersion(arr, size, 0) << "\n";
		//getSumOfArrayElenemts(arr + 1, size);
		//getSumOfArrayElenemts(arr + 3, size - 3);
	}


	// Напишіть рекурсивну функцію, 
	// яка приймає одновимірний масив зі 100 цілих чисел,
	// заповнених випадковим чином, і знаходить позицію,
	// з якої починається послідовність з 10 чисел, 
	// сума яких мінімальна.
	//(!) Порада: для відлагодження програми зробіть 10 елементів масиву,
	// а послідовність - 5. 
	// Тобто  у вас 6 варіантів мін.числа :
	// від 0 до 5, від 1 до 6 ... від 5 до 10

	const int size = 6;
	int arr[] = { 4, 7, 5, 3, 1, 8 };

	int minSum = getMinSumFromSequence(arr, size, 0, 0, 4, INT32_MAX);
	std::cout << minSum << "\n";
}

