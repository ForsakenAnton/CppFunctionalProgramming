#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <algorithm>
#include <chrono>
using namespace std;

std::chrono::steady_clock::time_point getCurrentTime()
{
    auto currentTime = std::chrono::high_resolution_clock::now();
    return currentTime;
}

std::chrono::microseconds calculateDuration(
    std::chrono::steady_clock::time_point end_time,
    std::chrono::steady_clock::time_point start_time)
{
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time);
    return duration;
}
// /////////////////////////////////////////////////////////////////////////////////////////////

// Initialize and Print methods /////////////////////////
template <class T>
void initializeArray(T arr[], long size)
{
    // заполняем рандомными значениями
    for (int i = 0; i < size; i++)
    {
        arr[i] = rand() % 100;
    }

    cout << "\n\n\n";
}

template <class T>
void printArray(T arr[], long size, string tip = "No sorted array:\n")
{
    cout << tip;

    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }

    cout << "\n\n";
}
/////////////////////////////////////////////////////////

int main()
{
    srand(static_cast<unsigned long>(time(nullptr)));
    // const long SIZE = 10; // для отладки
    const long SIZE = 1000; // для скорости выполнения отдельного вида сортировки
    int arr[SIZE];

    std::chrono::steady_clock::time_point startTime;
    std::chrono::steady_clock::time_point endTime;


    // std::sort(int* firstElement, int* lastElement)
    initializeArray(arr, SIZE);
    printArray(arr, SIZE);

    cout << "std::sort(int* firstElement, int* lastElement):\n";
    startTime = getCurrentTime();
    std::sort(arr, arr + SIZE);
    //std::sort(arr, arr + SIZE / 2); // Сортируем половину массива
    //std::sort(arr + 2, arr + 6); // Сортируем со 2-го по 6-й элементы
    endTime = getCurrentTime();
    cout << "Duration: " << calculateDuration(endTime, startTime).count() << " microseconds\n\n";

    printArray(arr, SIZE, "Sorted array:\n");
    ///////////////////////////////////////////////////////////////////////////////////////////


    // std::sort(int* firstElement, int* lastElement, bool Predicate)
    initializeArray(arr, SIZE);
    printArray(arr, SIZE);

    cout << "std::sort(int* firstElement, int* lastElement, bool Predicate):\n";
    startTime = getCurrentTime();
    std::sort(arr, arr + SIZE, [](int left, int right) {return left < right; }); // < - 0, 1, 2...
    //std::sort(arr, arr + SIZE, [](int left, int right) {return left > right; }); // > - 2, 1, 0...
    endTime = getCurrentTime();
    cout << "Duration: " << calculateDuration(endTime, startTime).count() << " microseconds\n\n";

    printArray(arr, SIZE, "Sorted array:\n");
    ///////////////////////////////////////////////////////////////////////////////////////////



    // Binary Search
    cout << "Binary Search:\n";
    cout << std::boolalpha;
    int searchedValue = 5;
    bool searchedResult = std::binary_search(arr, arr + SIZE, searchedValue);

    //// With Predicate
    //bool searched = std::binary_search(
    //    arr,
    //    arr + SIZE,
    //    searchedValue,
    //    [searchedValue](int i, int j) {return searchedValue % 2 != 0; });

    cout << "Result of binary searched the number " << searchedValue <<
        " is " << searchedResult << "\n\n";
    // ////////////////////////////////////////////////////////////////////////


    // std::for_each(start, end, VoidMethod(value))
    cout << "std::for_each(start, end, VoidMethod(value)):\n";
    std::for_each(
        arr,
        arr + SIZE,
        [](int el)
        {
            cout << "Element: " << el << endl;
        });
}
