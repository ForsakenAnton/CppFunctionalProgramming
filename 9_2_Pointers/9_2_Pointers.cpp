
#include <iostream>

int& getElementByIndex(int arr[], int size, int index);

int main()
{
	// const pointer
	{
		//int* const constPointer; // Error. Need initializing
		int variable = 100;
		int* const constPointer = &variable;
		*constPointer = 200; // Ok

		int anotherVariable = 300;
		//constPointer = &anotherVariable; // Error. Pointer is const
	}

	// pointer on const
	{
		const int* pointerOnConst; // Ok
		int variable = 100;
		pointerOnConst = &variable;  // Ok
		//*constPointer = 200; // Error. Pointer on const
		variable = 200; // Ok

		int anotherVariable = 300;
		pointerOnConst = &anotherVariable; // Ok
	}

	// const pointer on const
	{
		//const int* const constPointerOnConst; // Error. This pointer is the const pointer on const
		//int variable = 100;
		//constPointerOnConst = &variable;  // Error
		////*constPointer = 200; // Error. Pointer on const
		//variable = 200; // Ok

		//int anotherVariable = 300;
		//constPointerOnConst = &anotherVariable; // Error

		int variable = 100;
		const int* const constPointerOnConst = &variable;
		//*constPointerOnConst = 200; // Error

		int anotherVariable = 300;
		//constPointerOnConst = &anotherVariable; // Error
	}


	// pointer vs references
	{
		// pointers
		int x = 100;
		int* p1 = &x; // p1 => x => memory x
		int* p2 = p1; // p2 => x => memory x

		int y = 200;
		p1 = &y; // p1 => y => memory y
		// What about p2 ??? p2 => x => memory x



		// references
		//int& ref; // Error0. Need initializing
		int a = 100;
		int& refA = a; // refA => memory a

		int b = 200;
		refA = b; // ??? There is no any referencing to b. Just assignable the value of b variable
		// refA = 200; refA => memoryA; a == 200

		b = 300; // a == 200; refA == 200
		a = 400; // b == 300; refA == 400

		std::cout << "";
	}


	// returns ref from methods
	{
		const int size = 5;
		int arr[size] = { 10, 20, 50, 40, 30 };

		try
		{
			int &thirdEl = getElementByIndex(arr, size, 2); // Ok
			thirdEl = 100; // Ok. arr[2] == 100;
			std::cout << thirdEl << " - " << arr[2] << "\n\n";

			getElementByIndex(arr, size, 3) = 200; // Ok. arr[3] == 200
			std::cout << arr[3] << "\n\n";
		}
		catch (const std::exception& ex)
		{
			std::cout << ex.what() << "\n\n";
		}
	}


	// new and delete // /////////////////////////////////////////////////////

	// simple example
	{
		int autoVar = 100;

		int* dynamicVar = new int{100};
		int* y = dynamicVar;

		*dynamicVar = 200;

		//delete [] array; // deletion for array pointers.
		delete dynamicVar; // deletion for scalar pointers

		//delete autoVar; // Compile Error
		int* pAutoVar = &autoVar;
		//delete pAutoVar; // Runtime Error!!! We cannot remove auto memory, just dynamic memory;
		std::cout << "";

	} // autoVar release her memory, but not dynamicVar


	// another example (off topic)
	{
		struct MyStruct
		{
			MyStruct()
			{
				std::cout << "Constructor for " << this << "\n";
			}

			~MyStruct()
			{
				std::cout << "~Destructor for " << this << "\n";
			}
		};

		MyStruct myStruct1;
		MyStruct myStruct2;
		MyStruct myStruct3;


		MyStruct* dynamicStruct = new MyStruct;
		delete dynamicStruct;
		std::cout << "";

	} // auto delete for myStruct1 myStruct2, myStruct3



	// new delete with array pointers
	{
		int size = 5; // not const
		int* dArr = new int[size] { };

		for (int i = 0; i < size; i++)
		{
			std::cout << dArr[i] << ", ";
		}
		std::cout << "\n\n";

		delete[] dArr;

		dArr = new int[10] { };

		for (int i = 0; i < 10; i++)
		{
			std::cout << dArr[i] << ", ";
		}
		std::cout << "\n\n";

		delete[] dArr;
		dArr = nullptr;

		if (dArr != nullptr)
		{
			dArr[0] = 123;
		}
	}
}


int& getElementByIndex(int arr[], int size, int index) // програмістський індекс. Тобто 0 це 1
{
	if (index < 0 || index > size - 1)
	{
		throw std::exception("Index is out of range");
	}

	return arr[index];
}
