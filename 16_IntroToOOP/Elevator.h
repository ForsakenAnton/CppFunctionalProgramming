#pragma once
#include <iostream>
#include <thread>
#include <chrono>

// .Створити клас «Ліфт», що являє собою гранично
// спрощену модель ліфта. Клас повинен забезпечити :
// ▷ встановлення діапазон руху ліфта(нижній і верхній поверх);
// ▷ вмикання / вимикання ліфта;
// ▷ повернення поточного стану ліфта(працює / не працює);
// ▷ повернення поточного положення ліфта(поверх);
// ▷ опрацювання виклику ліфта(поверх).
// Написати програму, яка тестує клас «Ліфт»

class Elevator
{
private:
	int lastFloor;
	int firstFloor;
	bool power;
	int currentFloor;

	void setCurrentFloor(int floor);

public:
	Elevator();
	Elevator(int lastFloor, int firstFloor, bool power, int currentFloor);

	void setLastFloor(int floor);
	void setFirstFloor(int floor);

	int getLastFloor();
	int getFirstFloor();

	void togglePower();
	bool getPower();

	int getCurrentFloor();

	void callElevator(int targetFloor);

	~Elevator();
};