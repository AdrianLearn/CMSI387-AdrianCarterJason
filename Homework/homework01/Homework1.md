# Homework1

### Question 1
#### What is the difference between an operating system and middleware?

> An operating system is software that uses the hardware resources of a computer system to provide support for the execution of other software. Operating systems provide the following services: allow multiple computations to take place concurrently on a single computer system, control the interactions between the concurrent computations (enforce rules, provide isolated, private areas of memory), provide support for controlled interaction of computations even if they do not run concurrently, provide support for controlled interaction of computations spread among different computer systems through networking, and use file systems so that computations can read data from files written by earlier computations. 
>
> The true operating system is often referred to as the kernel, a fundamental portion of the operating system that provides an API supporting
computations with controlled interactions.
>
> Middleware refers to software which occupies a middle position between application programs and operating systems. It is like a layer on top of the operating system, which acts as a go-between for the applications and the operating system itself. Middleware uses services from an operating system and in turn provides services to application programs to support controlled interaction.
>
> Operating systems and middleware have a lot in common; both are software used to support other software, both provide a similar range of services centered around controlled interaction. Middleware can also enforce rules designed to keep computations from interfering with each other, and can bring computations at different times into contact (through file systems and storage of past computations) and can also support interaction between different computers through networking services.
>
> Operating systems and middleware are not the same, however; they rely on different underlying providers for lower-level services, and operating systems provide the services in its API by making use of the features supported by the hardware. Middleware instead provides services by making use of the features supported by the underlying operating system. For example, a piece of middleware may permit the user to edit a database, but the middleware relies on the OS capability to read and understand that database.

### Question 2
#### What is the relationship between threads and processes?

> A thread is the fundamental unit of concurrency. Any one sequence of programmed actions is a thread. A process is a container that holds the thread or threads that were running and protects them from unwanted interactions with other unrelated threads running on the same computer. 

### Question 3
#### Of all the topics previewed in chapter one of the text book, which one are you most looking forward to learning more about? Why?

Team Member | Topic
----------- | ------------
Carter      | I am most interested in learning about the interconnectivity of computers and how information created on one computer can end up on a computer across the world. I think its a brilliant development and one of the many modern wonders of our world: the ability to transmit information relatively instantaneously.
Adrian      | I am looking foward to learning more about how operating systems function. Personally, I feel I have always taken an operating system for granted, without realizing what computers were like before Windows or MacOS. By learning more about how this system software will give me a greater understanding of what is going on exactly in a computer.
Jason       | The topic that I think will be the most interesting is learning about middleware in general. Previous to hearing the title of this textbook, I had never heard of middleware. Im hoping that learning about this topic and others like it will deepen my understanding of computer systems and the connectivity of everything going inside each and every computational device. I also only have a surface level understanding of the complexities of things like API's, so i'm hoping that my gaps of knowlege will be filled. Learning about these different topics will help make me a more well rounded and stronger software engineer.

### Question 4
#### Suppose thread A goes through a loop 100 times, each time performing one disk I/O operation, taking 10 milliseconds, and then some computation, taking 1 millisecond. While each 10-millisecond disk operation is in progress, thread A cannot make any use of the processor. Thread B runs for 1 second, purely in the processor, with no I/O. One millisecond of processor time is spent each time the processor switches threads; other than this switching cost, there is no problem with the processor working on thread B during one of thread A's I/O operations. (The processor and disk drive do not contend for memory access bandwidth, for example.)

#### a. Suppose the processor and disk work purely on thread A until its completion, and then the processor switches to thread B and runs all of that thread. What will the total elapsed time be?

> Thread A Completion Time: 100(iterations) * [10 ms(Disk I/O operation) + 1 ms (computation)] = 1100 ms
>
> Thread B Completion Time: 1s = 1000 ms
> 
> Total Switch Time: 1 ms

Total Time: **2101 ms**

#### b. Suppose the processor starts out working on thread A, but every time thread A performs a disk operation, the processor switches to B during the operation and then back to A upon the disk operation's completion. What will the total elapsed time be?
> It takes 10 ms for thread A to complete a disk I/O operation. Every time this operation starts, the processor switches to B, costing 1 ms. When thread A's operation finishes, the processor switches back to thread A, costing 1 ms. This switch will add 2 ms to every thread A operation. Thread B's operation, however,  is concurrent with thread A. Thread B has effectively 10 ms per operation of thread A to process, as the switch occurs after the thread A operation starts, and switches back after it finishes. We can model this with the following equations:
>
> Thread A Completion Time: 100(iterations) * [10 ms(Disk I/O operation) + 1 ms (computation)] = 1100 ms
>
> Thread B Completion Time: 10 ms (time per thread A operation) * 100 (thread A operations to complete) = <s>1000 ms</s> (concurrent with thread A)
> 
> Total Switch Time: 100 (iterations) * 2 ms (switch time, given by switch from A to B, B to A) (not concurrent) = 200 ms

Total Time: **1300 ms**

#### c. In your opinion, which do you think is more efficient, and why?

> According to the calculations, the switch method is much more efficient: it takes much less time to complete. This saved time can add up when considering larger calculations e.g. an operation with millions of iterations. The switch method utilizes the processor more efficiently; by calculating thread B during the time when thread A cannot make use of the processor, this method saves 8 ms (10 ms thread B calculation - 2 ms switch time) per iteration.

### Question 5
####  Find and read the documentation for pthread_cancel(). Then, using your "C" programming environment, use the information and the model provided in Figure 2.4 on page 26 of the text book to write a program in which the initial (main) thread creates a second thread. The main thread should sit on a read call of some kind, waiting to read input from the keyboard, waiting until the user presses the Enter key. At that point, it should kill off the second thread and print out a message reporting that it has done so. Meanwhile, the second thread should be in an infinite loop, each time around sleeping five seconds and then printing out a message. Try running your program. Can the sleeping thread print its  periodic messages while the main thread is waiting for keyboard input? Can the main thread read input, kill the sleeping thread, and print a message while the sleeping thread is in the early part of one of its five-second sleeps?

```C
#include <pthread.h>
#include <unistd.h>
#include <stdio.h>

void* child(void* p) {
    while(1) {
        sleep(5);
        printf("Hey mister!\n");
    }
    return NULL;
}

int main(int argc, char *argv[]) {
    pthread_t child_thread;
    int code;

    code = pthread_create(&child_thread, NULL, child, NULL);
    if (code) {
        fprintf(stderr, "pthread_create failed with code %d\n", code);
    }

    while(1) {
        char c = getchar();
        if (c = '\n') {
            break;
        }
    }

    printf("THE CHILD (THREAD) HAS BEEN ELIMINATED.\n");
    pthread_cancel(child_thread);
    pthread_exit(NULL);
    return 0;
}
```

> The sleeping thread can print its periodic messages while the main thread is waiting for keyboard input. The main thread can also read input, kill the sleeping thread, and print a message while the sleeping thread is in the early part of its five-second sleeps.

### Question 6
#### Suppose a system has three threads (T1, T2, and T3) that are all available to run at time 0 and need one, two, and three seconds of processing, respectively. Suppose each thread is run to completion before starting another. Draw six different Gantt charts, one for each possible order the threads can be run in. For each chart, compute the turnaround time of each thread; that is, the time elapsed from when it was ready (time 0) until it is complete. Also, compute the average turnaround time for each order. Which order has the shortest average turnaround time? What is the name of the scheduling policy that produces this order?


<div align="center">
<b>T1, T2, T3</b>: 0, 1, 3 | Ave: <i>10/3 Seconds</i><br>
<b>T1, T3, T2</b>: 0, 1, 4 | Ave: <i>11/3 Seconds</i><br>
<b>T2, T1, T3</b>: 0, 2, 3 | Ave: <i>11/3 Seconds</i><br>
<b>T2, T3, T1</b>: 0, 2, 5 | Ave: <i>13/3 Seconds</i><br>
<b>T3, T1, T2</b>: 0, 3, 4 | Ave: <i>13/3 Seconds</i><br>
<b>T3, T2, T1</b>: 0, 3, 5 | Ave: <i>14/3 Seconds</i><br>
<br>
<img src="https://raw.githubusercontent.com/AdrianLearn/CMSI387-AdrianCarterJason/main/Homework/homework01/Question%206.png?token=AJM7Q5QFQ2M26363OORI7HLAEHGH6" />
</div>
<br>


{T1, T2, T3} has shortest average turnaround time at 10/3 seconds per thread.
The name of the scheduling policy that produces this order is shortest job first scheduling. 

### Question 7
#### Google the C standard library API and find out how to get information from the command line by using a printf() call to display a prompt, then another call [which you will look up] to get the user input. Write a program in C to prompt the user demographic information including name, age, class year, and any three other data times you wish. Structure the program as a call-and-response program such that each data item is a single question with a single answer. When all data has been obtained, display the data on the console. Each data item must be on a separate line, and it must be appropriately labeled. The output must be done using a single printf() statement.

```C
#include <stdio.h>
int main()
{
    char name[20], food[20], city[20], class_year[20];
    int age, fav_number;

    printf("Input your name: ");
    scanf("%s", name);
    printf("Input your age: ");
    scanf("%d", &age);
    printf("Input your class year: ");
    scanf("%s", class_year);
    printf("What is your favorite food: ");
    scanf("%s", food);
    printf("What city do you live in: ");
    scanf("%s", city);
    printf("What is your favorite number: ");
    scanf("%d", &fav_number);

    printf("Name: %s\nAge: %d\nClass Year: %s\nFavorite Food: %s\nCity: %s\nFavorite Number: %d\n", name, age, class_year, food, city, fav_number);
    return 0;
}
```
