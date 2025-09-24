#pragma once
#include <iostream>
#include <vector>

struct TodoItem
{
	std::string title;
	int priority; // or enum class Priority { Low, Medium, High }
	bool isCompleted;
};

TodoItem* updateTodoItem(TodoItem& target, const TodoItem& source)
{
	target.title = source.title;
	target.priority = source.priority;
	target.isCompleted = source.isCompleted;

	return &target;
}

TodoItem createTodoItem()
{
	TodoItem createditem;

	// Implementation for creating a new todo item

	return createditem;
}

bool validateTOdoItem(const TodoItem& item)
{
	// Implementation for validating a todo item
	if (item.title == "")
	{
		return false;
	}

	return true;
}

void addToList(std::vector<TodoItem>& data, const TodoItem& item)
{
	data.push_back(item);
}


void init(std::vector<TodoItem>& data)
{
	data.push_back({ "Buy groceries", 2, false });
	data.push_back({ "Finish project report", 1, false });
	data.push_back({ "Call mom", 3, true });
}

void startProgram()
{
	std::vector<TodoItem> todoList;
	init(todoList);

	auto createdItem = createTodoItem();
	if (validateTOdoItem(createdItem))
	{
		addToList(todoList, createdItem);
	}
	else
	{
		std::cout << "Invalid todo item. Please try again." << std::endl;
	}

	auto updatedTodoItem = updateTodoItem(todoList[0], { "Buy groceries and cook dinner", 2, false });

	addToList(todoList, createdItem);
}