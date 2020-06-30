//
// Created by nipnie on 6/30/20.
//

/**
 * join:
 * Join 线程，调用该函数会阻塞当前线程，直到由 *this 所标示的线程执行完毕 join 才返回。
 */

#include <iostream>
#include <thread>
#include <chrono>

void foo()
{
    // simulate expensive operation
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << "checkpoint 1 ..." << std::endl;
}

void bar()
{
    // simulate expensive operation
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << "checkpoint 2 ..." << std::endl;
}

int main()
{
    std::cout << "starting first helper...\n";
    std::thread helper1(foo);

    std::cout << "starting second helper...\n";
    std::thread helper2(bar);

    std::cout << "waiting for helpers to finish..." << std::endl;

    helper1.join();
    helper2.join();

    std::cout << "done!\n";
}