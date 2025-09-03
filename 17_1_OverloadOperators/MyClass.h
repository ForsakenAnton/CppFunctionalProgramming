#pragma once

class MyClass
{
private:
	int value;
	int* memoryValue;
	static int discount;

public:
	MyClass() :
		value{ 0 },
		memoryValue{ new int(123) }
	{
		//value = 0;
		//memoryValue = new int(123);
	}

	MyClass(const MyClass& right) :
		value{ right.value },
		//memoryValue{ right.memoryValue }
		memoryValue{ new int(*right.memoryValue) }
	{
		//this->value = right.value;
		////this->memoryValue = right.memoryValue;
		//this->memoryValue = new int(*right.memoryValue);
	}

	~MyClass()
	{
		if (memoryValue != nullptr)
		{
			delete memoryValue;
			memoryValue = nullptr;
		}
	}

	static void setDiscount(int d)
	{
		discount = d;
	}

	static int getDiscount()
	{
		return discount;
	}
};

int MyClass::discount = 0;