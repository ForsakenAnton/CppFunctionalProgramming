#include <iostream>
#include <Windows.h>

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);


	//// while
	//{
	//    int endPoint = 10;
	//    int startPoint = 0;
	//    // standard while loop
	//    while (startPoint < endPoint)
	//    {
	//        std::cout << startPoint << ", ";
	//        startPoint++;
	//    }
	//    std::cout << "\n\n";

	//    // infinite loop
	//    bool exit = false;
	//    while (true)
	//    {
	//        std::cout << "Enter 1 to exit or 0 to continue\n";

	//        std::cin >> exit;

	//        if (exit)
	//        {
	//            break;
	//        }
	//    }


	//    // true/false condition loop
	//    exit = false;
	//    while (!exit)
	//    {
	//        std::cout << "Enter 1 to exit or 0 to continue\n";

	//        std::cin >> exit;
	//    }
	//}





	//// Postfix/Prefix Increment and Decrement
	//{
	//    int value = 0;
	//    value++; // postfix increment (value = value + 1)
	//    value--; // postfix decrement (value = value - 1)

	//    ++value; // prefix increment (value = value + 1)
	//    --value; // prefix decrement (value = value - 1)

	//    value = 0;
	//    std::cout << value++ << std::endl;
	//    std::cout << ++value << std::endl;
	//    std::cout << value-- << std::endl;
	//    std::cout << --value << std::endl;
	//}





	//// do while
	//{
	//	bool someCondition = false;

	//	do
	//	{
	//		std::cout << "Some operations in do-while...\n";
	//	} while (someCondition);

	//	while (someCondition)
	//	{
	//		std::cout << "Some operations in while...\n";
	//	}


	//	// example like a menu
	//	char operation;
	//	do
	//	{
	//		std::cout << "Choose the operation:\n";
	//		std::cout << "1. On\n";
	//		std::cout << "2. Off\n";
	//		std::cout << "0. Exit\n";

	//		std::cin >> operation;

	//		switch (operation)
	//		{
	//		case '1':
	//			std::cout << "On\n";
	//			break;

	//		case '2':
	//			std::cout << "Off\n";
	//			break;

	//		case '0':
	//			std::cout << "Exit\n";
	//			break;

	//		default:
	//			std::cout << "Incorrect operation...\n\n";
	//			break;
	//		}

	//	} while (operation != '0');


	//	// the same example using while loop
	//	char anotherOperation = ' ';
	//	while (anotherOperation != '0')
	//	{
	//		std::cout << "Choose the operation:\n";
	//		std::cout << "1. On\n";
	//		std::cout << "2. Off\n";
	//		std::cout << "0. Exit\n";

	//		std::cin >> anotherOperation;

	//		switch (anotherOperation)
	//		{
	//		case '1':
	//			std::cout << "On\n";
	//			break;

	//		case '2':
	//			std::cout << "Off\n";
	//			break;

	//		case '0':
	//			std::cout << "Exit\n";
	//			break;

	//		default:
	//			std::cout << "Incorrect operation...\n\n";
	//			break;
	//		}
	//	}
	//}








	//// for
	//{
	//	for (
	//		int i = 0; // initialization (work one times during the start a loop)
	//		i < 10; // condition (second operation)
	//		i++) // action (fourth operation)
	//	{
	//		std::cout << i << ", "; // third operation
	//	}
	//	std::cout << std::endl;


	//	int index;
	//	for (index = 10; index >= 0; index -= 3)
	//	{
	//		std::cout << index << ", "; 
	//	}
	//	std::cout << std::endl;


	//	index = 10;
	//	for (; index >= 0; index -= 3)
	//	{
	//		std::cout << index << ", ";
	//	}
	//	std::cout << std::endl;


	//	index = 10;
	//	for (;; index -= 3)
	//	{
	//		if (!(index >= 0))
	//		{
	//			break;
	//		}
	//		std::cout << index << ", ";
	//	}
	//	std::cout << std::endl;


	//	index = 10;
	//	for ( ; ; )
	//	{
	//		if (!(index >= 0))
	//		{
	//			break;
	//		}
	//		std::cout << index << ", ";

	//		index -= 3;
	//	}
	//	std::cout << std::endl;




	//	//for (;;)
	//	//{
	//	//	std::cout << "Infinite loop\n";
	//	//}
	//}



	

	//{
	//	for (int row = 0; row < 10; row++)
	//	{
	//		for (int col = 0; col < 10; col++)
	//		{
	//			std::cout << row << " - " << col << ", ";
	//		}

	//		std::cout << "\n";
	//	}
	//}



	// Завдання 2.
	// Напишіть програму, яка запитує два цілих  числа x і y, 
	// після чого обчислює і виводить значення x у  степені y 
	// (використовуйте цикли або <math.h> pow) . 
	{
		int x = 3;
		int y = -4;

		if (y < 0)
		{
			y = std::abs(y); // 1 variant
			//y = y * -1; // 2 variant
		}

		int result = std::pow(x, y);
		std::cout << result << std::endl;

		int loopResult = x;
		for (int i = 1; i < y; i++)
		{
			loopResult *= x;
		}
		std::cout << loopResult << std::endl;

	}



	// swap
	{
		int start = 20;
		int end = 10;

		if (start > end)
		{
			//// 1 variant
			//std::swap(start, end);

			// 2 variant
			int tempVariable = start;
			start = end;
			end = tempVariable;
		}

		for (int pointer = start; pointer < end; pointer++)
		{
			std::cout << pointer << ", ";
		}
		std::cout << "\n";

	}
}



// Ticks and tricks
// 'number += 1' is the same as 'number++';

// row - рядок
// col - стовпчик (скорочення від column)