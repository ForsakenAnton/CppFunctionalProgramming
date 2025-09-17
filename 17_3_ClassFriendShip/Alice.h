#pragma once
#include <iostream>
#include "Tom.h"

class Tom;

class Alice
{
private:
	bool isMarried;
	bool hasAccesToTomAccount;

public:
	Alice(bool isMarried, bool hasAccesToTomAccount);	

	void marriage(Tom& tom);
	void getAccessToTomAccount(Tom& tom);

	friend void Tom::marriage(Alice& tom); // (!) частково товаришуємо з Томом

	friend std::ostream& operator<<(std::ostream& os, const Alice& tom);
};
