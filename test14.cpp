//
// Created by nipnie on 6/30/20.
//

/**
 * sleep_until:
 * 线程休眠至某个指定的时刻(time point)，该线程才被重新唤醒。
 * template< class Clock, class Duration >
 * void sleep_until( const std::chrono::time_point<Clock,Duration>& sleep_time );
 *
 * sleep_for:
 * 线程休眠某个指定的时间片(time span)，该线程才被重新唤醒，不过由于线程调度等原因，实际休眠时间可能比 sleep_duration 所表示的时间片更长。
 */

#include <iostream>
#include <chrono>
#include <thread>

int main()
{
    std::cout << "Hello waiter" << std::endl;
    std::chrono::milliseconds dura( 2000 );
    std::this_thread::sleep_for( dura );
    std::cout << "Waited 2000 ms\n";
}