// Detailed inheritance and notes:
//
// - Typedefs (char specialization):
//   using std::ifstream = std::basic_ifstream<char, std::char_traits<char>>;
//   using std::ofstream = std::basic_ofstream<char, std::char_traits<char>>;
//   using std::fstream  = std::basic_fstream<char,  std::char_traits<char>>;
//
// - Simplified inheritance hierarchy (template forms, simplified):
//
//   std::basic_ios<CharT,Traits> : public std::ios_base
//     - basic_ios provides the common stream state & locale support.
//     - It is typically the common base for istream/ostream via virtual inheritance.
//
//   std::basic_istream<CharT,Traits> : virtual public std::basic_ios<CharT,Traits>
//     - Provides input operations (operator>>, getline, read, etc.).
//
//   std::basic_ostream<CharT,Traits> : virtual public std::basic_ios<CharT,Traits>
//     - Provides output operations (operator<<, write, flush, etc.).
//
//   std::basic_iostream<CharT,Traits> : public std::basic_istream<CharT,Traits>, public std::basic_ostream<CharT,Traits>
//     - Combines both input and output capabilities.
//
//   std::basic_ifstream<CharT,Traits> : public std::basic_istream<CharT,Traits>
//     - Implements input file stream. Internally it typically contains a
//       std::basic_filebuf<CharT,Traits> (member) that manages the file buffer.
//     - Note: basic_ifstream does NOT inherit from basic_filebuf; it uses it.
//
//   std::basic_ofstream<CharT,Traits> : public std::basic_ostream<CharT,Traits>
//     - Implements output file stream. Also contains a basic_filebuf as a member.
//
//   std::basic_fstream<CharT,Traits> : public std::basic_iostream<CharT,Traits>
//     - Implements input/output file stream. Contains a basic_filebuf as a member.
//
// - Compact example for char specializations:
//
//   std::ios_base
//     ^
//     | (public)
//   std::basic_ios<char, Traits>
//     ^
//     | (virtual public)
//   +---------------------------+
//   |                           |
//   v                           v
// std::basic_istream<char,Traits>   std::basic_ostream<char,Traits>
//     ^                                 ^
//     |                                 |
//     +------------+--------------------+
//                  |
//                  v
//           std::basic_iostream<char,Traits>
//
// Then file stream types:
//   std::basic_ifstream<char,Traits>  : public std::basic_istream<char,Traits>
//   std::basic_ofstream<char,Traits>  : public std::basic_ostream<char,Traits>
//   std::basic_fstream<char,Traits>   : public std::basic_iostream<char,Traits>
//
// - Important note:
//   basic_filebuf<CharT,Traits> is the file buffer class used by the file
//   stream classes; it is typically held as a member inside basic_ifstream,
//   basic_ofstream, and basic_fstream, not inherited from.
//
// Original/remaining code:


#include <iostream>
#include <fstream>
#include <format>
#include <string>

const std::string fileName = "Data.txt";

void write()
{
    std::ofstream ofs;
    ofs.open(fileName, std::ios::out/* | std::ios::app*/);

    if (!ofs.is_open())
    {
        throw std::invalid_argument(std::format("{} cannot open to write", fileName).c_str());
    }

	std::cout << "ofstream width: " << ofs.width() << "\n";

	ofs << "First Row\n";
	ofs << 123 << "\n";
	ofs << "Second Row\n";

	std::cout << "ofstream width: " << ofs.width() << "\n";

	ofs.close();
}

void read()
{
	std::ifstream ifs;
	ifs.open(fileName, std::ios::in);

	if (!ifs.is_open())
	{
		throw std::invalid_argument(std::format("{} cannot open to read", fileName).c_str());
	}

	char first = (char)ifs.get(); // F
	char second = (char)ifs.get(); // i
	std::cout << first << " - " << second << "\n";

	ifs.seekg(2, std::ios::cur);
	char tSymbol = (char)ifs.get(); // t
	std::cout << tSymbol << "\n";

	ifs.seekg(0, std::ios::beg);

	while (ifs.peek() != -1)
	{
		std::string firstRow;
		int number;
		std::string thirdRow;

		std::getline(ifs, firstRow);

		std::string numberAsString;
		std::getline(ifs, numberAsString);
		number = std::stoi(numberAsString);

		std::getline(ifs, thirdRow);
	}

	ifs.close();
}

void usingFstream()
{
	std::fstream fs(fileName, std::ios::in | std::ios::out /*| std::ios::app*/);

	if (!fs.is_open())
	{
		throw std::invalid_argument(std::format("{} cannot open to read and write", fileName).c_str());
	}

	while (fs.peek() != -1)
	{
		char symbol = (char)fs.get();

		if (symbol == ' ')
		{
			symbol = '_';

			fs.seekg(-1, std::ios::cur);
			fs << symbol;
			fs.seekg(fs.tellg(), std::ios::beg);
		}
	}

	fs.close();
}

int main()
{
	try
	{
		write();
		//read();

		usingFstream();
	}
	catch (const std::exception& ex)
	{
		std::cout << ex.what() << "\n";
	}
}
