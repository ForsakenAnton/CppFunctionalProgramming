
#include <iostream>
#include "Point2D.h"
#include "Number.h"
#include "NumberArray.h"
#include "MyClass.h"

//Global function example ///////////////////////////////////////////////////
//Number operator+ (const Number& left, const Number& right)
//{
//    return Number{ left.value + right.value };
//}
/////////////////////////////////////////////////////////////////////////////

NumberArray createNumberArray()
{
	NumberArray numberArray{ 10 };

	return numberArray;
}

int main()
{
	{
		std::srand(std::time(nullptr));

		//Point2D emptyPoint;
		//emptyPoint.print();

		//Point2D somePoint{ 10 }; // Ok
		//somePoint.print();

		//// Point2D anotherPoint = 123; // Compile Error
		//Point2D anotherPoint{ 123 }; // Ok
		//anotherPoint.print();


		std::string str1 = "123";
		std::string str2 = "456";
		std::string reslutStr = str1 + str2;


		Number n1 = 10.123;
		Number n2 = 30;
		std::cout << n1.getValueString() << "\n";
		std::cout << n2.getValueString() << "\n";

		Number resultN = n1 + n2;
		std::cout << resultN.getValue() << "\n";

		auto anotherResult = n1 + 123;
		std::cout << anotherResult.getValue() << "\n";
		std::cout << anotherResult.getValueString() << "\n";

		std::cout << (n1 == n2) << "\n";
		std::cout << (n1 != n2) << "\n";
		std::cout << (n1 > n2) << "\n";
		std::cout << (n1 < n2) << "\n";

		// prefix ++ --
		std::cout << (++n1).getValue() << "\n";
		std::cout << n1.getValueString() << "\n";
		std::cout << (++n1).getValue() << "\n";
		std::cout << n1.getValueString() << "\n";

		// postfix ++ --
		std::cout << (n1++).getValue() << "\n";
		std::cout << n1.getValue() << "\n";
		std::cout << n1.getValueString() << "\n";
		std::cout << (n1++).getValue() << "\n";
		std::cout << n1.getValueString() << "\n";

		std::cout << "\n\n\n\n";

		// << >>

		std::cout << n1 << "\n";

		//std::cin >> n1 >> n2;

		std::cout << n1 << "\n";
		std::cout << n2 << "\n";



		// []
		NumberArray numberArr{ 3 };

		try
		{
			for (int i = 0; i < numberArr.getNumbersSize(); i++)
			{
				std::cout << numberArr[i] << "\n";
			}

			Number tempNumber = Number{ 123 };

			numberArr[1] = tempNumber;
			std::cout << numberArr[1] << "\n";
			std::cout << numberArr[100000000] << "\n";

		}
		catch (const std::exception& ex)
		{
			std::cout << ex.what() << "\n";
		}

		std::cout << "\n\n\n";

		// Copy Constructor and operator=

		// copy ctor
		NumberArray anotherNumberArr = numberArr;

		std::cout << "Original arr:\n";
		for (int i = 0; i < numberArr.getNumbersSize(); i++)
		{
			std::cout << numberArr[i] << "\n";
		}

		std::cout << "Cloned arr:\n";
		for (int i = 0; i < anotherNumberArr.getNumbersSize(); i++)
		{
			std::cout << anotherNumberArr[i] << "\n";
		}

		std::cout << "\n\n\n";

		// operator=
		NumberArray someArr{ 2 };
		someArr = someArr; // = to itself
		someArr = numberArr;

		std::cout << "Original arr:\n";
		for (int i = 0; i < numberArr.getNumbersSize(); i++)
		{
			std::cout << numberArr[i] << "\n";
		}

		std::cout << "Cloned arr:\n";
		for (int i = 0; i < anotherNumberArr.getNumbersSize(); i++)
		{
			std::cout << anotherNumberArr[i] << "\n";
		}
	}


	//{
	//	MyClass obj1;
	//	MyClass obj2;
	//	MyClass obj3;

	//	//obj1.setDiscount(10);
	//	//obj2.setDiscount(20);
	//	//obj3.setDiscount(30);

	//	MyClass::setDiscount(10);

	//	std::cout << obj1.getDiscount() << "\n";
	//	std::cout << obj2.getDiscount() << "\n";
	//	std::cout << obj3.getDiscount() << "\n";

	//	MyClass newObj = obj2; // copy ctor
	//	//newObj = obj3; // operator=

	//	int* p;
	//	int* p2 = nullptr;
	//	std::cout << "";

	//	//if (p == nullptr) // not work
	//	if (p2 == nullptr) // work
	//	{

	//	}
	//}


	// about right value (&&)
	{
		int leftValue = 10; // left value
		int* pLeftValue = &leftValue; // pointer left value
		int& refLeftValue = leftValue; // reference left value
		//int& refLeftValue = 123; // Compile Error. Ми не можемо створити посилання на літерал
		10; // right value та одночасно літерал
		//10 = 20; // Compile Error. Ми не можемо дати літералу нове значення

		int&& rightValue = 123; // ok
		//int&& refRightValue2 = leftValue; // Compile Error. Ми не можемо створити посилання на left value
		rightValue = 456; // ok
		//int&& anotherRightValue = rightValue; // Compile Error. rightValue - це одночасно left value

		rightValue = std::move(leftValue); // std::move - це каст до right value

		std::cout << "==============================\n\n\n\n\n\n\n\n\n";
		//NumberArray numberArr = createNumberArray();
		NumberArray numberArr = std::move(createNumberArray());
	}


	{
		std::cout << "==============================\n\n\n\n\n\n\n\n\n";
		NumberArray numberArr1{ 5 };
		//NumberArray numberArr2 = numberArr1; // copy ctor
		NumberArray numberArr2 = std::move(numberArr1); // move ctor

		std::cout << numberArr2.getNumbersSize() << "\n"; // 5
		std::cout << numberArr1.getNumbersSize() << "\n"; // 0
	}
}