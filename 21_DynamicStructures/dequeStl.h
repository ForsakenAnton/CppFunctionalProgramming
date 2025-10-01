#pragma once
#include <iostream>
#include <deque>

void dequeStl()
{
	std::deque<std::string> deq{ "1", "2", "3", "4", "5", "6", "7", "8", "9", "10", };

	deq.emplace_front("first");
	deq.emplace_back("last");

	for (size_t i = 0; i < deq.size(); i++)
	{
		std::cout << deq[i] << " ";
	}
	std::cout << "\n";


	// Кільцева черга
	std::string completedEl = deq.front();
	std::cout << "first element completed it's work: " << completedEl << "\n";
	deq.pop_front();
	deq.push_back(completedEl);

	for (size_t i = 0; i < deq.size(); i++)
	{
		std::cout << deq[i] << " ";
	}
	std::cout << "\n";
}