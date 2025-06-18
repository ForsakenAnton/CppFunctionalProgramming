#include "Elevator.h"

void Elevator::setCurrentFloor(int floor)
{
	currentFloor = floor;
}

Elevator::Elevator()
{
	lastFloor = 0;
	firstFloor = 0;
	power = false;
	currentFloor = 0;
}

Elevator::Elevator(int lastFloor, int firstFloor, bool power, int currentFloor)
{
	std::cout << "Constructor for " << this << "\n";

	this->lastFloor = lastFloor;
	this->firstFloor = firstFloor;
	this->power = power;
	this->currentFloor = currentFloor;
}

void Elevator::setLastFloor(int floor)
{
	if (floor >= 1 && floor >= firstFloor)
	{
		lastFloor = floor;
	}
}

void Elevator::setFirstFloor(int floor)
{
	if (floor <= lastFloor)
	{
		firstFloor = floor;
	}
}

int Elevator::getLastFloor()
{
	return lastFloor;
}

int Elevator::getFirstFloor()
{
	return firstFloor;
}

void Elevator::togglePower()
{
	power = !power;
}

bool Elevator::getPower()
{
	return power;
}

int Elevator::getCurrentFloor()
{
	return currentFloor;
}

void Elevator::callElevator(int targetFloor)
{
	if (!power)
	{
		std::cout << "The elevator's power is off\n\n";
		std::this_thread::sleep_for(std::chrono::milliseconds(500));
		return;
	}

	if (targetFloor < firstFloor || targetFloor > lastFloor)
	{
		std::cout << "Where are you calling the elevator from!??\n\n";
		std::this_thread::sleep_for(std::chrono::milliseconds(500));
		return;
	}

	if (currentFloor == targetFloor)
	{
		std::cout << "The elevator is already here.\n\n";
		std::this_thread::sleep_for(std::chrono::milliseconds(500));
		return;
	}

	std::cout << "The elevator is mooving...\n";
	std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	int floor = currentFloor;
	for (
		int i = currentFloor < targetFloor
		? targetFloor - currentFloor
		: currentFloor - targetFloor;
		i >= 0;
		i--
		)
	{
		std::cout << "Floor: " << floor << "\n";
		floor = currentFloor < targetFloor ? floor + 1 : floor - 1;
		std::this_thread::sleep_for(std::chrono::milliseconds(500));
	}
	std::this_thread::sleep_for(std::chrono::milliseconds(500));

	this->setCurrentFloor(targetFloor);

	std::cout << "The elevator is at the " << targetFloor << " floor.\n\n";
}

Elevator::~Elevator() // noexcept
{
	std::cout << "~Destructor for " << this << "\n";
}