
## Homework 2
### 1. In the mutex-locking pseudocode of Figure 4.10 on page 111, there are two consecutive steps that remove the current thread from the runnable threads and then unlock the spinlock. Because spinlocks should be held as briefly as possible, we ought to consider whether these steps could be reversed, as shown in Figure 4.28 [on page 148]. Explain why reversing them would be a bad idea by giving an example sequence of events where the reversed version malfunctions.

<p style = "margin:2%; font-size:16px; line-height:1.8"> To call unlock on a mutex, the mutex must be owned by the current thread. If this condition is not met, anything could happen. This undefined behavior can cause problems due to the random nature of the  situation - crashing or possible memory bug. For example, [Example here] </p>

### 2. Suppose the first three lines of the audit method in Figure 4.27 on page 144 were replaced by the following two lines:
 ```java
int seatsRemaining = state.get().getSeatsRemaining();
int cashOnHand = state.get().getCashOnHand();
```
### Explain why this would be a bug.

<p style = "margin:2%; font-size:16px; line-height:1.8">This would be a bug because of the nature of AtomicReference's support for nonblocking synchronization. The first line in Figure 4.27 capures a snapshot of the current state that will then be consistent across all uses of that State object. Should we remove that snapshot and instead directly reference state.get(), calls to getSeatsRemaining and getCashOnHand would appear inconsistent and cause possible problems. </p>

### 3. <b>IN JAVA:</b> Write a test program in Java for the BoundedBuffer class of Figure 4.17 on page 119 of the textbook.

### 4. <b>IN JAVA:</b> Modify the BoundedBuffer class of Figure 4.17 [page 119] to call notifyAll() only when inserting into an empty buffer or retrieving from a full buffer. Test that the program still works using your test program from the previous exercise.

### 5. Suppose T1 writes new values into x and y and T2 reads the values of both x and y. Is it possible for T2 to see the old value of x but the new value of y? Answer this question three times: once assuming the use of two-phase locking, once assuming the read committed isolation level is used and is implemented with short read locks, and once assuming snapshot isolation. In each case, justify your answer.

### 6. Assume a page size of 4 KB and the page mapping shown in Figure 6.10 on page 225. What are the virtual addresses of the first and last 4-byte words in page 6? What physical addresses do these translate into?

### 7. At the lower right of Figure 6.13 on page 236 are page numbers 1047552 and 1047553. Explain how these page numbers were calculated.

### 8. Write a program that loops many times, each time using an inner loop to access every 4096th element of a large array of bytes. Time how long your program takes per array access. Do this with varying array sizes. Are there any array sizes when the average time suddenly changes? Write a report in which you explain what you did, and the hardware and software system context in which you did it, carefully enough that someone could replicate your results.

<p style = "margin:2%; font-size:16px; line-height:1.8">Implemented in file named numberEight.C </p>

### 9. Figure 7.20 [page 324] contains a simple C program that loops three times, each time calling the fork() system call. Afterward it sleeps for 30 seconds. Compile and run this program, and while it is in its 30-second sleep, use the ps command in a second terminal window to get a listing of processes. How many processes are shown running the program? Explain by drawing a family tree of the processes, with one box for each process and a line connecting each (except the first one) to its parent.