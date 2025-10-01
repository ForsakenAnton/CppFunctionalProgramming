#pragma once
#include <iostream>
#include <forward_list>
#include <list> // linkedList

template<typename T>
struct Node
{
private:
	T data; // корисне навантаження
	
public:
	Node* next = nullptr; // покажчик на такий самий тп, як цей класс

	explicit Node(const T& data) : data{ data }
	{
	}

	T getData() const
	{
		return data;
	}

	void print()
	{
		std::cout << data << "\n";
	}
};

template<typename T>
class ForwardList
{
private:
	Node<T>* head = nullptr; // перший елемент списку
	//Node<T>* tail; // останній елемент списку

public:
	ForwardList() = default;

	// newHead(next = head) -> head -> el1 -> el2 ... tail
	void addToHead(const T& value)
	{
		// нехай head is: 3 => 2 => 1;

		Node<T>* newHead = new Node<T>{ value }; // 123
		newHead->next = head; // 123 => 3 => 2 => 1
		head = newHead; // 123 => 3 => 2 => 1
	}

	void removeFromHead()
	{
		if (head == nullptr)
		{
			return;
		}

		Node<T>* headToDelete = head; // 3 => 2 => 1
		head = headToDelete->next; // 2 => 1

		delete headToDelete; // delete 3
	}

	void print() const
	{
		for (
			Node<T>* current = head;
			current != nullptr;
			current = current->next)
		{
			current->print();
		}
	}

	Node<T>* find(const T& value) const
	{
		for (
			Node<T>* current = head;
			current != nullptr;
			current = current->next)
		{
			if (current->getData() == value)
			{
				return current;
			}
		}

		return nullptr;
	}
};



void forwardListExample()
{
	ForwardList<int> fl;
	fl.addToHead(1);
	fl.addToHead(2);
	fl.addToHead(3);

	fl.print();

	std::cout << "Finded 2 " << fl.find(2)->getData() << "\n";
	std::cout << "Finded 3 " << fl.find(3)->getData() << "\n";

	auto nullptrNode = fl.find(123);
	if (nullptrNode != nullptr)
	{
		std::cout << "Finded 123 " << nullptrNode->getData() << "\n";
	}

	fl.removeFromHead();
	fl.removeFromHead();
	fl.removeFromHead();
	fl.removeFromHead();
}

void stl_forward_list_Example()
{
	std::forward_list<int> fl;
	fl.push_front(1);
	fl.push_front(2);
	fl.push_front(3);

	for (const int& el : fl)
	{
		std::cout << el << " ";
	}
	std::cout << "\n";

	auto it = fl.begin(); // Ok
	it++; // Ok
	//it--; // Compile error
	//it += 2; // Compile error

	auto itEnd = fl.end(); // Ok


	for (
		auto currentIt = fl.begin(), endIt = fl.end();
		currentIt != endIt;
		currentIt++)
	{
		std::cout << *currentIt << " ";
	}
	std::cout << "\n";

	fl.emplace_after(it, 123); // 3, 2, 123, 1
	fl.erase_after(it); // 3, 2, 1


	std::forward_list<int> anotherFL{ 5, 10 };
	anotherFL.emplace_front(6);
	anotherFL.emplace_front(7);
	anotherFL.emplace_front(8);

	fl.sort();
	anotherFL.sort();

	anotherFL.merge(fl);
}

void stl_linked_list_Example()
{
	std::list<int> l({3, 4, 5, 6});
}