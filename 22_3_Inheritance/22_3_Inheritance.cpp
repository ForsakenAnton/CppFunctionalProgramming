
#include <iostream>

class Person
{
protected:
	std::string name;
	int age;

public:
	Person(const std::string& name, int age) :
		name{ name },
		age{ age }
	{
	}

	//Person() : Person("Anon", 0)
	//{

	//}

	void setNameAndAge(const std::string& nameValue, int ageValue)
	{
		this->name = nameValue;
		this->age = ageValue;
	}

	void print() const
	{
		std::cout << name << " - " << age << "\n";
	}
};

class Worker : public Person
{
private:
	double salary;

public:
	Worker(const std::string& name, int age, double salary) :
		Person{name, age},
		salary{ salary }
	{
	}

	void print() const
	{
		Person::print();
		std::cout << "Salary from worker: " << Person::name << " is " << salary << "\n";
	}
};

int main()
{
	Worker worker{ "John", 42, 100500 };
	worker.print();
	worker.setNameAndAge("Jack", 34);
	worker.print();
}
