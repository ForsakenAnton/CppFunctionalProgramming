#include <iostream>


int main() 
{
    // dynamic two dim. arrays
    {
        int rows = 4;
        int cols = 3;

        int** arr = new int* [rows];
        // *
        // *
        // *
        // *
        for (int i = 0; i < rows; i++)
        {
            arr[i] = new int[cols] {};
        }
        // * 0 0 0
        // * 0 0 0
        // * 0 0 0
        // * 0 0 0

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                arr[i][j] = i + j;
            }
        }

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                std::cout << arr[i][j] << ", ";
            }

            std::cout << "\n";
        }

        std::cout << "\n\n\n";


        // what about size of the arr???
        std::cout << sizeof(new int{ 123 }) << std::endl;
        std::cout << sizeof(int*) << std::endl;
        std::cout << sizeof(char*) << std::endl;
        std::cout << sizeof(double*) << std::endl;
        std::cout << sizeof(bool*) << std::endl;

        std::cout << sizeof(arr) << std::endl;
        std::cout << sizeof(arr[0]) << std::endl;
        std::cout << sizeof(arr[1]) << std::endl;
        std::cout << sizeof(arr[2]) << std::endl;
        std::cout << sizeof(arr[3]) << std::endl;
        std::cout << sizeof(*arr) << std::endl;

        std::cout << sizeof(**arr) << std::endl;
        std::cout << sizeof(arr[0][0]) << std::endl;
        std::cout << **arr << std::endl;
        std::cout << arr[0][0] << std::endl;


        std::cout << _msize(arr) << std::endl; // 8bytes * 4pointers == 32bytes
        std::cout << _msize(*arr) << std::endl; // intSize * countOfArray == 12bytes

        int dynamicRows = _msize(arr) / sizeof(int*);
        int dynamicCols = _msize(*arr) / sizeof(int);

        for (int i = 0; i < rows; i++)
        {
            delete [] arr[i];
        }

		delete[] arr;
        arr = nullptr;

        std::cout << "\n\n\n";
    }


    // dynamic two dim arrays with different cols
    {
        int rows = 4;
        int** arr = new int* [rows];

        int firstSize = 3;
        int secondSize = 5;
        int thirdSize = 2;
        int fourthSize = 7;

        arr[0] = new int[firstSize] {3, 4, 5};
		arr[1] = new int[secondSize] {5, 6, 7, 8, 9};
		arr[2] = new int[thirdSize] {2, 3};
        arr[3] = new int[fourthSize] {7, 8, 9, 10, 11, 12, 13};
        ///
        /////
        //
        ///////

        for (int i = 0; i < rows; i++)
        {
            int cols = _msize(arr[i]) / sizeof(int);
			//std::cout << "Row " << i << " has " << cols << " cols\n";

            for (int j = 0; j < cols; j++)
            {
                std::cout << arr[i][j] << ", ";
            }

			std::cout << "\n";
        }

        std::cout << "\n\n\n";


        for (int i = 0; i < rows; i++)
        {
            delete[] arr[i];
        }

		delete[] arr;
		arr = nullptr;
    }
}

