
#include <iostream>
#include "Point2D.h"
#include "Number.h"
#include "NumberArray.h"

//Global function example ///////////////////////////////////////////////////
//Number operator+ (const Number& left, const Number& right)
//{
//    return Number{ left.value + right.value };
//}
/////////////////////////////////////////////////////////////////////////////


int main()
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