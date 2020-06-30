cmake_minimum_required(VERSION 2.8)
project(threadTest)

set(CMAKE_CXX_STANDARD 11)
# set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall  -O3 -march=native -std=c++11")

find_package (Threads REQUIRED)

add_executable(test01 test01.cpp)
target_link_libraries(test01 ${CMAKE_THREAD_LIBS_INIT})

add_executable(test02 test02.cpp)
target_link_libraries(test02 ${CMAKE_THREAD_LIBS_INIT})

add_executable(test03 test03.cpp)
target_link_libraries(test03 ${CMAKE_THREAD_LIBS_INIT})

add_executable(test04 test04.cpp)
target_link_libraries(test04 ${CMAKE_THREAD_LIBS_INIT})

add_executable(test05 test05.cpp)
target_link_libraries(test05 ${CMAKE_THREAD_LIBS_INIT})

add_executable(test06 test06.cpp)
target_link_libraries(test06 ${CMAKE_THREAD_LIBS_INIT})

add_executable(test07 test07.cpp)
target_link_libraries(test07 ${CMAKE_THREAD_LIBS_INIT})

add_executable(test08 test08.cpp)
target_link_libraries(test08 ${CMAKE_THREAD_LIBS_INIT})

add_executable(test09 test09.cpp)
target_link_libraries(test09 ${CMAKE_THREAD_LIBS_INIT})

add_executable(test10 test10.cpp)
target_link_libraries(test10 ${CMAKE_THREAD_LIBS_INIT})

add_executable(test11 test11.cpp)
target_link_libraries(test11 ${CMAKE_THREAD_LIBS_INIT})

add_executable(test12 test12.cpp)
target_link_libraries(test12 ${CMAKE_THREAD_LIBS_INIT})

add_executable(test13 test13.cpp)
target_link_libraries(test13 ${CMAKE_THREAD_LIBS_INIT})

add_executable(test14 test14.cpp)
target_link_libraries(test14 ${CMAKE_THREAD_LIBS_INIT})