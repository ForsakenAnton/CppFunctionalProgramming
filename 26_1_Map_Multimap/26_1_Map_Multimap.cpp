
#include <iostream>
#include <map>
#include <set>
#include <unordered_set>

void initMap(std::map<int, std::string>& m)
{
	m.insert(std::make_pair(380, "Ukraine"));
	m.insert(std::make_pair(90, "Turkey"));
	m.insert(std::make_pair(886, "Taiwan"));
	m.insert(std::make_pair(34, "Spain"));
	m.insert(std::make_pair(371, "Latvia"));
	m.insert(std::pair<int, std::string>(1, "USA"));
	m[44] = "UK";

	// not works below - duplicate keys are ignored
	m.insert(std::make_pair(380, "Ukraine 2")); // ignore
	m.insert(std::pair<int, std::string>(380, "Ukraine 3")); // ignore
	m[380] = "Ukraine"; // add or updates existing key (update in this case)
}

void initMultiMap(std::multimap<int, std::string>& m)
{
	m.insert(std::make_pair(380, "Ukraine"));
	m.insert(std::make_pair(90, "Turkey"));
	m.insert(std::make_pair(886, "Taiwan"));
	m.insert(std::make_pair(100500, "Unknown Country"));
	m.insert(std::make_pair(34, "Spain"));
	m.insert(std::make_pair(371, "Latvia"));
	m.insert(std::pair<int, std::string>(1, "USA"));
	//m[44] = "UK"; // Compiler error - multimap doesn't support operator[]

	// not works below - duplicate keys are ignored
	m.insert(std::make_pair(380, "Ukraine 2"));
	m.insert(std::pair<int, std::string>(380, "Ukraine 3"));
	//m[380] = "Ukraine"; // Compiler error - multimap doesn't support operator[]
}

void showMap(const std::map<int, std::string>& m)
{
	std::cout << "Map contents:\n";
	for (const auto& pair : m)
	{
		std::cout << pair.first << " : " << pair.second << "\n";
	}

	//for (auto it = m.begin(); it != m.end(); ++it)
	//{
	//	std::cout << it->first << " : " << it->second << "\n";
	//}

	std::cout << "\n\n";
}

void showMultiMap(const std::multimap<int, std::string>& m)
{
	std::cout << "Map contents:\n";
	for (const auto& pair : m)
	{
		std::cout << pair.first << " : " << pair.second << "\n";
	}

	//for (auto it = m.begin(); it != m.end(); ++it)
	//{
	//	std::cout << it->first << " : " << it->second << "\n";
	//}

	std::cout << "\n\n";
}

void findElementMap(const std::map<int, std::string>& m, int key)
{
	auto elByKey = m.find(key);
	if (elByKey != m.end())
	{
		std::cout << "Element with key " << key << " found: " << elByKey->second << "\n";
	}
	else
	{
		std::cout << "Element with key " << key << " not found\n";
	}
}

void findElementMultiMap(const std::multimap<int, std::string>& m, int key)
{
	auto elByKey = m.find(key);
	if (elByKey != m.end())
	{
		std::cout << "Element with key " << key << " found: " << elByKey->second << "\n";
	}
	else
	{
		std::cout << "Element with key " << key << " not found\n";
	}
}

void atMap(const std::map<int, std::string>& m, int key)
{
	try
	{
		std::string value = m.at(key);
		std::cout << "Element with key " << key << " found: " << value << "\n";
	}
	catch (const std::out_of_range& e)
	{
		std::cout << "Element with key " << key << " not found\n";
	}
}

void lowerBound_upperBoundMap_Example(const std::map<int, std::string> m)
{
	// lower_bound (>=)
	{
		auto lower1 = m.lower_bound(380); // first element not less than key
		auto lower2 = m.lower_bound(1);
		auto lower3 = m.lower_bound(30);
		auto lower4 = m.lower_bound(12345);
		auto lower5 = m.lower_bound(-123);
		std::cout << "Lower 1: " << (lower1 != m.end() ? lower1->second : "end") << "\n";
		std::cout << "Lower 2: " << (lower2 != m.end() ? lower2->second : "end") << "\n";
		std::cout << "Lower 3: " << (lower3 != m.end() ? lower3->second : "end") << "\n";
		std::cout << "Lower 4: " << (lower4 != m.end() ? lower4->second : "end") << "\n";
		std::cout << "Lower 5: " << (lower5 != m.end() ? lower5->second : "end") << "\n";
	}

	// upper_bound (>)
	{
		auto upper1 = m.upper_bound(380); // first element greater than key
		auto upper2 = m.upper_bound(1);
		auto upper3 = m.upper_bound(30);
		auto upper4 = m.upper_bound(12345);
		auto upper5 = m.upper_bound(-123);
		std::cout << "Upper 1: " << (upper1 != m.end() ? upper1->second : "end") << "\n";
		std::cout << "Upper 2: " << (upper2 != m.end() ? upper2->second : "end") << "\n";
		std::cout << "Upper 3: " << (upper3 != m.end() ? upper3->second : "end") << "\n";
		std::cout << "Upper 4: " << (upper4 != m.end() ? upper4->second : "end") << "\n";
		std::cout << "Upper 5: " << (upper5 != m.end() ? upper5->second : "end") << "\n";
	}
}

void lowerBound_upperBoundMultiMap_Example(const std::multimap<int, std::string> m)
{
	// lower_bound (>=)
	{
		auto lower1 = m.lower_bound(380); // first element not less than key
		auto lower2 = m.lower_bound(1);
		auto lower3 = m.lower_bound(30);
		auto lower4 = m.lower_bound(12345);
		auto lower5 = m.lower_bound(-123);
		std::cout << "Lower 1: " << (lower1 != m.end() ? lower1->second : "end") << "\n";
		std::cout << "Lower 2: " << (lower2 != m.end() ? lower2->second : "end") << "\n";
		std::cout << "Lower 3: " << (lower3 != m.end() ? lower3->second : "end") << "\n";
		std::cout << "Lower 4: " << (lower4 != m.end() ? lower4->second : "end") << "\n";
		std::cout << "Lower 5: " << (lower5 != m.end() ? lower5->second : "end") << "\n";
	}

	// upper_bound (>)
	{
		auto upper1 = m.upper_bound(380); // first element greater than key
		auto upper2 = m.upper_bound(1);
		auto upper3 = m.upper_bound(30);
		auto upper4 = m.upper_bound(12345);
		auto upper5 = m.upper_bound(-123);
		std::cout << "Upper 1: " << (upper1 != m.end() ? upper1->second : "end") << "\n";
		std::cout << "Upper 2: " << (upper2 != m.end() ? upper2->second : "end") << "\n";
		std::cout << "Upper 3: " << (upper3 != m.end() ? upper3->second : "end") << "\n";
		std::cout << "Upper 4: " << (upper4 != m.end() ? upper4->second : "end") << "\n";
		std::cout << "Upper 5: " << (upper5 != m.end() ? upper5->second : "end") << "\n";
	}
}

void eraseMapExample(std::map<int, std::string>& m)
{
	size_t res = 0;
	res = m.erase(380); // 1, by key
	res = m.erase(380); // 0, by key - no effect, key not found

	auto it = m.find(90);
	if (it != m.end())
	{
		m.erase(it); // by iterator
	}
	m.erase(m.begin()); // by iterator
	std::cout << "After erase:\n";
	showMap(m);
}

void eraseMultiMapExample(std::multimap<int, std::string>& m)
{
	//size_t res = 0;
	//res = m.erase(380); // 3, by key

	// remove all 380 keys
	auto range = m.equal_range(380); //remove all elements with key 380
	m.erase(range.first, range.second);

	auto nextRange = m.equal_range(123456789);
	m.erase(nextRange.first, nextRange.second); // no effect, key not found
}

int main()
{
	std::map<int, std::string> countryCodeMap;
	std::multimap<int, std::string> countryCodeMultiMap;

	std::cout << "Init maps\n";

	initMap(countryCodeMap);
	initMultiMap(countryCodeMultiMap);

	showMap(countryCodeMap);
	showMultiMap(countryCodeMultiMap);

	findElementMap(countryCodeMap, 1);
	findElementMap(countryCodeMap, 12345);

	atMap(countryCodeMap, 44);
	atMap(countryCodeMap, 54321);

	findElementMultiMap(countryCodeMultiMap, 380);
	findElementMultiMap(countryCodeMultiMap, 12345);

	lowerBound_upperBoundMap_Example(countryCodeMap);
	lowerBound_upperBoundMultiMap_Example(countryCodeMultiMap);

	eraseMapExample(countryCodeMap);
	eraseMultiMapExample(countryCodeMultiMap);

	countryCodeMap.count(380); // 0 or 1
	countryCodeMultiMap.count(380); // number of elements with key 380

	auto it = countryCodeMap.emplace_hint(countryCodeMap.find(44), 44, "New Zealand"); // UK
	auto it2 = countryCodeMap.emplace_hint(countryCodeMap.find(40), 40, "New Zealand"); // UK

	countryCodeMap.insert_or_assign(44, "Great Britain"); // update existing key
	countryCodeMap[44] = "United Kingdom"; // update existing key

	std::less<int> l = countryCodeMap.key_comp();




	// set
	{
		std::set<int> s;
		s.insert(10);
		s.insert(20);
		s.insert(20); // ignored

		std::unordered_set<int> us;
		us.insert(10);
		us.insert(20);
		us.insert(20); // ignored
	}
}
