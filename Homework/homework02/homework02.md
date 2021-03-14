## Homework 2

### 1. In the mutex-locking pseudocode of Figure 4.10 on page 111, there are two consecutive steps that remove the current thread from the runnable threads and then unlock the spinlock. Because spinlocks should be held as briefly as possible, we ought to consider whether these steps could be reversed, as shown in Figure 4.28 [on page 148]. Explain why reversing them would be a bad idea by giving an example sequence of events where the reversed version malfunctions.

<p style = "margin:2%; font-size:16px; line-height:1.8"> To call unlock on a mutex, the mutex must be owned by the current thread. If this condition is not met, anything could happen. This undefined behavior can cause problems due to the random nature of the  situation - crashing or possible memory bug. (possibly wrong, something about infinite loop) For example, [Example here] </p>

### 2. Suppose the first three lines of the audit method in Figure 4.27 on page 144 were replaced by the following two lines:

```java
int seatsRemaining = state.get().getSeatsRemaining();
int cashOnHand = state.get().getCashOnHand();
```

### Explain why this would be a bug.

<p style = "margin:2%; font-size:16px; line-height:1.8">This would be a bug because of the nature of AtomicReference's support for nonblocking synchronization. The first line in Figure 4.27 capures a snapshot of the current state that will then be consistent across all uses of that State object. Should we remove that snapshot and instead directly reference state.get(), calls to getSeatsRemaining and getCashOnHand would appear inconsistent and cause possible problems. </p>

### 3. <b>IN JAVA:</b> Write a test program in Java for the BoundedBuffer class of Figure 4.17 on page 119 of the textbook.

<p style = "margin:2%; font-size:16px; line-height:1.8"></p>

### 4. <b>IN JAVA:</b> Modify the BoundedBuffer class of Figure 4.17 [page 119] to call notifyAll() only when inserting into an empty buffer or retrieving from a full buffer. Test that the program still works using your test program from the previous exercise.

<p style = "margin:2%; font-size:16px; line-height:1.8"></p>

### 5. Suppose T1 writes new values into x and y and T2 reads the values of both x and y. Is it possible for T2 to see the old value of x but the new value of y? Answer this question three times: once assuming the use of two-phase locking, once assuming the read committed isolation level is used and is implemented with short read locks, and once assuming snapshot isolation. In each case, justify your answer.

    Need help starting Different types of locking, is it possible for the second thread
    first one - two phase locking. (two phases to locking process 1. take everything you need, do what you do | unlock it all) in this case T1 is taking lock on x, y does what it needs to do, then unlocks x and y. If that is the process, is it possible for the second one to read a "bogus" value from that
    second, very short reads - T1 locks x just long enough for what it needs to do, lock why (really short and quick) in this case, is it possible, while T1 has either of the resources locked, for T2 to come thorugh and read a bogus value out of it
    third, snapshot isolation two step process (T1 takes the snapshot and modifies the snapshot and writes it back.) In this case, is it possible for T2 to read a bogus value
    chapter 5

### 6. Assume a page size of 4 KB and the page mapping shown in Figure 6.10 on page 225. What are the virtual addresses of the first and last 4-byte words in page 6? What physical addresses do these translate into?

    Assuming a page size of 4 KB, the virtual addresses for the first and last 4 bytes of page 6 would be 24576 and 28668 respectively.

    These values are calculated as follows:
    If the first word of page 0 is 0, and the first word of page 1 is 4096, then the first word of page 6 is 4096(6) = 24576. To find the last word on page 6 we can go to the first word of page 7 and subtract 4 (the size of one word in bytes). 4096(7) - 4 = 28668. These translate to the 12288, and the 16380 physical addresses in the same manner. Because page 6 points to the page frame 3, we multiply 4096(3) to get the first words physical address. We multiply 4096(4)-4 to get the last word in the same page frame.

### 7. At the lower right of Figure 6.13 on page 236 are page numbers 1047552 and 1047553. Explain how these page numbers were calculated.

    The page directory points to invalid chunks from 1024-2047. These page numbers are calculated by taking the page table chunks and multiplying them by the page frames per chunk.

    In our case, the page table chunks equate to 1024, and the page frames/chunk equate to 1023. When multiplying these numbers together we get 1047552. To get the last word of the page frame before it we must add 1, giving us 1047553. We need to add 1 rather than subtract it because of the way figure 6.13 is oriented.

### 8. Write a program that loops many times, each time using an inner loop to access every 4096th element of a large array of bytes. Time how long your program takes per array access. Do this with varying array sizes. Are there any array sizes when the average time suddenly changes? Write a report in which you explain what you did, and the hardware and software system context in which you did it, carefully enough that someone could replicate your results.

<p style = "margin:2%; font-size:16px; line-height:1.8">Implemented in file named numberEight.C. Unfortunatly, our code executed too quickly to measure time between array access trials. For our trial, we decided to print out an arbritrary element of our array. In this case, we decided on 4095, 2694, and 300. We chose these indicies to space them out throughout the array to better understand how long it took to access each space. We conducted this test on a windows machine utilizing a high-end graphics card, 32Gb ram, and an Intel i9 CPU. </p>

### 9. Figure 7.20 [page 324] contains a simple C program that loops three times, each time calling the fork() system call. Afterward it sleeps for 30 seconds. Compile and run this program, and while it is in its 30-second sleep, use the ps command in a second terminal window to get a listing of processes. How many processes are shown running the program? Explain by drawing a family tree of the processes, with one box for each process and a line connecting each (except the first one) to its parent.

<p style = "margin:2%; font-size:16px; line-height:1.8"> When running this program and running 'ps -eaf | [user]' in an external console, 8 processes are listed, all labeled as ./a.out. The threads were related by the following diagram.</p>

![number9](https://raw.githubusercontent.com/AdrianLearn/CMSI387-AdrianCarterJason/main/Homework/homework02/number9.png?token=AJM7Q5X5MCLI3567ZPMVJ53AKQHLQ)
