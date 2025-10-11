#include <iostream>

class Car
{
private:
	std::string name;

	class Engine
	{
	private:
		int power;

	public:
		explicit Engine(int power) : power{ power }
		{
		}

		void setPower(int value)
		{
			power = value;
		}

		int getPower() const
		{
			return power;
		}

		void showPower() const
		{
			std::cout << "Power: " << power << "\n";
		}
	};

	Engine engine;

public:
	Car(const std::string& name, int power) : name{ name }, engine{ power }
	{
	}

	void printInfo() const
	{
		std::cout << "Name: " << name << "\n";
		//std::cout << "Power: " << engine.power << "\n";
		engine.showPower();
	}

	void setPower(int value)
	{
		engine.setPower(value);
	}
};

int main()
{
	Car car{ "CarName", 123 };
	//Car::Engine engine{ 123 };
	car.printInfo();
	car.setPower(456);
	car.printInfo();
}
