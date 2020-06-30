//
// Created by nipnie on 6/30/20.
//

// member function: get_id()

#include <iostream>
#include <thread>
#include <chrono>

void foo()
{
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << "checkpoint 7 ... " << std::endl;
}

int main()
{
    std::thread t1(foo);
    std::cout << "checkpoint 1 ... " << std::endl;

    std::thread::id t1_id = t1.get_id();
    std::cout << "checkpoint 2 ... " << std::endl;

    std::thread t2(foo);
    std::cout << "checkpoint 3 ... " << std::endl;

    std::thread::id t2_id = t2.get_id();
    std::cout << "checkpoint 4 ... " << std::endl;

    std::cout << "t1's id: " << t1_id << '\n';
    std::cout << "t2's id: " << t2_id << '\n';

    t1.join();
    std::cout << "checkpoint 5 ... " << std::endl;
    t2.join();
    std::cout << "checkpoint 6 ... " << std::endl;
}

/**
 * results
 * checkpoint 1 ...
 * checkpoint 2 ...
 * checkpoint 3 ...
 * checkpoint 4 ...
 * t1's id: 139830404269824
 * t2's id: 139830395877120
 * checkpoint 7 ...
 * checkpoint 7 ...
 * checkpoint 5 ...
 * checkpoint 6 ...
 */