#include <iostream>

int main()
{
	std::srand(std::time(nullptr));

	// memory test
	{
		int arr[] = { 1, 2, 3 };
		std::cout << arr << std::endl;
		std::cout << &arr[0] << std::endl;

		int variable = 123;
		std::cout << &variable << std::endl;
		std::cout << std::endl;

	}


	// two dimensional arrays
	{
		const int rows = 3;
		const int cols = 4;

		int twoDimArray[][cols] =
		{
			{1, 2, 3, 4,},
			{4, 5, 6,},
			{7, 8, 9,},
		};

		std::cout << twoDimArray << std::endl;
		std::cout << twoDimArray[0] << std::endl;
		std::cout << twoDimArray[1] << std::endl;
		std::cout << twoDimArray[2] << std::endl;
		std::cout << &twoDimArray[0][0] << std::endl;
		std::cout << &twoDimArray[1][0] << std::endl;
		std::cout << &twoDimArray[2][0] << std::endl;

		// заповнення масиву рандомними значеннями
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				twoDimArray[i][j] = std::rand() % (10 - 1) + 1;
			}
		}

		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				std::cout << twoDimArray[i][j] << ", ";
			}

			std::cout << "\n";
		}

		std::cout << "\n\n";


		// динамічне знаходження розмірів масиву
		int bytesInType = sizeof(int);
		int allBytesInTwoDimArray = sizeof(twoDimArray);
		int allBytesInOneDimArray = sizeof(twoDimArray[0]);

		int findedRows = allBytesInTwoDimArray / allBytesInOneDimArray;
		int findedCols = allBytesInOneDimArray / bytesInType;

		std::cout << "rows: " << findedRows
			<< ", cols: " << findedCols <<
			std::endl;

		std::cout << "\n\n\n";
	}


	// three dimensional arrays
	{
		const int deep = 2; // глибина
		const int rows = 3;
		const int cols = 4;

		int threeDimArray[][rows][cols] =
		{
			// deep[0]
			{
				{1, 2, 3, 4,},
				{4, 5, 6,},
				{7, 8, 9,},
			},
			// deep[1]
			{
				{5, 6, 7, 8,},
				{6, 6, 6,},
				{6, 6, 6,},
			},
		};


		for (int d = 0; d < deep; d++)
		{
			std::cout << "Deep: " << d << std::endl;

			for (int r = 0; r < rows; r++)
			{
				for (int c = 0; c < cols; c++)
				{
					std::cout << threeDimArray[d][r][c] << ", ";
				}

				std::cout << "\n";
			}

			std::cout << "\n";
		}


		std::cout << "\n\n\n\n\n\n\n\n";
	}




	// find max el. in every row in two dim. array
	{
		const int rows = 3;
		const int cols = 6;

		int arr[rows][cols] =
		{
			{3, 5, 2, 8, 6, 4},
			{4, 3, 6, 1, 5, 2},
			{9, 5, 2, 1, 4, 3},
		};

		int arrWithMaxElements[rows] = {};

		for (int r = 0; r < rows; r++)
		{
			int maxElInRow = arr[r][0];

			for (int c = 0; c < cols; c++)
			{
				if (maxElInRow < arr[r][c])
				{
					maxElInRow = arr[r][c];
				}
			}

			arrWithMaxElements[r] = maxElInRow;
		}

		std::cout << "Max elements in every row:\n";
		for (int i = 0; i < rows; i++)
		{
			std::cout << arrWithMaxElements[i] << ", ";
		}

		std::cout << "\n\n\n\n\n\n\n\n";
	}




	// Завдання 3 (по бажанню). 
	// Створіть двовимірний масив. 
	// Заповніть його  випадковими числами і покажіть на екран. 
	// Користувач вибирає кількість зрушень і положення (вліво, вправо,  вгору, вниз).
	// Виконати зрушення масиву і показати на  екран отриманий результат. 
	// Зрушення циклічне.

	// Наприклад, якщо ми маємо такий масив.
	// 1 2 0 4 5 3 4 5 3 9 0 1
	// і користувач вибрав зрушення на 2 розряди вправо, то  ми отримаємо :
	// 5 3 1 2 0 4 0 1 4 5 3 9.
	{
		const int rows = 4;
		const int cols = 6;

		int arr[rows][cols] =
		{
			{1, 2, 3, 4, 5, 6},
			{2, 3, 4, 5, 6, 7},
			{3, 4, 5, 6, 7, 8},
			{4, 5, 6, 7, 8, 9},
		};


		char action;

		do
		{
			std::cout << "Current array:\n";
			for (int i = 0; i < rows; i++)
			{
				for (int j = 0; j < cols; j++)
				{
					std::cout << arr[i][j] << ", ";
				}

				std::cout << "\n";
			}
			std::cout << "\n\n";


			std::cout << "Actions\n";
			std::cout << "1. Shift an array on the left\n";
			std::cout << "2. Shift an array on the right\n";
			std::cout << "3. Shift an array on the top\n";
			std::cout << "4. Shift an array on the bottom\n";
			std::cout << "5. Print the array\n";
			std::cout << "0. Exit\n";

			std::cin >> action;

			int shift = 0;

			std::cout << "Enter the shift: ";
			std::cin >> shift;

			if (action == '1' || action == '2')
			{
				shift = shift % cols;
			}
			else if (action == '3' || action == '4')
			{
				shift = shift % rows;
			}

			switch (action)
			{
			case'1':
				for (int s = 0; s < shift; s++)
				{
					for (int i = 0; i < rows; i++)
					{
						int first = arr[i][0];

						for (int j = 0; j < cols - 1; j++)
						{
							arr[i][j] = arr[i][j + 1];
						}

						arr[i][cols - 1] = first;
					}
				}

				// not work
				//for (int i = 0; i < rows; i++)
				//{
				//	for (int j = 0; j < cols - 1; j++)
				//	{
				//		int temp = arr[i][j];
				//		arr[i][j] = arr[i][(j + shift) % cols];
				//		arr[i][(j + shift) % cols] = temp;
				//	}
				//}
				break;

			case'2':
				for (int s = 0; s < shift; s++)
				{
					for (int i = 0; i < rows; i++)
					{
						int last = arr[i][cols - 1];

						for (int j = cols - 1; j > 0; j--)
						{
							arr[i][j] = arr[i][j - 1];
						}

						arr[i][0] = last;
					}
				}
				break;

			case'3':
				for (int s = 0; s < shift; s++)
				{
					for (int j = 0; j < cols; j++)
					{
						int first = arr[0][j];

						for (int i = 0; i < rows - 1; i++)
						{
							arr[i][j] = arr[i + 1][j];
						}

						arr[rows - 1][j] = first;
					}
				}
				break;

			case'4':
				for (int s = 0; s < shift; s++)
				{
					for (int j = 0; j < cols; j++)
					{
						int last = arr[rows - 1][j];

						for (int i = rows - 1; i > 0; i--)
						{
							arr[i][j] = arr[i - 1][j];
						}

						arr[0][j] = last;
					}
				}				
				break;

			default:
				std::cout << "incorrect operation...\n\n";
				break;

				//case '5':
				//	for (int i = 0; i < rows; i++)
				//	{
				//		for (int j = 0; j < cols; j++)
				//		{
				//			std::cout << arr[i][j] << ", ";
				//		}

				//		std::cout << "\n";
				//	}

				//	std::cout << "\n\n";
				//	break;

			case'0':
				std::cout << "Exit\n\n";
				break;
			}

		} while (action != '0');
	}
}
