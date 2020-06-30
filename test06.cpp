//
// Created by nipnie on 6/30/20.
//

/**
 * joinable:
 * 检查线程是否可被 join。检查当前的线程对象是否表示了一个活动的执行线程，
 * 由默认构造函数创建的线程是不能被 join 的。另外，如果某个线程 已经执行完任务，
 * 但是没有被 join 的话，该线程依然会被认为是一个活动的执行线程，因此也是可以被 join 的。
 *
 * join:
 * Join 线程，调用该函数会阻塞当前线程，直到由 *this 所标示的线程执行完毕 join 才返回。
 */

#include <iostream>
#include <thread>
#include <chrono>

void foo()
{
    std::this_thread::sleep_for(std::chrono::seconds(1));
}

int main()
{
    std::thread t;
    std::cout << "before starting, joinable: " << t.joinable() << '\n';

    t = std::thread(foo);
    std::cout << "after starting, joinable: " << t.joinable() << '\n';

    t.join();
}