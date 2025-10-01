#pragma once
#include <iostream>
#include <queue>
#include <vector>

template<typename T, typename Container = std::vector<T>>
class MyLess
{
public:
	bool operator() (T l, T r) const
	{
		return l < r;
	}
};

template<typename T, typename Container = std::vector<T>>
class MyMore
{
public:
	bool operator() (T l, T r) const
	{
		return l > r;
	}
};

void priorityQueueStl()
{
	{
		//std::priority_queue<int> intPQ;
		//std::priority_queue<int, std::vector<int>, MyLess<int>> intPQ;
		std::priority_queue<int, std::vector<int>, MyMore<int>> intPQ;
		intPQ.push(5);
		intPQ.push(1);
		intPQ.push(7);
		intPQ.push(9);
		intPQ.push(6);
		intPQ.push(3);
		intPQ.push(2);
		intPQ.push(1);
		intPQ.push(5);
		intPQ.push(1);

		//intPQ.pop();
		//intPQ.pop();
		//intPQ.pop();
		//intPQ.pop();
		//intPQ.pop();
		//intPQ.pop();

		std::less<int> l;
		std::boolalpha;
		std::cout << std::boolalpha << l(3, 4) << "\n";
		std::cout << std::boolalpha << l(4, 3) << "\n";

		std::cout << std::format("{0} qwerty - qwerty {1}, {2}", l(3, 4), "hello", "world") << "\n";
		std::cout << std::format("{0}", l(4, 3)) << "\n";

		while (!intPQ.empty())
		{
			std::cout << intPQ.top() << " ";
			intPQ.pop();
		}
		std::cout << "\n";
	}


	{
		struct TodoItem
		{
			std::string title;
			int priority;

			bool operator< (const TodoItem& right) const
			{
				return this->priority < right.priority;
			}
		};

		std::priority_queue<TodoItem> todoQueue;
		todoQueue.emplace(TodoItem{ "Feed the cat", 3 });
		todoQueue.emplace(TodoItem{ "Take out the trash", 7 });
		todoQueue.emplace(TodoItem{ "Relax", 5 });
	}
}