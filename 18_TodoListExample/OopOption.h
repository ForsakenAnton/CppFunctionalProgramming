#pragma once
#include <iostream>
#include <vector>

struct Todo
{
	std::string title;
	int priority; // or enum class Priority { Low, Medium, High }
	bool isCompleted;
};

struct TodoListWrapper
{
private:
	std::vector<Todo> todos;

public:
	void addTodo(const std::string& title, int priority)
	{
		todos.push_back({ title, priority, false });
	}

	Todo& getLastTodo()
	{
		return todos.back();
	}	

	void markCompleted(size_t index)
	{
		if (index < todos.size())
		{
			todos[index].isCompleted = true;
		}
		else
		{
			std::cerr << "Invalid index\n";
		}
	}

	void displayTodos() const
	{
		for (size_t i = 0; i < todos.size(); ++i)
		{
			const auto& todo = todos[i];
			std::cout << i << ": " << todo.title 
					  << " [Priority: " << todo.priority 
					  << "] [Completed: " << (todo.isCompleted ? "Yes" : "No") << "]\n";
		}
	}
};

class TodoService
{
	private:
		TodoListWrapper todoList;

public:
	TodoService& addTodo(const std::string& title, int priority)
	{
		todoList.addTodo(title, priority);
		return *this;
	}

	TodoService& trimStart()
	{
		Todo& todo = todoList.getLastTodo();

		for (int i = 0; i < todo.title.size();)
		{
			if (todo.title[i] != ' ')
			{

				break;
			}

			todo.title = todo.title.substr(1, todo.title.size() - 2);
		}

		return *this;
	}

	void displayTodos() const
	{
		todoList.displayTodos();
	}
};

void startOOP()
{
	TodoService service;
	service
		.addTodo("    Learn C++", 1)
		.trimStart()
		.addTodo("  Learn C#", 2)
		.trimStart();

	service.displayTodos();
}