#pragma once
#include <iostream>
#include <array>
#include <vector>

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

	virtual void showInfo() const
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

	void showInfo() const override
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

	void showInfo() const override
	{
		Employee::showInfo();
		std::cout << "Part Time Employee Salary: " << getSalary() << "\n";
	}
};

void showEmployeeInfo(const Employee& employee)
{
	employee.showInfo();
}

void showEmployeeInfos(Employee* const* employees, size_t size)
{
	for (size_t i = 0; i < size; ++i)
	{
		if (employees[i] != nullptr)
		{
			employees[i]->showInfo();
			std::cout << "\n";
		}
	}
}



static void virtualOverride()
{
	//PartTimeEmployee partTimeEmp{ "Charlie", 20, 80 };
	//Employee emp = partTimeEmp; // slicing


	const int SIZE = 7;
	Employee* employees[SIZE] =
	{
		new FullTimeEmployee{ "Alice", 5000, 1000 },
		new PartTimeEmployee{ "Charlie", 20, 80 },
		new Employee{ "Charlie", 20 },
		new FullTimeEmployee{ "Bob", 6000, 1500 },
		new PartTimeEmployee{ "Dave", 25, 60 },
		new FullTimeEmployee{ "Tom", 10000, 2500 },
		new PartTimeEmployee{ "Eve", 30, 40 }
	};

	for (size_t i = 0; i < 7; i++)
	{
		employees[i]->showInfo();
		std::cout << "\n";
	}
	std::cout << "\n\n\n\n\n\n";

	showEmployeeInfos(employees, SIZE);

	PartTimeEmployee* pte = new PartTimeEmployee{ "Charlie", 20, 80 };
	showEmployeeInfo(*pte);
	showEmployeeInfo((*(Employee*)pte));
	Employee* emp = pte; // cast from derived to base (uppercasting)
	showEmployeeInfo(*emp);
	emp->showInfo(); // PartTimeEmployee::showInfo();

	//PartTimeEmployee* newPte = (PartTimeEmployee*)emp; // downcasting (ok, but danderous)
	PartTimeEmployee* newPte = static_cast<PartTimeEmployee*>(emp); // downcasting (ok, but danderous)
	auto salary1 = newPte->getSalary();

	FullTimeEmployee* fullPte = (FullTimeEmployee*)emp; // emp is PartTimeEmployee, not FullTimeEmployee
	auto salary2 = fullPte->getSalary(); // bonus = ???

	// Правильний спосіб
	PartTimeEmployee* newPte2 = dynamic_cast<PartTimeEmployee*>(emp);
	auto salary3 = newPte2->getSalary();

	FullTimeEmployee* fullPte2 = dynamic_cast<FullTimeEmployee*>(emp);
	if (fullPte2 != nullptr)
	{
		auto salary4 = fullPte2->getSalary();
	}

	std::cout << "\n\n";
}
