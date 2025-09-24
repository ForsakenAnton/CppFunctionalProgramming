#pragma once
#include <vector>

//template <typename TItem, typename F, typename S>
template <template<typename, typename> typename TItem, typename F, typename S>
class Collection
{
private:
	//std::vector<TItem> items;
	std::vector<TItem<F, S>> items;

public:
	void addItem(const TItem<F, S>& item)
	{
		items.push_back(item);
	}

	void displayItems() const
	{
		for (const auto& item : items)
		{
			std::cout << item << std::endl;
		}
	}
};