
#include <iostream>

struct MyArray
{
    unsigned int size;
	unsigned int* arr;

    MyArray(int size)
    {
        this->size = size;
		arr = new unsigned int[size];

		std::cout << "Constructor called for " << this << "with arr "<< arr << std::endl;
    }

	void initialize()
	{
		for (int i = 0; i < size; i++)
		{
			arr[i] = i;
		}
	}

	void print()
	{
		for (int i = 0; i < size; i++)
		{
			std::cout << arr[i] << " ";
		}
		std::cout << std::endl << std::endl;
	}

	void allocate(unsigned int size)
	{
		deallocate();

		this->size = size;
		arr = new unsigned int[size];
	}

	void deallocate()
	{
		if (arr != nullptr)
		{
			delete[] arr;
			arr = nullptr;
		}
	}

	~MyArray()
	{
		deallocate();

		std::cout << "~Destructor called for " << this << "with arr " << arr << std::endl;
	}
};

int main()
{
    MyArray myArray(10);
	myArray.initialize();
	myArray.print();

	myArray.allocate(20);
	myArray.initialize();
	myArray.print();

	myArray.deallocate();
	myArray.deallocate();
	myArray.deallocate();

	myArray.allocate(30);
	myArray.initialize();
	myArray.print();

	//MyArray anotherArray = myArray;
	//anotherArray.print();
}
