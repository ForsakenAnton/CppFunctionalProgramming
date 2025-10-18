#pragma once
#include <iostream>
#include <vector>

class Animal abstract
{
protected:
	std::string name;

public:
	explicit(true) Animal(const std::string& name) : name{ name }
	{
	}

	virtual void makeSound() const = 0; // pure virtual | abstract method
};

void Animal::makeSound() const
{
	std::cout << "Default behavior...\n\n";
}

class Cat final : public Animal
{
public:
	std::string catDescription = "This is a cat";

	explicit(true) Cat(const std::string& name) : Animal{ name }
	{
	}

	void makeSound() const override
	{
		Animal::makeSound();
		std::cout << "Cat with'" << name << "' makes meow...\n";
	}

	virtual void info()
	{
		// ...
	}
};

//class MaineCoon : public Cat
//{
//
//};

class Dog : public Animal
{
public:
	std::string dogDescription = "This is a dog";

	explicit(true) Dog(const std::string& name) : Animal{ name }
	{
	}

	void makeSound() const override
	{
		std::cout << "Dog with'" << name << "' makes woof...\n";
	}
};

class Raccoon : public Animal
{
public:
	explicit Raccoon(const std::string& name) : Animal{ name }
	{

	}

	void makeSound() const override
	{
		std::cout << "Racoon with'" << name << "' makes hrrrrrrrr...\n";
	}
};


void pureVirtualMethods()
{
	Cat* cat = new Cat{ "Tom" }; // Cat

	//Animal a{ "qwety" };
	//a.makeSound()

	Animal* animal = cat; // // uppercasting. Ok, Cat is animal
	cat->makeSound(); // meow
	animal->makeSound(); // meow

	Animal* anotherAnimal = new Cat{ "Lucy" }; // uppercasting. Ok, Cat is animal
	anotherAnimal->makeSound(); // meow

	// downcasting using static_cast
	{
		// (Cat*) == static_cast<Cat*>(value)

		Cat* catFromAnimal = (Cat*)animal; // downcasting. Animal is cat. (Cat*) - ok, but dangerous
		Cat* anotherCatFromAnimal = (Cat*)anotherAnimal; // downcasting. Animal is cat. (Cat*) - ok, but dangerous
		catFromAnimal->makeSound();
		anotherCatFromAnimal->makeSound();

		//Animal* uknownAnimal = new Animal{ "Unknown" };
		//Cat* catFromUnknownAnimal = (Cat*)uknownAnimal; // Animal is cat, but it's not true !!!
		//catFromUnknownAnimal->makeSound();

		Animal* dogAnimal = new Dog{ "Jack" };
		Cat* catFromDogAnumal = (Cat*)dogAnimal; // Animal is cat, but it's a dog !!!
		catFromDogAnumal->makeSound();
	}

	// downcasting using dynamic_cast
	{
		Cat* catFromAnimal = dynamic_cast<Cat*>(animal); // downcasting. Animal is cat. (Cat*) - ok
		Cat* anotherCatFromAnimal = dynamic_cast<Cat*>(anotherAnimal); // downcasting. Animal is cat. (Cat*) - ok
		catFromAnimal->makeSound();
		anotherCatFromAnimal->makeSound();

		//Animal* uknownAnimal = new Animal{ "Unknown" };
		//Cat* catFromUnknownAnimal = dynamic_cast<Cat*>(uknownAnimal); // Animal is cat, but it's not true !!! Result is nullptr
		//if (catFromUnknownAnimal != nullptr)
		//{
		//	catFromUnknownAnimal->makeSound();
		//}

		Animal* dogAnimal = new Dog{ "Jack" };
		Cat* catFromDogAnimal = dynamic_cast<Cat*>(dogAnimal); // Animal is cat, but it's a dog !!! Result is nullptr
		if (catFromDogAnimal != nullptr)
		{
			catFromDogAnimal->makeSound();
		}


		Cat c{ " CatName " };
		//Animal a = c; slicing
		Animal* a = &c; // uppercasting
		a->makeSound(); // meow
	}

	// references with dynamic polymorphism
	{
		Cat tom{ "Tom" };

		Animal& refTom = tom;
		refTom.makeSound();

		Cat dynamicTom = dynamic_cast<Cat&>(refTom);
		dynamicTom.makeSound();
		std::cout << dynamicTom.catDescription << "\n";

		//Dog dogFromCat = dynamic_cast<Dog&>(refTom); // runtime error (std::bad_cast)
		//dogFromCat.makeSound();
		//std::cout << dogFromCat.dogDescription << "\n";
	}


	{
		//Cat cat{ "Tom" };
		//Animal a = cat;
		//a = cat;

		Raccoon r{ "some name" };

		std::vector<Animal*> v;
		v.emplace_back(new Cat{ "Tom" });
		v.push_back(new Dog{ "Jack" });
		v.push_back(new Raccoon{ "lucy" });

		for (const auto& el : v)
		{
			el->makeSound();
		}
	}
}