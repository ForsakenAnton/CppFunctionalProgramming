
#include <iostream>
#include <string>

struct Person
{
	int age;
	std::string name;
	float salary;

	void printInfo()
	{
		std::cout << "Age: " << age << "\n";
		std::cout << "Name: " << name << "\n";
		std::cout << "Salary: " << salary << "\n\n";
	}

	bool setAge(int age)
	{
		if (age < 18)
		{
			return false;
		}

		this->age = age;

		return true;
	}

	std::string getAge()
	{
		return std::to_string(this->age) + " years old";
	}
};

struct PersonCollection
{
	Person people[10];
};

//typedef decltype(Person{}) person_type;

struct Display
{
	int width;
	int height;
};

struct Processor
{
	int cores;
	int threads;
};

struct Smartphone
{
	std::string brand;
	std::string model;
	std::string color;

	Display display;
	Processor processor;
};

struct SmartphoneFactory
{
	Smartphone createDefaultSmartphone()
	{
		Smartphone defaultSmartphone
		{ 
			"NoName", 
			"X", 
			"White",
			Display { 7, 7 },
			Processor { 4, 8 }
		};

		return defaultSmartphone;
	}
};

void registerPerson(Person& person)
{
	std::cout << "Enter age: ";
	std::cin >> person.age;

	std::cout << "Enter name: ";
	//std::cin.ignore(32767, '\n');
	std::cin.ignore(INT16_MAX, '\n');
	std::getline(std::cin, person.name, '\n');

	std::cout << "Enter salary: ";
	std::cin >> person.salary;
}

void printPerson(const Person& person)
{
	std::cout << "Age: " << person.age << "\n";
	std::cout << "Name: " << person.name << "\n";
	std::cout << "Salary: " << person.salary << "\n";
}

int main()
{
	//std::cout << INT16_MAX << "\n";
	//person_type person;
	//Person person;
	//person.name = "Anton";
	//std::cout << person.name << "\n";
	//std::cout << person.age << "\n";
	//std::cout << person.salary << "\n";



	//Person person{};
	//registerPerson(person);
	//printPerson(person);

	//person.printInfo();

	//bool isAgeSet = person.setAge(20);
	//std::cout << isAgeSet << "\n";

	//isAgeSet = person.setAge(17);
	//std::cout << isAgeSet << "\n";

	//std::cout << person.getAge() << "\n";



	Smartphone smartphone{};
	smartphone.brand = "Apple";
	smartphone.model = "Iphone 11";
	smartphone.color = "Black";

	smartphone.display.height = 6;
	smartphone.display.width = 7;

	smartphone.processor.cores = 4;
	smartphone.processor.threads = 8;

	Smartphone* pSmartphone = &smartphone;
	pSmartphone->color = "White";
	pSmartphone->processor.cores = 12;

	(*pSmartphone).color = "Green";

	SmartphoneFactory factory{};
	Smartphone defaultSmartphone = factory.createDefaultSmartphone();
	

	const int size = 3;
	Person persons[size]{};
	persons[1].name = "Anton";

	for (int i = 0; i < size; i++)
	{
		std::cout << persons[i].name << "\n";
	}

	PersonCollection personCollection{};
	for (int i = 0; i < 10; i++)
	{
		personCollection.people[i].age = i + 18;
		personCollection.people[i].name = "Person" + std::to_string(i);
		personCollection.people[i].salary = 100500 * (i + 1);
	}

	for (int i = 0; i < 10; i++)
	{
		personCollection.people[i].printInfo();
	}


	// sizeof with structs
	struct Point
	{
		int x;
		int y;
		char test;
	};

	struct Coordinate
	{
		Point point1;
		Point point2;
	};

	Point point1;
	std::cout << "Size of Point: " << sizeof(Point) << "\n";
	std::cout << "Size of Point: " << sizeof(point1) << "\n";

	Coordinate coordinate;
	std::cout << "Size of Coordinate: " << sizeof(Coordinate) << "\n";
	std::cout << "Size of Coordinate: " << sizeof(coordinate) << "\n";

	Coordinate* pCoordinate = &coordinate;
	std::cout << "Size of Coordinate: " << sizeof(pCoordinate) << "\n";
	std::cout << "Size of Coordinate: " << sizeof(*pCoordinate) << "\n";

	return 0;
}
