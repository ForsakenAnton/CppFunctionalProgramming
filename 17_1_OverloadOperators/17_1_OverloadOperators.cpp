
#include <iostream>
#include "Point2D.h"
#include "Number.h"

//Global function example ///////////////////////////////////////////////////
//Number operator+ (const Number& left, const Number& right)
//{
//    return Number{ left.value + right.value };
//}
/////////////////////////////////////////////////////////////////////////////


int main()
{
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
}