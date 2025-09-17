#pragma once
#include <iostream>
//#include "Alice.h"

class Alice;

class Tom
{
private:
	bool isMarried;
	bool hasAccesToTomAccount;

public:
	Tom(bool isMarried, bool hasAccesToTomAccount);

	void marriage(Alice& alice);
	void getAccessToTomAccount(Alice& alice);

	friend std::ostream& operator<<(std::ostream& os, const Tom& tom);

	friend class Alice; // повністю товаришуємо з Alice
};
