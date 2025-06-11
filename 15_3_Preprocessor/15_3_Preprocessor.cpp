
#include <iostream>
#include "Functions.h"

int main()
{
#ifdef FUNCTIONAL
    functional();
    FUNCTIONAL();
#endif // FUNCTIONAL

#ifdef OOP
    oop();
    OOP();
#endif // OOP
}