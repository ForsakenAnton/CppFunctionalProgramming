
#include <iostream>
#include <vector>
#include <stdarg.h>

#pragma region Functions with variaty number of arguments
static int sumNumbers(int count, int first, ...)
{
	int sum = 0;

	const int* pFirst = &first;
	for (size_t i = 0; i < count; i++)
	{
		sum += *pFirst;
		//std::cout << *pFirst << "\n";
		pFirst += 2; // 8 bytes ahead
	}

	return sum;
}

// Для останнього параметру
template<typename T>
void print(const T& value)
{
	std::cout << value << "\n";
}

template<typename T, typename... Args>
void print(const T& value, const Args&... args)
{
	print(value);
	print(args...); // останній параметер іде у метод вище
}

// Для останнього параметру
template<typename T>
T sum(const T& value)
{
	return value;
}

template<typename T, typename ...Args>
T sum(const T& value, const Args&... args)
{
	return value + sum(args...);
}


// Fold Expression
template<typename... Args>
void printFoldExpression(const Args&... args)
{
	((std::cout << args << "\n"), ...);
}

// Fold Expression
template<typename ...Args>
auto sumFoldExpression(const Args&... args)
{
	return (args + ...);
}

#pragma endregion

#pragma region InitializerList
template<typename T>
class ArrayWrapper
{
private:
	size_t arrSize;
	int* arr;
	std::vector<T> vec;

public:
	ArrayWrapper(const std::initializer_list<T>& initList) :
		arrSize{ initList.size() },
		arr{ arrSize == 0 ? nullptr : new T[arrSize] },
		vec{ initList } // ok
	{
		if (arrSize == 0)
		{
			return;
		}

		for (const T& el : initList)
		{
			*arr = el;
			arr++;
		}

		arr -= arrSize;
	}

	void initListDemo_Stub(const std::initializer_list<T>& initList) // Stub - заглушка
	{
		for (const T& el : initList)
		{
			std::cout << el << " ";
		}

		std::cout << "\n";
	}

	friend std::ostream& operator<<(std::ostream& os, const ArrayWrapper<T>& obj)
	{
		for (size_t i = 0; i < obj.arrSize; i++)
		{
			os << obj.arr[i] << " ";
		}

		return os;
	}
};
#pragma endregion

#pragma region About Iterators
void iteratorsDemo()
{
	std::string str = "Qwerty";

	/*auto*/ std::string::iterator it = str.begin();
	std::cout << *it << "\n"; // Q
	it++; // w
	it += 2; // r
	std::cout << *it << "\n"; // r

	auto itEnd = str.end();
	itEnd--; // y
	*itEnd = 'Y';
	std::cout << *itEnd << "\n"; // Y

	auto constIt = str.cbegin(); // const iterator
	//*constIt = 'q'; // compile error
}
#pragma endregion

#pragma region constexpr
template <typename T>
class MyClass
{
private:
	T _value;

public:
	MyClass(T val) : _value(val)
	{
	}

	T getValue() const
	{
		return _value;
	}

	void minusOperation(T value)
	{
		// Нижче constexpr(C++ 17+) каже, що ми знаємо значення цього куска коду
		// вже на етапі компіляції, тому constexpr тут потрібен,
		// інакше простої перевірки is_same не хватає, щоб дати зрозуміти компілятору,
		// що сюди не попаде, наприклад, int або ще якийсь тип. 

		//if constexpr (std::is_same<T, std::string>().value) // Ok
		if constexpr (std::is_same_v<T, std::string>) // Ok
		{
			std::cout << "Performing string subtraction\n";
			int fieldLength = _value.length();
			int valueLength = value.length();

			_value = fieldLength > valueLength ?
				_value.substr(0, fieldLength - valueLength) :
				"";
		}
		else
		{
			std::cout << "Performing other types subtraction\n";
			_value -= value;
		}
	}

	void printValue() const
	{
		std::cout << "Value: " << _value << std::endl;
	}
};
#pragma endregion



int main()
{
	std::cout << sumNumbers(5, 1, 2, 3, 4, 5) << "\n"; // 15

	print(1, 2.5, "Hello", 'c');
	print(123);

	std::cout << sum(5, 1, 2, 3, 4, 5) << "\n"; // 20s

	printFoldExpression(1, 2.5, "Hello", 'c');
	std::cout << sumFoldExpression(5, 1, 2, 3, 4, 5) << "\n"; // 20s


	ArrayWrapper<int> arr{ 3, 4, 5, 6 }; // Ok
	std::cout << arr << "\n";

	//arr.initListDemo_Stub{ 1, 2, 3, 4, 5 }; // complile error
	arr.initListDemo_Stub(std::initializer_list<int>{1, 2, 3, 4}); // Ok
	arr.initListDemo_Stub({ 1, 2, 3, 4 }); // Ok


	iteratorsDemo();


	MyClass<int> intObject{ 5 };
	intObject.minusOperation(3);
	intObject.printValue(); // 2

	// Далі ми будемо віднімати рядки, наприклад: "Qwerty" - "abc" == "Qwe"
	MyClass<std::string> stringObject("C++ is such a hard language"); // 27 symbols
	stringObject.minusOperation("123456789012345678901234"); // 24 symbols
	stringObject.printValue(); // "C++"
	stringObject.minusOperation("12345"); // 5 symbols
	stringObject.printValue(); // ""


	//int* p = new int[5] { 1, 2, 3, 4, 123 };
	//std::cout << *p << std::endl;
	//p++;
	//p++;
	//p = p + 2;
	//std::cout << *p << std::endl;
}

