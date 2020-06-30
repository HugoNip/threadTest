//
// Created by nipnie on 6/30/20.
//

#include <iostream>
#include <utility>
#include <thread>
#include <chrono>
#include <functional>

void f1(int n)
{
    for (int i = 0; i < 5; ++i) {
        std::cout << "f1: " << i << std::endl;
        std::cout << "Thread " << n << " executing\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
}

void f2(int& n)
{
    for (int i = 0; i < 5; ++i) {
        std::cout << "f2: " << i << std::endl;
        std::cout << "Thread 2 executing\n";
        ++n;
        std::cout << "checkpoint 6: " << n << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
}

int main()
{
    int n = 0;
    std::thread t1; // t1 is not a thread
    std::cout << "checkpoint 1: " << n << std::endl;
    std::thread t2(f1, n + 1); // pass by value
    std::cout << "checkpoint 2: " << n << std::endl;
    std::thread t3(f2, std::ref(n)); // pass by reference
    std::cout << "checkpoint 3: " << n << std::endl;
    std::thread t4(std::move(t3)); // t4 is now running f2(). t3 is no longer a thread
    std::cout << "checkpoint 4: " << n << std::endl;
    t2.join();
    std::cout << "checkpoint 5: " << n << std::endl;
    t4.join();
    std::cout << "Final value of n is " << n << '\n';
}

/**
 * results
 * Thread 1 executing
 * Thread 2 executing
 * Thread 1 executing
 * Thread 2 executing
 * Thread 1 executing
 * Thread 2 executing
 * Thread 1 executing
 * Thread 2 executing
 * Thread 1 executing
 * Thread 2 executing
 * Final value of n is 5
 */