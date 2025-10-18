#pragma once
#include <iostream>
#include <list>

class TodoItem 
{

};

class Person
{

};

template<typename T>
class IRepository
{
public:
	virtual std::list<T> getAll() const = 0;
	virtual T getById(int id) const = 0;
	virtual T create(T value) = 0;
	virtual T update(int id, T value) = 0;
	virtual T remove(int id) = 0;
};

class TodoItemsRepository : public IRepository<TodoItem>
{
private:
	std::list<TodoItem> data;

public:
	std::list<TodoItem> getAll() const
	{
		return data;
	}

	TodoItem getById(int id) const
	{
		//for (auto it = data.begin(); it < data.end(); it++)
		//{
		//	if (it->id == id)
		//	{
		//		return *it;
		//	}
		//}

		return TodoItem{};
	}

	TodoItem create(TodoItem value)
	{
		data.push_back(value);

		return value;
	}

	TodoItem update(int id, TodoItem value)
	{
		// TODO add updating logic
		return value;
	}

	TodoItem remove(int id)
	{
		// TODO add updating logic

		return TodoItem{};
	}
};

class PersonsRepository : public IRepository<Person>
{
private:
	std::list<Person> data;

public:
	std::list<Person> getAll() const
	{
		return data;
	}

	Person getById(int id) const
	{
		//for (auto it = data.begin(); it < data.end(); it++)
		//{
		//	if (it->id == id)
		//	{
		//		return *it;
		//	}
		//}

		return Person{};
	}

	Person create(Person value)
	{
		data.push_back(value);

		return value;
	}

	Person update(int id, Person value)
	{
		// TODO add updating logic
		return value;
	}

	Person remove(int id)
	{
		// TODO add updating logic

		return Person{};
	}
};


void pureAbstractClass()
{
	IRepository<TodoItem>* repo = new TodoItemsRepository{};
	repo->create(TodoItem{});
	repo->create(TodoItem{});

	IRepository<Person>* repo2 = new PersonsRepository{};
	// ...
}