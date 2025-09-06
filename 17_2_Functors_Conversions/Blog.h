#pragma once
#include <iostream>

class Blog
{
private:
	std::string title;
	std::string author;

public:
	Blog() = delete;
	Blog(const Blog& blog) = default;

	Blog& operator=(const Blog& blog) = delete;

	Blog(std::string title, std::string author) 
		: title{ title }, author{ author }
	{

	}

	void operator()()
	{
		std::cout << "Blog title: " << title << ", author: " << author << std::endl;
	}

	void operator()(const std::string& info)
	{
		std::cout << info << std::endl;
		std::cout << "Blog title: " << title << ", author: " << author << std::endl;
	}

	Blog operator()(int)
	{
		return *this;
	}
};