// 24_Exceptions.cpp : This file contains the 'main' function. Program execution begins and ends there.
// 
//
// Standard C++ exception hierarchy (common classes, C++11/C++14-focused):
//
// std::exception                              (header <exception>) - root of the standard exception hierarchy
// ├─ std::bad_alloc                           (header <new>)       - memory allocation failure
// ├─ std::bad_cast                            (header <typeinfo>)
// ├─ std::bad_typeid                          (header <typeinfo>)
// ├─ std::bad_exception                       (header <exception>)
// ├─ std::bad_function_call                   (header <functional>) // since C++11
// ├─ std::bad_weak_ptr                        (header <memory>)     // since C++11
// ├─ std::logic_error                         (header <stdexcept>)
// │    ├─ std::domain_error
// │    ├─ std::invalid_argument
// │    ├─ std::length_error
// │    └─ std::out_of_range
// ├─ std::runtime_error                       (header <stdexcept>)
// │    ├─ std::range_error
// │    ├─ std::overflow_error
// │    ├─ std::underflow_error
// │    ├─ std::regex_error                     (header <regex>)     // since C++11
// │    ├─ std::future_error                    (header <future>)    // since C++11
// │    └─ std::system_error                    (header <system_error>) // since C++11; commonly derives from std::runtime_error
// │         └─ std::ios_base::failure          (header <ios>)       // historically derived directly from std::exception; since C++11 often associated with std::system_error
// 
// Additional standard utilities related to exceptions (not all are derived classes):
// - std::exception_ptr       (header <exception>) // holds a reference to an exception object
// - std::nested_exception    (header <exception>) // mixin to nest exceptions
// - std::bad_array_new_length (header <new>)      // introduced later (C++11/C++17 variants exist); check your standard
// 
// Notes:
// - This is a concise overview of the common standard exceptions in C++11/C++14. The full standard and later revisions (C++17, C++20) introduce additional exception types.
// - Headers shown are the ones that typically declare the types; consult cppreference or the standard for exact details per standard version.
// - The depicted inheritance reflects common relationships; some historical inheritance changed across standards (e.g., ios_base::failure).
//
// Make all hierarchy of exceptions in C++ in comments

#include <iostream>
#include <string>

int devide(int x, int y)
{
	if (y == 0)
	{
		throw std::invalid_argument("Divizion by zero");
	}

	return x / y;
}

int devideWithTryCatchThrow(int x, int y)
{
	try
	{
		if (y == 0)
		{
			throw std::invalid_argument("Divizion by zero");
		}

		return x / y;
	}
	catch (const std::exception& ex)
	{
		std::cout << "Exception in innder block - " << ex.what() << "\n";

		throw;
	}
}

int main()
{
	try
	{
		int x = 10;
		int y = 0;

		//int res = devide(x, y);
		int res = devideWithTryCatchThrow(x, y);

		int oneTwoThree = std::stoi("123"); // Ok
		int sth = std::stoi("qwerty"); // Exception

	}
	catch (const std::exception& ex)
	{
		std::cout << ex.what();
	}
}