#pragma once
#include <iostream>
#include <queue>
#include <deque>
#include <vector>
#include <list>
#include <forward_list>
#include <chrono>

using namespace std;

constexpr int N = 1'000'000'0;

template<typename Queue>
void benchmark(const string& name)
{
	Queue q;

	auto start = std::chrono::high_resolution_clock::now();

	for (int i = 0; i < N; i++)
	{
		q.push(i);
	}

	for (int i = 0; i < N; i++)
	{
		q.pop();
	}

	auto end = std::chrono::high_resolution_clock::now();
	auto duration = duration_cast<std::chrono::milliseconds>(end - start).count();

	cout << name << " → " << duration << " ms\n";
}

void queueStl()
{
	std::queue<int> q;
	q.push(1);
	q.push(2);
	q.push(3);

	while (!q.empty())
	{
		std::cout << q.front() << "\n";
		q.pop();
	}

	cout << "Benchmark std::queue with different containers (" << N << " elements)\n\n";

	// std::deque
	benchmark<queue<int, deque<int>>>("queue<deque>");

	//// std::vector (⚠️ вектор неефективний, бо pop() вимагає зміщення всіх елементів)
	//benchmark<queue<int, vector<int>>>("queue<vector>");

	// std::list
	benchmark<queue<int, list<int>>>("queue<list>");

	// std::forward_list (⚠️ forward_list не має push_back, тому std::queue з ним не скомпілюється)
	// benchmark<queue<int, forward_list<int>>>("queue<forward_list>"); // ❌ не скомпілюється

	cout << "\n⚠️ std::forward_list не можна напряму використати як контейнер для std::queue,\n"
		"бо queue вимагає push_back/pop_front, а forward_list має лише push_front/pop_front.\n";
}