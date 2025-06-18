
#include <iostream>
#include "Elevator.h"

int main()
{
	Elevator elevator{ 16, 1, false, 8 };
	Elevator elevator2{ 31, 1, true, 10 };

	std::cout << &elevator << "\n";
	std::cout << &elevator2 << "\n\n";

	elevator.callElevator(11);
	elevator.togglePower();
	elevator.callElevator(11);
	elevator.callElevator(5);
	elevator.callElevator(100);
	elevator.callElevator(-100);
	elevator.callElevator(1);
}
