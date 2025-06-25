#pragma once
#include <iostream>

class Point2D
{
private:
	int x;
	int y;

public:
	Point2D(int x, int y) : x{ x }, y{y}
	{ 
	}

	explicit Point2D(int x) : Point2D{ x, 0 } // potensial problem
	{
	}

	Point2D() : Point2D{ 0 }
	{
	}

	void print()
	{
		std::cout << x << " - " << y << "\n";
	}

	friend void friendFunc();
};


void someFunc()
{
	Point2D point;
	//point.x ... // inaccessible
	// TODO...
}

void friendFunc()
{
	Point2D point;
	std::cout << point.x << "\n";
}