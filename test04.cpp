//
// Created by nipnie on 6/30/20.
//

#include <stdio.h>
#include <stdlib.h>

#include <chrono>    // std::chrono::seconds
#include <iostream>  // std::cout
#include <thread>    // std::thread, std::this_thread::sleep_for

void thread_task(int n) {
    std::this_thread::sleep_for(std::chrono::seconds(n));
    std::cout << "hello thread " << std::this_thread::get_id()
              << " paused " << n << " seconds" << std::endl;
}

int main(int argc, const char *argv[])
{
    std::thread threads[5]; // 5 objects

    std::cout << "Spawning 5 threads...\n";

    for (int i = 0; i < 5; i++) {
        threads[i] = std::thread(thread_task, i + 1);
        std::cout << "checkpoint 1: " << i << std::endl;
    }

    std::cout << "Done spawning threads! Now wait for them to join\n";

    for (auto& t: threads) {
        t.join();
        std::cout << "checkpoint 2 ... " << std::endl;
    }

    std::cout << "All threads joined.\n";

    return EXIT_SUCCESS;
}

/**
 * results:
 * Spawning 5 threads...
 * checkpoint 1: 0
 * checkpoint 1: 1
 * checkpoint 1: 2
 * checkpoint 1: 3
 * checkpoint 1: 4
 * Done spawning threads! Now wait for them to join
 * hello thread 139900092651264 paused 1 seconds
 * checkpoint 2 ...
 * hello thread 139900084258560 paused 2 seconds
 * checkpoint 2 ...
 * hello thread 139900075865856 paused 3 seconds
 * checkpoint 2 ...
 * hello thread 139900067473152 paused 4 seconds
 * checkpoint 2 ...
 * hello thread 139900059080448 paused 5 seconds
 * checkpoint 2 ...
 * All threads joined.
 */