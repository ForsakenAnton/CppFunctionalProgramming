//#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
using namespace std;


int getWordCount(char* str) 
{
	return 0;
}

int getWordCount(string str)
{
	return 0;
}


string toLower(string str)
{
	for (int i = 0; i < str.size(); i++)
	{
		str[i] = std::tolower(str[i]);
	}

	return str;
}

int main()
{
	{
		char cStyle[] = "Hello\nWorld";
		std::cout << cStyle << "\n";

		cStyle[1] = 'a';

		char* dynamicCStyle = new char[20] {};
		//dynamicCStyle = "qwerty"; // Compile Error

		const char* myStr = "Hello!";


		std::string cppStyle = "Hello\nWorld";
		std::cout << cppStyle << "\n\n\n\n";
		cppStyle += "!!!";
	}


	// length
	{
		char cStyle[] = "Hello";
		std::cout << sizeof(cStyle) << "\n";
		std::cout << std::strlen(cStyle) << "\n";


		std::string cppStyle = "Hello";
		std::cout << cppStyle.size() << "\n";
		std::cout << cppStyle.length() << "\n";
	}


	// concatenation
	{
		char str1[20] = "Hello";
		const char* str2 = "World";
		strcat_s(str1, str2);
		cout << "str1: " << str1 << endl;
		cout << "str2: " << str2 << endl;
		cout << "Result string str1 after concatenation with str2:" << str1 << endl;


		std::string cppStyle = "Hello";
		std::string cppStyle2 = "World";

		string concatResult = cppStyle + cppStyle2;
	}


	// copy 
	{
		char strDest[50] = "Destination";
		char strSrc[50] = "Source";

		cout << "Destination str: " << strDest << endl;
		cout << "Source str: " << strSrc << endl;

		//strcpy(strDest, strSrc);
		strcpy_s(strDest, strSrc);
		cout << "String strDest is now:" << strDest << endl;


		std::string cppStyle = "Hello";
		std::string cppStyle2 = "World";

		cppStyle = cppStyle2;
		cppStyle = "";
		cppStyle = "qwerty...";
	}


	// compare and std::string toLower (custom toLower)
	{
		const char* str1 = "admin";
		const char* str2 = "Admin";

		if (strcmp(str1, str2) == 0)
		{
			cout << "str1: " << str1 << " = " << "str2: " << str2 << endl;
		}
		else if (_stricmp(str1, str2) == 0)
		{
			cout << "without Case Sensitivity! str1: " << str1 << " = " << "str2: " << str2 << endl;
		}


		std::string cppStyle = "Hello";
		std::string cppStyle2 = "Hello";

		int isCompare = 0;
		isCompare = cppStyle.compare(cppStyle2);

		cppStyle2 = "HELLO";

		isCompare = ::toLower(cppStyle).compare(toLower(cppStyle2));
	}



	// search (by char and string)
	{
		char str[] = "Welcome!";
		char ch = 'c';
		char* result;

		result = strchr(str, ch);
		cout << "String '" << str << "' after first '" << ch << "' is : " << result << endl;
		result = strrchr(str, ch);
		cout << "String '" << str << "' after last '" << ch << "' is : " << result << endl;

		char subStr[] = "lc";
		auto res = strstr(str, subStr);
		cout << res << "\n\n";



		string cppStyle = "I learn C++ programming";

		auto index = cppStyle.find("a");
		index = cppStyle.find("a", index + 1);
		index = cppStyle.find("a", index + 1);
		if (index == string::npos)
		{
			cout << "npos\n";
		}

		index = 0;
		for (
			index = cppStyle.find("a");
			index != string::npos;
			index = cppStyle.find("a", index + 1))
		{
			cout << index << "\n";
		}
	}



	// toLower toUpper for char[]
	{
		{
			char str1[] = "Hello";
			char str2[] = "Admin";
			char ch = '*';

			_strlwr_s(str1);
			cout << "String in lowercase:" << str1 << endl;
			_strupr_s(str2);
			cout << "String in uppercase:" << str2 << endl;
		}
	}


	// fgets, puts (C-style)
	{
		//char fullName[25];
		//cout << "Input your full name: ";
		////cin >> fullName;
		//fgets(fullName, sizeof(fullName), stdin);
		//cout << "Welcome, " << fullName << endl;

		int x;
		cout << "Enter the X: ";
		cin >> x;
		cin.ignore(INT16_MAX, '\n');

		string cppStyle;
		//cin >> cppStyle;
		cout << "Enter the cppStyle string: ";
		std::getline(cin, cppStyle);
		cout << "Welcome, " << cppStyle << endl;
	}



	{
		cout << std::isdigit('1') << "\n";
		cout << std::isdigit('a') << "\n";
		cout << std::isalpha('1') << "\n";
		cout << std::isalpha('a') << "\n";
	}
}

//char cStyle[] = "Hello";
//std::string cppStyle = "Hello";
