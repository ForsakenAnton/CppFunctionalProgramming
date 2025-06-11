#pragma once
#include <iostream>

#include "Directives.h"

#ifdef FUCTIONAL_PROGRAMMING
void functional();
#define FUNCTIONAL functional
#endif // FUCTIONAL_PROGRAMMING

#ifdef OOP_PROGRAMMING
void oop();
#define OOP oop
#endif // OOP_PROGRAMMING