#include <iostream>
#include <string>
#include <vector>
//#include <string.h>
#include <bitset> // дл€ перетворенн€ з 10-чноњ в 2-чну систему
using namespace std;


int main()
{
	{
		// BitsTable
		const int bitsCount = 8;
		std::bitset<bitsCount> bits;

		enum Bits
		{
			ONE = 2,
			TWO = 4,
			THREE = 8,
			FOUR = 16,
			FIVE = 32,
			SIX = 64,
			SEVEN = 128,
			EIGHT = 256,
			NINE = 512,
			TEN = 1024,
			ELEVEN = 2048,
			TWELWE = 4096,
			THIRTEEN = 8192,
			FOURTEEN = 16384,
			FIFTHTEEN = 32768, // INT16_MAX + 1 (тип short)
			// ...
		};


		// 1 - 2, 2 - 4, 3 - 8, 4 - 16, 5 - 32, 6 - 64, 7 - 128, 8 - 256

		short bitsBetweenZeroAndEight = Bits::EIGHT;

		cout << "Numbers that take one bit:\n";
		for (int i = 0, bitsCount = 1; i < bitsBetweenZeroAndEight; i++)
		{
			if (i == Bits::ONE ||
				i == Bits::TWO ||
				i == Bits::THREE ||
				i == Bits::FOUR ||
				i == Bits::FIVE ||
				i == Bits::SIX ||
				i == Bits::SEVEN ||
				i == Bits::EIGHT ||
				i == Bits::NINE ||
				i == Bits::TEN || 
				i == Bits::ELEVEN ||
				i == Bits::TWELWE ||
				i == Bits::THIRTEEN ||
				i == Bits::FOURTEEN ||
				i == Bits::FIFTHTEEN)
			{
				cout << "\nNumbers that take " << ++bitsCount << " bits: " << endl;
			}

			bits = i;
			cout << i << "\t - \t" << bits << endl;
		}

		cout << endl << endl;
	}



	// << >> ~ & | ^
	{
		// << >>
		// 
		// 24 - 00011000 
		// << 1
		// 48 - 00110000

		int x = 24;
		x = x << 1; // 48 - 00110000
		std::cout << x << "\n";

		x = x << 2; // 48 - 11000000
		std::cout << x << "\n"; // 192

		x = x >> 5; // 6 - 00000110
		std::cout << x << "\n"; // 6

		// ~
		x = ~x; // -7
		std::cout << x << "\n"; // 7

		x = ~x; // 6
		std::cout << x << "\n"; // 6



		// & - та
		// 113	- 01110001
		// &
		// 77	- 01001101
		// ==
		// 65	- 01000001

		x = 113;
		int y = 77;
		int result = x & y;
		std::cout << result << "\n";


		// | - або
		// 113	- 01110001
		// |
		// 77	- 01001101
		// ==
		// 125	- 01111101
		result = x | y;
		std::cout << result << "\n";

		// ^ - не та
		// 113	- 01110001
		// ^
		// 77	- 01001101
		// ==
		// 60	- 00111100
		result = x ^ y;
		std::cout << result << "\n";
	}



	{
		// 1-st example
		union Money
		{
			double dMoney;
			char sMoney[30];
		};

		Money money{};
		money.dMoney = 123.12;

		std::cout << money.dMoney << "\n"; // Ok
		std::cout << money.sMoney << "\n"; // 0_o

		strcpy_s(money.sMoney, 29, to_string(money.dMoney).c_str());

		std::cout << money.dMoney << "\n"; // 0_o
		std::cout << money.sMoney << "\n\n\n"; // Ok


		// 2-nd example
		union Example
		{
			short shortVar;
			int intVar;
			long longVar;
			char charVar;
		};

		Example example;
		example.shortVar = 123;
		example.charVar = 124;
		example.longVar = 125;
		example.longVar = INT16_MAX;
		example.longVar = INT16_MAX + 1;

		std::cout << "";


		// 3-rd example
		struct Point3D
		{
			int x;
			int y;
			int z;
		};

		union Point3DPresentation
		{
			Point3D point3D;
			int coordinates[3];
		};

		Point3D point{ 4, 2, 9 };

		Point3DPresentation pointPresentation;
		pointPresentation.point3D = point;

		std::cout << "x: " << pointPresentation.point3D.x
			<< "y: " << pointPresentation.point3D.y
			<< "z: " << pointPresentation.point3D.z
			<< "\n\n";

		for (int& coordinate : pointPresentation.coordinates) 
		{
			std::cout << coordinate << "\n";
		}

		pointPresentation.point3D.y = 123; // coordinates[1] = 123
		pointPresentation.coordinates[2] = 456; // point3D.z = 456

		std::cout << "\n\n\n\n";
	}



	// Bit fields
	{
		// using struct without bit fields
		struct Sprite
		{
			int ccordinateX; // 4 bytes (32 bits)
			int ccordinateY; // 4 bytes (32 bits)
			int ccordinateZ; // 4 bytes (32 bits)
			short color; // 2 bytes (16 bits)
			short timeToLive; // 2 bytes (16 bits)
			bool isVisible; // 1 byte (8 bits)
		}; // 17 bytes

		Sprite sprite{};
		std::cout << sizeof(sprite) << "\n"; // 20 bytes (160 bits)
		std::cout << sizeof(Sprite) << "\n"; // 20 bytes (160 bits)


		// using struct with bit fields
		// x > 0 && x < 255
		// y > 0 && y < 255
		// z > 0 && z < 100
		// color > 0 && color < 32
		// timeToLive == 0 && timeToLive == 1
		// isVisible == 0 && isVisible == 1
		struct SpriteUsingBitFields
		{
			unsigned short ccordinateX : 8; // 8 bit (1 byte)
			unsigned short ccordinateY : 8; // 8 bit (1 byte)
			unsigned short ccordinateZ : 7; // 7 bit (< 1 byte)
			unsigned short color : 5; // 5 bit (< 1 byte)
			unsigned short timeToLive : 1; // 1 bit
			unsigned short isVisible : 1; // 1 bit
		}; // 30 bit (< 4 bytes)

		Sprite spriteUsingBitFields;
		std::cout << sizeof(spriteUsingBitFields) << "\n"; // 20 bytes (160 bits)
		std::cout << sizeof(SpriteUsingBitFields) << "\n\n"; // 8 bytes (64 bits)
	}



	// bitset
	{
		std::bitset<32> bitset;
		std::cout << (std::bitset<32>)64 << "\n\n";
	}
}