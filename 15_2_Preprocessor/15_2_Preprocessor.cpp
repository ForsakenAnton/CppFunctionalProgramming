
#include <iostream>
#include "Functions.h"
#include "Person.h"

int main()
{
    sum(3, 4);
    minus(3, 4);

    devide(10.0F, 3.0F);

    Person p{ "Alice", 25 };
    p.info();

    std::string sth = "sth";
    std::cout << p.equalPersonWithSomething(sth);
}
