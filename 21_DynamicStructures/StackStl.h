#pragma once
#include <iostream>
#include <stack>

void stackStl()
{
	std::stack<int> s;

	int x = 123;
	s.push(x);
	s.emplace(x);
	s.push(456);
	s.emplace(789);
	
	if (!s.empty())
	{
		std::cout << s.top() << "\n";
		s.pop();
		std::cout << s.top() << "\n";
	}

	while (!s.empty())
	{
		std::cout << s.top() << "\n";
		s.pop();
	}
}