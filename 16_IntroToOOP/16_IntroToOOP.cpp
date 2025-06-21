
#include <iostream>
#include "Elevator.h"
#include "Product.h"

int main()
{
	//Elevator elevator{ 16, 1, false, 8 };
	//Elevator elevator2{ 31, 1, true, 10 };

	//std::cout << &elevator << "\n";
	//std::cout << &elevator2 << "\n\n";

	//elevator.callElevator(11);
	//elevator.togglePower();
	//elevator.callElevator(11);
	//elevator.callElevator(5);
	//elevator.callElevator(100);
	//elevator.callElevator(-100);
	//elevator.callElevator(1);

	{
		std::cout << Product::discount << "\n";
		Product::changeDiscount(400);
		Product::changeDiscountAndPrice(400, 500);

		std::string accesories[3] =
		{
			"Protected glass",
			"Charger",
			"TypeC",
		};

		Manufacturer google{ "Google" };
		Product googleProduct
		{
			"Google Pixel 8 Pro",
			1000.99,
			3,
			accesories,
			google
		};

		googleProduct.print();

		Product emptyProduct{};

		std::cout << emptyProduct.isCertificated << "\n";
		//std::cout << Product::isCertificated << "\n"; // Compile Error
		std::cout << emptyProduct.isCertificated << "\n"; // Ok

		std::cout << googleProduct.discount << "\n";
		std::cout << emptyProduct.discount << "\n";

		emptyProduct.discount = 123.45;

		std::cout << googleProduct.discount << "\n";
		std::cout << emptyProduct.discount << "\n";

		Product::discount = 200;
		std::cout << Product::discount << "\n";

		Product::changeDiscount(300);
		std::cout << Product::discount << "\n";
		//int x = 123; // sample init
		//int y{ 123 }; // unify init
	}

	std::cout << "===========================================\n\n\n\n\n";




	// Copy Ctor
	{
		std::string accesories[3] =
		{
			"Protected glass",
			"Charger",
			"TypeC",
		};

		Manufacturer google{ "Google" };
		Product googleProduct
		{
			"Google Pixel 8 Pro",
			1000.99,
			3,
			accesories,
			google
		};

		// Copy constructor
		Product copyProduct = googleProduct;
	}
}
