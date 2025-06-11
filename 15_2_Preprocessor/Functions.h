#pragma once
#include <iostream>

void sum(int left, int right);
void minus(int left, int right);

template <typename T>
void devide(T left, T right);

template <typename T>
void devide(T left, T right)
{
	std::cout << left / right << "\n";
}