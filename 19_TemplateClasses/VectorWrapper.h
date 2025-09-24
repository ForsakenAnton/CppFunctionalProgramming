#pragma once
#include <iostream>
#include <vector>

template <typename T>
class VectorWrapper
{
private:
	std::vector<T> data;

public:
	void pushBack(const T value);
	bool pushBackPositive(const T value);
	void display() const;
};

template<typename T>
void VectorWrapper<T>::pushBack(const T value)
{
	data.push_back(value);
}

template<typename T>
bool VectorWrapper<T>::pushBackPositive(const T value)
{
	if (value > T())
	{
		this->pushBack(value); 

		return true;
	}

	return false;
}

template<typename T>
void VectorWrapper<T>::display() const
{
	for (const T& el : data)
	{
		std::cout << el << " ";
	}
	std::cout << std::endl << std::endl;
}



// Part Class Method Specialization for const char*
//template<typename T>
//bool VectorWrapper<T>::pushBackPositive(const T value)
template<>
bool VectorWrapper<const char*>::pushBackPositive(const char* value)
{
	if (value != nullptr && value[0] != '\0')
	{
		this->pushBack(value);
		return true;
	}

	return false;
}

//// Full Class Specialization for Pet
//template<>
//class VectorWrapper<Pet> // (!) <Pet>
//{
//private:
//	std::vector<Pet> data; // (!)
//
//public:
//	// TODO...
//}