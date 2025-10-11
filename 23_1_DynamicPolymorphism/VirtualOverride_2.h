#pragma once
#include <iostream>

class Animal
{
protected:
	std::string name;

public:
	explicit(true) Animal(const std::string& name) : name{ name }
	{
	}

	virtual void makeSound() const
	{
		std::cout << "Animal with '" << name << "' makes some sound...\n";
	}
};

class Cat : public Animal
{
public:
	std::string catDescription = "This is a cat";

	explicit(true) Cat(const std::string& name) : Animal{ name }
	{
	}

	void makeSound() const
	{
		std::cout << "Cat with'" << name << "' makes meow...\n";
	}
};

class Dog : public Animal
{
public:
	std::string dogDescription = "This is a dog";

	explicit(true) Dog(const std::string& name) : Animal{ name }
	{
	}

	void makeSound() const override
	{
		std::cout << "Dog with'" << name << "' makes meow...\n";
	}
};

void printAnimalDescription(const Animal* animal)
{
	const Cat* cat = dynamic_cast<const Cat*>(animal);
	const Dog* dog = dynamic_cast<const Dog*>(animal);

	if (cat != nullptr)
	{
		std::cout << "Desc: " << cat->catDescription << "\n";
	}
	else if (dog != nullptr)
	{
		std::cout << "Desc: " << dog->dogDescription << "\n";
	}
	else
	{
		std::cout << "There are neither cat or dog\n";
	}
}


void virtualOverride_2()
{
	Cat* cat = new Cat{ "Tom" }; // Cat

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

		Animal* uknownAnimal = new Animal{ "Unknown" };
		Cat* catFromUnknownAnimal = (Cat*)uknownAnimal; // Animal is cat, but it's not true !!!
		catFromUnknownAnimal->makeSound();

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

		Animal* uknownAnimal = new Animal{ "Unknown" };
		Cat* catFromUnknownAnimal = dynamic_cast<Cat*>(uknownAnimal); // Animal is cat, but it's not true !!! Result is nullptr
		if (catFromUnknownAnimal != nullptr)
		{
			catFromUnknownAnimal->makeSound();
		}

		Animal* dogAnimal = new Dog{ "Jack" };
		Cat* catFromDogAnimal = dynamic_cast<Cat*>(dogAnimal); // Animal is cat, but it's a dog !!! Result is nullptr
		if (catFromDogAnimal != nullptr)
		{
			catFromDogAnimal->makeSound();
		}


		Cat c{" CatName "};
		//Animal a = c; slicing
		Animal* a = &c; // uppercasting
		a->makeSound(); // meow

		printAnimalDescription(catFromAnimal);
		printAnimalDescription(anotherCatFromAnimal);
		printAnimalDescription(uknownAnimal);
		printAnimalDescription(catFromUnknownAnimal);
		printAnimalDescription(dogAnimal);
		printAnimalDescription(catFromDogAnimal);
	}
}