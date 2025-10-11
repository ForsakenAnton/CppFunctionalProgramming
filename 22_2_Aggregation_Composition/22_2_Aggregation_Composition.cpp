
#include <iostream>

// for composition
class Processor
{
private:
	std::string name;
	float cpu;

public:
	Processor(const std::string& name, float cpu) :
		name{ name }, 
		cpu{ cpu }
	{
	}

	void print() const
	{
		std::cout << "Processor Name: " << name << "\n";
		std::cout << "CPU: " << cpu << "\n";
	}
};

// for composition
class Screen
{
private:
	float diagonal;

public:
	explicit Screen(float diagonal) :
		diagonal{ diagonal }
	{
	}

	void print() const
	{
		std::cout << "Diagonal: " << diagonal << "\n";
	}
};

// for aggregation
class Stylus
{
private:
	std::string manufacturerName;

public:
	explicit Stylus(const std::string& manufacturerName) :
		manufacturerName{ manufacturerName }
	{
	}

	void print() const
	{
		std::cout << "Stylus Manufacturer Name: " << manufacturerName << "\n";
	}
};

class Smartphone
{
private:
	Processor processor;
	Screen* screen;
	Stylus* stylus;

public:
	Smartphone(const std::string& name, float cpu, float diagonal, Stylus* stylus = nullptr) :
		processor{ name, cpu }, // composition
		screen{ new Screen{diagonal} }, // composition
		stylus{ stylus } // aggregation
	{
	}

	void printInfo() const
	{
		processor.print();
		screen->print();

		if (stylus != nullptr)
		{
			stylus->print();
		}

		std::cout << "\n";
	}

	~Smartphone()
	{
		// composition
		// processor - автоматичний об'єкт. Ми його явно не видаляємо

		// composition
		if (screen != nullptr)
		{
			delete screen;
			screen = nullptr;
		}

		// aggregation
		//if (stylus != nullptr)
		//{
		//    delete stylus; // так при агрегації робити не можна
		//}
	}
};


int main()
{
	Smartphone smart{ "MediaTek 100500", 3.5F, 8.0F };

	Stylus* stylus = new Stylus{ "Samsung" };
	Smartphone smartWithStylus{ "Kirin 990", 3.2F, 7.0F, stylus };

	smart.printInfo();
	smartWithStylus.printInfo();

	if (stylus != nullptr)
	{
		delete stylus;
		stylus = nullptr;
	}
}
