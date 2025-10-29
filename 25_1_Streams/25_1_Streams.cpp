
#include <iostream>
#include <vector>
#include <list>
#include <chrono>
#include <fstream>
#include <string>

using namespace std;

struct Company
{
	string name;
};

struct Device
{
	string name;
	float price = 0;
	//std::vector<string> accesories;
	Company company;

	friend ostream& operator<<(ostream& out, const Device& device)
	{
		out << device.name << endl;
		out << device.price << endl;
		out << device.company.name << endl << endl;

		return out;
	}

	friend ofstream& operator<<(ofstream& ofs, const Device& device)
	{
		ofs << device.name << endl;
		ofs << device.price << endl;
		ofs << device.company.name << endl;

		return ofs;
	}

	friend ifstream& operator>>(ifstream& ifs, Device& device)
	{
		std::getline(ifs, device.name);

		string price;
		std::getline(ifs, price);
		device.price = stof(price);

		std::getline(ifs, device.company.name);

		return ifs;
	}
};

template<typename Container, typename T>
class IRepositoryBase abstract
{
public:
	virtual void print() const = 0;

	virtual Container getItems() = 0;
	virtual T getItem(int index) = 0;

	virtual void add(const T& item) = 0;
	virtual void edit(const T& item, int index) = 0;
	virtual void remove(int index) = 0;

	virtual ~IRepositoryBase() = 0;
};

template<typename Container, typename T>
IRepositoryBase<Container, T>::~IRepositoryBase()
{
}

template<typename Container, typename T>
class RepositoryListVectorBase : IRepositoryBase<Container, T>
{
protected:
	Container data;

	// /////////////////
	//std::vector<T> v;
	//std::list<T> l;
	// /////////////////

private:
	void checkRange(int index)
	{
		if (index < 0 || index > data.size())
		{
			throw exception{ "Index is out of range!\n" };
		}
	}

public:
	void print() const
	{
		for (const T& item : data)
		{
			cout << item;
		}
		cout << "\n\n";
	}

	Container getItems()
	{
		return data;
	}

	T getItem(int index) // індекс програмістський
	{
		this->checkRange(index);

		if constexpr (std::is_same_v<Container, vector<T>>)
		{
			return data[index];
		}

		auto it = data.begin();
		std::advance(it, index);

		return *it;
	}

	void add(const T& item)
	{
		data.push_back(item);
		//auto it = data.begin();
		//data.insert(it, item);
	}

	void edit(const T& item, int index)
	{
		this->checkRange(index);

		if constexpr (std::is_same_v<Container, vector<T>>)
		{
			data[index] = item;
			return;
		}

		auto it = data.begin();
		std::advance(it, index);
		*it = item;
	}

	void remove(int index)
	{
		this->checkRange(index);

		auto it = data.begin();
		std::advance(it, index);
		data.erase(it);
	}

	~RepositoryListVectorBase() override
	{

	}
};

template<typename Container, typename T>
class RepositoryFStreamBase : public RepositoryListVectorBase<Container, T>
{
private:
	string fileName;
	std::ifstream ifs;
	std::ofstream ofs;

	template<typename Stream>
	void checkIfFileOpen(const Stream& stream)
	{
		if (!stream.is_open())
		{
			throw exception("File cannot be open 0_o...\n\n");
		}
	}

	void loadData()
	{
		ifs.open(fileName, std::ios::in);
		this->checkIfFileOpen(ifs);

		while (ifs.peek() != -1)
		{
			T item;
			ifs >> item;

			RepositoryListVectorBase<Container, T>::add(item);
		}

		ifs.close();
	}

public:
	RepositoryFStreamBase(const string& fileName)
		: fileName{ fileName }
	{
		this->loadData();
	}

	void add(const T& item) override
	{
		ofs.open(fileName, std::ios::out | std::ios::app);
		this->checkIfFileOpen(ofs);

		ofs << item;
		ofs.close();

		RepositoryListVectorBase<Container, T>::add(item);
	}

	void edit(const T& item, int index) override
	{
		//RepositoryListVectorBase<Container, T>::checkRange(index);
		RepositoryListVectorBase<Container, T>::edit(item, index);

		ofs.open(fileName, std::ios::out | std::ios::trunc);
		this->checkIfFileOpen(ofs);

		for (const T& item : RepositoryListVectorBase<Container, T>::data)
		{
			ofs << item;
		}

		ofs.close();
	}

	void remove(int index) override
	{
		//RepositoryListVectorBase<Container, T>::checkRange(index);
		RepositoryListVectorBase<Container, T>::remove(index);

		ofs.open(fileName, std::ios::out | std::ios::trunc);
		this->checkIfFileOpen(ofs);

		for (const T& item : RepositoryListVectorBase<Container, T>::data)
		{
			ofs << item;
		}

		ofs.close();
	}


	void testRenameAndRemoveFile()
	{
		ifs.open(fileName, std::ios::in);
		ofstream tempOfs("temp.txt", std::ios::out);

		while (ifs.peek() != -1)
		{
			string line;
			std::getline(ifs, line);


			// if condition
			tempOfs << line << endl;
		}

		ifs.close();
		tempOfs.close();

		std::remove(fileName.c_str()); // видаляємо старий файл
		int removedResult = std::rename("temp.txt", fileName.c_str()); // перейменовуємо до старого імені

		if (removedResult == 0)
		{
			cout << "Removing and renaming was successfully\n\n";
		}
	}
};
// /////////////////////////////////////////////////////////////////////



Device inputDataDevice()
{
	Device device;

	cin.ignore(32767, '\n');
	cout << "Put name:";
	std::getline(cin, device.name);

	cout << "Put Price:";
	cin >> device.price;

	cin.ignore(32767, '\n');
	cout << "Put company name:";
	std::getline(cin, device.company.name);

	return device;
}

void runDeviceClient()
{
	string fileName = "Device.txt";
	RepositoryFStreamBase<vector<Device>, Device> repoFSB{ fileName };

	int action;

	do
	{
		cout << "1. Print\n";
		cout << "2. Add\n";
		cout << "3. Edit\n";
		cout << "4. Remove\n";
		cout << "5. Test Remove and Rename the File.txt\n";
		cout << "0. Exit\n";

		cin >> action;

		switch (action)
		{
		case 1:
			repoFSB.print();
			break;

		case 2:
			repoFSB.add(::inputDataDevice());
			break;

		case 3:
		{
			cout << "Enter the index what you want to change: ";
			int index;
			cin >> index;

			Device device = ::inputDataDevice(); // repoFSB.getItem(index);

			repoFSB.edit(device, index);
			break;
		}

		case 4:
			cout << "Enter the index what you want to remove: ";
			int index;
			cin >> index;

			repoFSB.remove(index);
			break;

		case 5:
			repoFSB.testRenameAndRemoveFile();
			break;

		default:
			cout << "Incorrect operation\n\n";
			break;
		}

	} while (true);
}

int main()
{
	try
	{
		::runDeviceClient();
	}
	catch (const std::exception& ex)
	{
		cout << ex.what() << endl;
	}
}


//int main()
//{
//	try
//	{
//		{
//			auto startTime = std::chrono::high_resolution_clock::now();
//
//			RepositoryListVectorBase<std::vector<int>, int> repo;
//
//			for (int i = 0; i < 100000; i++)
//			{
//				repo.add(i);
//			}
//
//			//repo.add(1);
//			//repo.add(2);
//			//repo.add(3);
//			//repo.add(4);
//			//repo.add(5);
//			//repo.print();
//
//			auto v = repo.getItems();
//			//for (auto& item : v)
//			//{
//			//	cout << item << " ";
//			//}
//			//cout << "\n\n";
//
//			auto el = repo.getItem(3);
//			//cout << el << "\n\n";
//
//			repo.edit(6, 2);
//			repo.remove(3);
//			//repo.print();
//
//			auto endTime = std::chrono::high_resolution_clock::now();
//
//			auto duration = std::chrono::duration_cast<std::chrono::microseconds>(endTime - startTime);
//			cout << "Execution time: " << duration.count() << " microseconds" << endl;
//
//			cout << "\n================================\n\n";
//		}
//
//		{
//			auto startTime = std::chrono::high_resolution_clock::now();
//
//			RepositoryListVectorBase<std::list<int>, int> repo;
//
//			for (int i = 0; i < 100000; i++)
//			{
//				repo.add(i);
//			}
//
//			//repo.add(1);
//			//repo.add(2);
//			//repo.add(3);
//			//repo.add(4);
//			//repo.add(5);
//			//repo.print();
//
//			auto v = repo.getItems();
//			//for (auto& item : v)
//			//{
//			//	cout << item << " ";
//			//}
//			//cout << "\n\n";
//
//			auto el = repo.getItem(3);
//			//cout << el << "\n\n";
//
//			repo.edit(6, 2);
//			repo.remove(3);
//			//repo.print();
//
//			auto endTime = std::chrono::high_resolution_clock::now();
//
//			auto duration = std::chrono::duration_cast<std::chrono::microseconds>(endTime - startTime);
//			cout << "Execution time: " << duration.count() << " microseconds" << endl;
//
//			cout << "\n================================\n\n";
//		}
//	}
//	catch (const std::exception& ex)
//	{
//		cout << ex.what() << endl;
//	}
//}
