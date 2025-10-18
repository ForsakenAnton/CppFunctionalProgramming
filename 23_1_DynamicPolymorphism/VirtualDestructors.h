#pragma once

template<typename T>
class BaseArray
{
private:
	T* arr;
	size_t size;

public:
	explicit BaseArray(size_t size) :
		arr{ size != 0 ? new T[size]{} : nullptr },
		size{ size }
	{
	}

	virtual void print()
	{
		for (size_t i = 0; i < size; i++)
		{
			std::cout << arr[i] << " ";
		}
		std::cout << "\n\n";
	}

	virtual ~BaseArray()
	{
		std::cout << "~Destructor in BaseArray\n\n";

		if (arr != nullptr)
		{
			delete[] arr;
			arr = nullptr;
		}
	}
};

template<typename T>
class MyArr : public BaseArray<T>
{
private:
	char* desc;

public:
	MyArr(const char* desc, size_t size) :
		BaseArray<T>{ size }
	{ 
		if (desc != nullptr && strlen(desc) > 0)
		{
			auto length = strlen(desc);
			this->desc = new char[length + 1];
			strcpy_s(this->desc, length + 1, desc); // error
		}
		else
		{
			this->desc = nullptr;
		}
	}

	void print() override
	{
		std::cout << "Desc: " << desc << "\n";
		BaseArray<T>::print();
	} 

	~MyArr() override
	{
		std::cout << "~Destructor in MyArr\n\n";

		if (desc != nullptr)
		{
			delete[] desc;
			desc = nullptr;
		}
	}
};


void virtualDestructors()
{
	{
		BaseArray<int> ba{ 5 };
		ba.print();
	}

	{
		MyArr<int> ma{ "some", 5};
		ma.print();
	}

	{
		MyArr<int>* myArr = new MyArr<int>{ "desc", 5};
		myArr->print();
		delete myArr;

		BaseArray<int>* myArrinBase = new MyArr<int>{ "desc", 5 };
		myArrinBase->print();
		delete myArrinBase;
	}

	std::cout << "End of method\n\n";
}