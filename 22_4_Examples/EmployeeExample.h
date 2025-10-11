#pragma once
#include <iostream>
#include <array>

class Employee
{
protected:
	std::string name;
	double baseRate;

public:
	Employee(const std::string& name, double rate) :
		name{ name },
		baseRate{ rate }
	{
	}

	void showInfo() const
	{
		std::cout << "Name: " << name << ", Base Rate: " << baseRate << "\n";
	}

	//double getSalary(int hours) const
	//{
	//	return baseRate * hours;
	//}
};

class FullTimeEmployee : public Employee
{
private:
	double bonus;

public:
	FullTimeEmployee(const std::string& name, double rate, double bonus) :
		Employee{ name, rate },
		bonus{ bonus }
	{
	}

	double getSalary() const
	{
		return baseRate + bonus;
	}

	void showInfo() const
	{
		Employee::showInfo();
		std::cout << "Full Time Employee Salary: " << getSalary() << "\n";
	}
};

class PartTimeEmployee : public Employee
{
private:
	int hoursWorked;

public:
	PartTimeEmployee(const std::string& name, double rate, int hours) :
		Employee{ name, rate },
		hoursWorked{ hours }
	{
	}

	double getSalary() const
	{
		return baseRate * hoursWorked;
	}

	void showInfo() const
	{
		Employee::showInfo();
		std::cout << "Part Time Employee Salary: " << getSalary() << "\n";
	}
};

static void employeeExample()
{
	std::array<FullTimeEmployee, 3> fulltimeEmployees =
	{
		FullTimeEmployee{ "Alice", 5000, 1000 },
		FullTimeEmployee{ "Bob", 6000, 1500 },
		FullTimeEmployee{ "Tom", 10000, 2500 },
	};

	std::array<PartTimeEmployee, 3> partTimeEmployees =
	{
		PartTimeEmployee{ "Charlie", 20, 80 },
		PartTimeEmployee{ "Dave", 25, 60 },
		PartTimeEmployee{ "Eve", 30, 40 },
	};

	for (const auto& el : fulltimeEmployees)
	{
		el.showInfo();
	}

	std::cout << "\n";

	for (const auto& el : partTimeEmployees)
	{
		el.showInfo();
	}

	std::cout << "\n\n";
}
