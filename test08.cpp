//
// Created by nipnie on 6/30/20.
//

/**
 * detach:
 * Detach 线程。 将当前线程对象所代表的执行实例与该线程对象分离，使得线程的执行可以单独进行。一旦线程执行完毕，它所分配的资源将会被释放。
 *
 * 调用 detach 函数之后：
 * 1. *this 不再代表任何的线程执行实例。
 * 2. joinable() == false
 * 3. get_id() == std::thread::id()
 * 另外，如果出错或者 joinable() == false，则会抛出 std::system_error。
 */

#include <iostream>
#include <chrono>
#include <thread>

void independentThread()
{
    std::cout << "Starting concurrent thread.\n";
    std::this_thread::sleep_for(std::chrono::seconds(5));
    std::cout << "Exiting concurrent thread.\n";
}

void threadCaller()
{
    std::cout << "Starting thread caller.\n";
    std::thread t(independentThread);
    t.detach();
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << "Exiting thread caller.\n";
}

int main()
{
    threadCaller();
    std::this_thread::sleep_for(std::chrono::seconds(5));
}