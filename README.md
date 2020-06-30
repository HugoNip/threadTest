# Thread in Operating System
## What is a Thread?  
A thread is a path of execution within a process. 
A process can contain multiple threads.

## Why Multithreading?
A thread is also known as lightweight process. The idea is to achieve parallelism by 
dividing a process into multiple threads. For example, in a browser, multiple tabs can be different threads. 
MS Word uses multiple threads: one thread to format the text, another thread to process inputs, etc. 
More advantages of multithreading are discussed below

## Process vs Thread?
The primary difference is that threads within the same process run in a shared memory space, 
while processes run in separate memory spaces.  
Threads are not independent of one another like processes are, and as a result 
threads share with other threads their code section, data section, and OS resources (like open files and signals). 
But, like process, a thread has its own program counter (PC), register set, and stack space.

### Advantages of Thread over Process
#### 1. Responsiveness:  
If the process is divided into multiple threads, 
if one thread completes its execution, then its output can be immediately returned.

#### 2. Faster context switch:   
Context switch time between threads is lower compared to process context switch. 
Process context switching requires more overhead from the CPU.

#### 3. Effective utilization of multiprocessor system: 
If we have multiple threads in a single process, then we can schedule multiple threads 
on multiple processor. This will make process execution faster.

#### 4. Resource sharing: 
Resources like code, data, and files can be shared among all threads within a process.
Note: stack and registers can’t be shared among the threads. Each thread has its own stack and registers.

#### 5. Communication: 
Communication between multiple threads is easier, as the threads shares common address space. 
while in process we have to follow some specific communication technique for communication between two process.

#### 6. Enhanced throughput of the system: 
If a process is divided into multiple threads, and each thread function is considered as one job, 
then the number of jobs completed per unit of time is increased, thus increasing the throughput of the system.

## Two types of Threads
[*User Level Thread* and *Kernel Level Thread*](https://www.geeksforgeeks.org/difference-between-user-level-thread-and-kernel-level-thread/)

## Single/Multi Threaded process
![gate-1.png](https://github.com/HugoNip/threadTest/blob/master/figures/gate-1.png)

A thread is a basic unit of CPU utilization, consisting of a program counter, 
a stack, and a set of registers, (and a thread ID.) As you can see, for a single thread of control – 
there is one program counter, and one sequence of instructions that can be carried out at any given
time and for multi-threaded applications-there are multiple threads within a single process, each
having their own program counter, stack and set of registers, but sharing common code, data, 
and certain structures such as open files.


# Reference
https://www.geeksforgeeks.org/thread-in-operating-system/  
https://www.runoob.com/w3cnote/cpp-std-thread.html  
https://en.cppreference.com/w/cpp/thread/thread/thread  
