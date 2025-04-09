#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main()
{
	//cout << x << "\n";
	//int x = 10;

	//{
	//	int x = 20;
	//	cout << x << "\n";
	//}

	//cout << x << "\n";


	// Features
	{
		int x = 11;
		int y = 3;
		double result = x / y;
		cout << result << "\n";

		result = (double)x / y;
		cout << result << "\n";


		result = std::ceil((double)x / y); // округлення до більшого 
		cout << result << "\n";
		result = std::floor((double)x / y); // округлення до меншого
		cout << result << "\n";
		result = std::round((double)7 / 3); // 2 // округлення до більшого/меншого
		cout << result << "\n";
		result = std::round((double)8 / 3); // 3 // округлення до більшого/меншого
		cout << result << "\n";

		result = (double)x / y; // C style
		cout << result << "\n";

		result = static_cast<double>(x) / y; // C++ style
		cout << result << "\n";

		cout << std::fixed << std::setprecision(1) << result << "\n";
		cout << std::fixed << std::setprecision(2) << result << "\n";
		cout << std::fixed << std::setprecision(3) << result << "\n";
		cout << std::fixed << std::setprecision(4) << result << "\n";
		cout << std::fixed << std::setprecision(5) << result << "\n";
	}

	// Type conversions
	{
		float price = 100.99;
		double discount = 10.99F;

		price = 100;
		price = 'A';
		char symbol = 65.123;

		bool isOpen = true;
		price = isOpen;
		discount = isOpen;
		symbol = isOpen;

		std::string str = "123";
		//price = str; // Compile conversation Error
		price = stoi(str); // Ok, but if the str is a number

		//str = "qwerty";
		//price = stoi(str); // Not Ok, str is not a number.

		cout << "";
	}

	// if/else and conditional oparators
	{
		int count = 50;

		if (count > 0)
		{
			cout << "Enough of products\n";
			cout << "Enough of products\n";
			cout << "Enough of products\n";
			cout << "Enough of products\n";
		}
		else if (count == 50)
		{
			cout << "There is 50 items exactly!\n";
		}
		else
		{
			cout << "Is not enough\n";
		}

		cout << "\n\n";

		int totalPrice = 1000;
		int productCount = 0;

		if (productCount != 0 && totalPrice / productCount != 10)
		{
			cout << "Some actions...\n";
		}

		if (!(productCount != 0))
		{
			cout << "Some actions...\n";
		}


		bool toggle = false;

		if (toggle)
		{
			cout << "Toggle On\n";
		}

		//toggle = true;
		toggle = !toggle;

		if (toggle)
		{
			cout << "Toggle On\n";
		}

		if (!toggle)
		{
			cout << "Toggle Off\n";
		}
	}


	// switch
	{
		char operation;
		cout << "Choose the operation:\n";
		cout << "1. Play the music\n";
		cout << "2. Stop the music\n";
		cout << "3. Paused\n";

		cin >> operation;

		const char firstOp = '1';

		switch (operation)
		{
		case firstOp:
		case 'P':
		case 'p':
			cout << "Info:\n";
			cout << "The music is playing\n";
			break;
		case '2':
		case 'S':
		case 's':
			cout << "Info:\n";
			cout << "The music is stopped\n";
			break;
		case '3':
			cout << "Info:\n";
			cout << "The music is on paused\n";
			break;

		default:
			cout << "Incorrect operation... 0_o\n";
			break;
		}

		cout << "The end\n\n";


		//float price = 100.12;
		//switch (price) // compile error
		//{
		//default:
		//	break;
		//}

		//std::string text = "qwerty";
		//switch (text) // compile error
		//{
		//default:
		//	break;
		//}
	}



	// enum
	{
		enum Operations
		{
			Play = 1,
			Stop,
			Paused,
			PowerOff = 0
		};

		Operations op = Operations::Play;
		//cout << op << endl;
		op = (Operations)123; // weird code

		if (op == Operations::PowerOff)
		{
			cout << "power is off\n";
		}



		int operation = 2;

		switch (operation)
		{
		case Operations::Play:
			cout << "Info:\n";
			cout << "The music is playing\n";
			break;
		case Operations::Stop:

			cout << "Info:\n";
			cout << "The music is stopped\n";
			break;
		case Operations::Paused:
			cout << "Info:\n";
			cout << "The music is on paused\n";
			break;
		case Operations::PowerOff:
			cout << "Info:\n";
			cout << "The power is off\n";
			break;

		default:
			cout << "Incorrect operation... 0_o\n";
			break;
		}

		cout << "The end\n\n";
	}
}
