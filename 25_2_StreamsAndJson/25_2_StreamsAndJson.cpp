#include <iostream>
#include <fstream>
#include <string>
#include <nlohmann/json.hpp>

using namespace std;
using json = nlohmann::json;

namespace deviceNS
{
	struct Company
	{
		string name;
	};

	struct Device
	{
		std::string name;
		float price;
		std::vector<string> accessories;

		Company company;

		friend ostream& operator << (ostream& out, const Device& device)
		{
			out << device.name << endl;
			out << device.price << endl;
			out << device.company.name << endl;

			out << "Accesories: ";
			for (auto accesory : device.accessories)
			{
				out << accesory << " | ";
			}
			out << endl << endl;

			return out;
		}
	};

	void to_json(json& j, const Device& d)
	{
		j = json
		{
			{"name", d.name},
			{"price", d.price},
			{"accessories", d.accessories},
			{"company", {
				{"name", d.company.name}
			  }
			},
		};

		//j["name"] = "New Name";
		//j.at("name") = "New Name 2";
	}

	void from_json(const json& j, Device& d)
	{
		j.at("name").get_to(d.name);
		j.at("price").get_to(d.price);
		j.at("accessories").get_to(d.accessories);
		//j.at("company").get_to(d); // error

		// 1 variant
		j.at("company").at("name").get_to(d.company.name);

		//// 2 variant
		//json companyJson = j.at("company");
		//companyJson.at("name").get_to(d.company.name);
	}
}

template<typename Stream>
void checkIfIFStreamOpen(Stream& fs)
{
	if (!fs.is_open())
	{
		throw exception{ "Cannot open the file...\n\n" };
	}
}

void loadData(json& jDevices, std::vector<deviceNS::Device>& devices, const string& fileName)
{
	ifstream ifs(fileName, std::ios::in);
	::checkIfIFStreamOpen(ifs);

	//jDevices = json::parse(ifs);
	if (ifs.peek() == -1)
	{
		return;
	}
	ifs >> jDevices;

	//cout << setw(4) << jDevices << endl;

	//for (int i = 0; i < jDevices.size(); i++)
	//{
	//	devices.push_back(jDevices[i].template get<deviceNS::Device>());
	//}

	devices = jDevices;
}

void printDevices(const std::vector<deviceNS::Device>& devices)
{
	for (auto& item : devices)
	{
		cout << item;
	}
	cout << "\n\n";
}

void printJson(const json& jDevices)
{
	cout << setw(2) << jDevices << endl << endl;
}

void inputDeviceData(deviceNS::Device& deviceToAdd)
{
	cout << "Enter the name of device: ";
	cin.ignore(32767, '\n');
	std::getline(cin, deviceToAdd.name);

	cout << "Enter the price: ";
	cin >> deviceToAdd.price;

	cout << "Enter the accesories. To exit put 0:\n";
	cin.ignore(32767, '\n');
	while (true)
	{
		string accesory;
		std::getline(cin, accesory);

		if (accesory == "0")
		{
			break;
		}

		deviceToAdd.accessories.push_back(accesory);
	}

	cout << "Enter the name of device's company: ";
	std::getline(cin, deviceToAdd.company.name);
}


void addDevice(json& jDevices, std::vector<deviceNS::Device>& devices, const string& fileName)
{
	deviceNS::Device deviceToAdd;
	::inputDeviceData(deviceToAdd);

	jDevices.push_back(deviceToAdd);
	devices.push_back(deviceToAdd);

	ofstream ofs(fileName, std::ios::out);
	::checkIfIFStreamOpen(ofs);

	ofs << setw(4) << jDevices << endl;
	ofs.close();

	cout << "The device was created and added successfully\n\n";
}

void addDeviceByIndex(json& jDevices, std::vector<deviceNS::Device>& devices, const string& fileName)
{
	cout << "There are " << devices.size() << " elements.\n";
	cout << "Enter the programmer's style index aka (size() == 1, index == 0): ";
	int index;
	cin >> index;

	if (index < 0 || index >= devices.size())
	{
		throw exception("Index is out of range\n\n");
	}

	cout << "Now you will add the device.\n";
	deviceNS::Device deviceToAdd;
	::inputDeviceData(deviceToAdd);

	auto jIt = jDevices.begin();
	std::advance(jIt, index);
	jDevices.insert(jIt, deviceToAdd);

	auto dIt = devices.begin();
	std::advance(dIt, index);
	devices.insert(dIt, deviceToAdd);

	ofstream ofs(fileName, std::ios::out);
	::checkIfIFStreamOpen(ofs);

	ofs << setw(4) << jDevices << endl;
	ofs.close();
}

void editDevice(json& jDevices, std::vector<deviceNS::Device>& devices, const string& fileName)
{
	cout << "There are " << devices.size() << " elements.\n";
	cout << "Enter the programmer's style index aka (size() == 1, index == 0): ";
	int index;
	cin >> index;

	if (index < 0 || index >= devices.size())
	{
		throw exception("Index is out of range\n\n");
	}

	cout << "Now you will edit the device.\n";
	deviceNS::Device deviceToEdit = jDevices[index];
	deviceToEdit.accessories.clear();
	::inputDeviceData(deviceToEdit);

	auto jIt = jDevices.begin();
	std::advance(jIt, index);
	*jIt = deviceToEdit;

	auto dIt = devices.begin();
	std::advance(dIt, index);
	*dIt = deviceToEdit;

	ofstream ofs(fileName, std::ios::out);
	::checkIfIFStreamOpen(ofs);

	ofs << setw(4) << jDevices << endl;
	ofs.close();
}

void deleteDevice(json& jDevices, std::vector<deviceNS::Device>& devices, const string& fileName)
{
	cout << "There are " << devices.size() << " elements.\n";
	cout << "Enter the programmer's style index aka (size() == 1, index == 0): ";
	int index;
	cin >> index;

	if (index < 0 || index >= devices.size())
	{
		throw exception("Index is out of range\n\n");
	}

	cout << "Now you will delete the device.\n";
	deviceNS::Device deviceToDelete = jDevices[index];

	auto jIt = jDevices.begin();
	std::advance(jIt, index);
	jDevices.erase(jIt);


	auto dIt = devices.begin();
	std::advance(dIt, index);
	devices.erase(dIt);

	if (jDevices.size() == 0)
	{
		return;
	}

	ofstream ofs(fileName, std::ios::out);
	::checkIfIFStreamOpen(ofs);

	ofs << setw(4) << jDevices << endl;
	ofs.close();
}

void searchDeviceByNameWithJson(json& jDevices)
{
	string search;
	cout << "Enter the name: ";
	cin.ignore(32767, '\n');
	std::getline(cin, search);

	for (auto el : jDevices)
	{
		string value;
		el.at("name").get_to(value);

		size_t isFound = value.find(search);
		if (isFound != -1)
		{
			deviceNS::Device foundDevice = el;
			cout << foundDevice << endl;
		}
	}
}


int main()
{
	//// Examples
	//try
	//{
	//	deviceNS::Device device
	//	{
	//		"Google Pixel 8",
	//		100500.99,
	//		{ "charger", "protective glass", "stylus" },
	//		deviceNS::Company{ "Google" }
	//	};

	//	//Serialize
	//	json jDevice = device; // { ... } // As first non-explicit operation jDevice is object
	//	//jDevice.push_back(device); // Error after operation = below. It is not array, it is object
	//	cout << setw(4) << jDevice << endl << endl;

	//	json jDevices;
	//	jDevices.push_back(device); // [ { ... }, { ... }, ... ] // As first non-explicit operation jDevice is array
	//	jDevices.push_back(device); // Ok. It is already array
	//	//jDevices = device; // Ok. Non-explicit convertion to object. Lost previous data

	//	cout << setw(4) << jDevices << endl << endl;


	//	// For example, about objects and arrays, you can do it as explicit
	//	json jArr = json::array();
	//	json jObj = json::object();

	//	if (jArr.is_array())
	//	{
	//		jArr.push_back(device);
	//		jArr.push_back(device);
	//		jArr.push_back(device);
	//	}

	//	if (jObj.is_object())
	//	{
	//		jObj = device;
	//	}


	//	// Deserialize Object
	//	deviceNS::Device deserializedObject;
	//	//deserializedObject = jObj.template get<deviceNS::Device>(); // Ok
	//	deserializedObject = jObj; // Ok
	//	cout << deserializedObject << endl;


	//	// Deserialize Array
	//	std::vector<deviceNS::Device> deserializedArray;
	//	//// 1 variant for array
	//	//for (auto el : jArr.items())
	//	//{
	//	//	//deserializedArray.push_back(el.value().template get<deviceNS::Device>()); // Ok
	//	//	deserializedArray.push_back(el.value()); // Ok
	//	//}

	//	//// 2 variant
	//	//for (int i = 0; i < jArr.size(); i++)
	//	//{
	//	//	deserializedArray.push_back(jArr[i]/*.template get<deviceNS::Device>()*/);
	//	//}

	//	// 3 variant
	//	deserializedArray = jArr;



	//	// json pointer test
	//	auto j_flat = jObj.flatten();
	//	cout << setw(4) << j_flat << endl;

	//	auto jProperty = jObj["/name"_json_pointer];
	//	auto jValue = jObj["/accessories"_json_pointer];
	//	vector<string> accessories = jValue;

	//	auto jPrice = jObj["/price"_json_pointer];
	//	float price = jPrice;//.template get<float>();


	//	// iterators
	//	json j;
	//	j["one"] = 1;
	//	j["two"] = 2;
	//	j["three"] = 3;

	//	for (auto it = j.begin(); it != j.end(); ++it)
	//	{
	//		std::cout << *it << std::endl;
	//	}
	//}
	//catch (const std::exception& ex)
	//{
	//	cout << ex.what() << endl;
	//}
	//// End of Examples





	try
	{
		json jDevices;
		std::vector<deviceNS::Device> devices;
		const string fileName = "Devices.json";

		ofstream createFile(fileName, ios::out | ios::app);
		createFile.close();


		::loadData(jDevices, devices, fileName);

		int action;

		do
		{
			cout << "Menu:\n";
			cout << "1. Print all devices\n";
			cout << "2. Print all devices as json\n";
			cout << "3. Search device by name\n";
			cout << "4. Add a device\n";
			cout << "5. Add a device and insert by index:\n";
			cout << "6. Update a device\n";
			cout << "7. Remove device by name\n";
			cout << "0. Exit\n\n";

			cin >> action;

			switch (action)
			{
			case 1:
				::printDevices(devices);
				break;


			case 2:
				::printJson(jDevices);
				break;


			case 3:
				::searchDeviceByNameWithJson(jDevices);
				break;


			case 4:
				::addDevice(jDevices, devices, fileName);
				break;


			case 5:
				::addDeviceByIndex(jDevices, devices, fileName);
				break;


			case 6:
				::editDevice(jDevices, devices, fileName);
				break;


			case 7:
				::deleteDevice(jDevices, devices, fileName);
				break;


			case 0:
				// To do...
				break;


			default:
				cout << "Invalid operation\n\n";
				break;
			}
		} while (action != 0);

	}
	catch (const std::exception& ex)
	{
		cout << ex.what() << endl;
	}
}












//#include <iostream>
//#include <fstream>
//#include <string>
//#include <nlohmann/json.hpp>
//
//using namespace std;
//using json = nlohmann::json;
//
//namespace ns 
//{
//    // a simple struct to model a person
//    struct person 
//    {
//        std::string name;
//        std::string address;
//        int age;
//    };
//
//    // Нижче 2 методи обов'яэкові для запису типу: json j = oblect/arrayOfObjects;
//    // Вони спрацьовують неявно, тому викликати їх не треба.
//    void to_json(json& j, const person& p)
//    {
//        j = json 
//        { 
//            {"name", p.name},
//            {"address", p.address},
//            {"age", p.age}
//        };
//    }
//
//    void from_json(const json& j, person& p) 
//    {
//        j.at("name").get_to(p.name);
//        j.at("address").get_to(p.address);
//        j.at("age").get_to(p.age);
//    }
//} // namespace ns
//
//int main()
//{
//    // create a person
//    ns::person p{ "Ned Flanders", "744 Evergreen Terrace", 60 };
//    ns::person p2{ "Ned Flanders2", "744 Evergreen Terrace2", 602 };
//
//    ns::person pArr[2]{ p, p2 };
//
//    json j; //= pArr; Теж працює
//    j.push_back(pArr[0]);
//    cout << setw(4) << j << endl << endl;
//
//    j.push_back(pArr[1]);
//    cout << setw(4) << j << endl << endl;
//
//    //[
//        //{
//        //    "address": "744 Evergreen Terrace",
//        //    "age" : 60,
//        //    "name" : "Ned Flanders"
//        //},
//        //{
//        //    "address": "744 Evergreen Terrace2",
//        //    "age" : 602,
//        //    "name" : "Ned Flanders2"
//        //}
//    //]
//
//    // conversion: json -> person
//    ns::person pNewArr[2]{ };
//    pNewArr[0] = j[0].template get<ns::person>();
//    pNewArr[1] = j[1].template get<ns::person>();
//
//    for (auto& p : pNewArr)
//    {
//        cout << p.name << "; " << p.age << ", " << p.address << endl;
//    }
//    // that's it
//
//    //ns::person p{ "Ned Flanders", "744 Evergreen Terrace", 60 };
//
//    //// convert to JSON: copy each value into the JSON object
//    //json j;
//    //j["name"] = p.name;
//    //j["address"] = p.address;
//    //j["age"] = p.age;
//
//    //// ...
//
//    //// convert from JSON: copy each value from the JSON object
//    //ns::person p2{
//    //    j["name"].template get<std::string>(),
//    //    j["address"].template get<std::string>(),
//    //    j["age"].template get<int>()
//    //};
//}
//
