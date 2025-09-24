#include <iostream>

#include "VectorWrapper.h"
#include "Pet.h"
#include "Collection.h"
#include "Tuple.h"


int main()
{
	VectorWrapper<int> intVec;
	intVec.pushBack(1);
	intVec.pushBack(2);
	intVec.pushBack(3);
	intVec.display();
	intVec.pushBackPositive(4);
	intVec.pushBackPositive(-5);
	intVec.pushBackPositive(6);
	intVec.display();

	VectorWrapper<double> doubleVec;
	doubleVec.pushBack(1.1);
	doubleVec.pushBack(2.2);
	doubleVec.pushBack(3);
	doubleVec.display();
	doubleVec.pushBackPositive(4.4);
	doubleVec.pushBackPositive(-5.5);
	doubleVec.pushBackPositive(6.6);
	doubleVec.display();
	
	VectorWrapper<std::string> stringVec;
	stringVec.pushBack("Hello");
	stringVec.pushBack("World");
	stringVec.pushBackPositive("Positive");
	stringVec.pushBackPositive("");
	stringVec.display();

	Pet cat{ "Lucky", 5 };
	Pet dog{ "Jack", 7 };

	VectorWrapper<Pet> petVec;
	petVec.pushBack(cat);
	petVec.pushBack(dog);
	petVec.display();


	VectorWrapper<const char*> charPtrVec;
	charPtrVec.pushBack("C++");
	charPtrVec.pushBack("C#");
	charPtrVec.pushBackPositive("JS");
	charPtrVec.pushBackPositive("");

	Tuple<std::string, int> countryCodeUK;
	Tuple<std::string, int> countryCodeUS;
	countryCodeUS.setTuples("US", 1);
	countryCodeUK.setTuples("UK", 44);
	std::cout << "Country: " << countryCodeUK.getFirst() << " Code: " << countryCodeUK.getSecond() << std::endl;
	std::cout << "Country: " << countryCodeUS.getFirst() << " Code: " << countryCodeUS.getSecond() << std::endl;
	
	Collection<Tuple, std::string, int> collection;
	collection.addItem(countryCodeUK);
	collection.addItem(countryCodeUS);
	collection.displayItems();
}
