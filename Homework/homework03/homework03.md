# Homework 3

### **1.** Write an implementation of the Dining Philosophers program, demonstrating deadlock avoidance.

#### **2.** Write a short paragraph explaining why your program is immune to deadlock?

### **3.** Modify the **file-processes.cpp** program from Figure 8.2 on page 338 to simulate this shell command:

```
tr a-z A-Z < /etc/passwd
```

### **4.** Write the code in C, not in C++. Write a program that opens a file in read-only mode and maps the entire file into the virtual-memory address space using **mmap**. The program should search through the bytes in the mapped region, testing whether any of them is equal to the character **X**. As soon as an **X** is found, the program should print a success message and exit. If the entire file is searched without finding an **X**, the program should report failure. Time your program on files of varying size, some of which have an **X** at the beginning, while others have an **X** only at the end or not at all.

### **5.** Read enough of Chapter 10 to understand the following description: In the TopicServer implementation shown in Figures 10.9 and 10.10 on pages 456 and 457, the receive method invokes each subscriber's receive method. This means the TopicServer's receive method will not return to its caller until after all of the subscribers have received the message. Consider an alternative version of the TopicServer, in which the receive method simply places the message into a temporary holding area and hence can quickly return to its caller. Meanwhile, a separate thread running in the TopicServer repeatedly loops, retrieving messages from the holding area and sending each in turn to the subscribers. What Java class from Chapter 4 would be appropriate to use for the holding area? Describe the pattern of synchronization provided by that class in terms that are specific to this particular application.
