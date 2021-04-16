# Homework 3

### **1.** Write an implementation of the Dining Philosophers program, demonstrating deadlock avoidance.
see DiningPhilisophers.py
#### **2.** Write a short paragraph explaining why your program is immune to deadlock?
The main problem in the dining philosophers is that deadlock is cause when there is a philosopher with a fork but begins perpetually waiting for a knife. In the computer system itself there is a stack of unwarranted requests which can cause a deadlock. In other words we dont want a lock of resources that need to be shared within a group of people.  The solution we used uses semaphores which is a way to make sure that there is a data type that is able to control access to the resources and able to allocate the resources to multiple people.  In our code the way we solved the problem was we used a waiter to act as the resource allocation person in order to prevent starvation and deadlock.  We said that our code would make the philosphers aim to get both utensils and if they didn't than they would put the utensils back on the table. This allows other philosophers 

### **3.** Modify the **file-processes.cpp** program from Figure 8.2 on page 338 to simulate this shell command:

```
tr a-z A-Z < /etc/passwd
```

### **4.** Write the code in C, not in C++. Write a program that opens a file in read-only mode and maps the entire file into the virtual-memory address space using **mmap**. The program should search through the bytes in the mapped region, testing whether any of them is equal to the character **X**. As soon as an **X** is found, the program should print a success message and exit. If the entire file is searched without finding an **X**, the program should report failure. Time your program on files of varying size, some of which have an **X** at the beginning, while others have an **X** only at the end or not at all.


### **5.** Read enough of Chapter 10 to understand the following description: In the TopicServer implementation shown in Figures 10.9 and 10.10 on pages 456 and 457, the receive method invokes each subscriber's receive method. This means the TopicServer's receive method will not return to its caller until after all of the subscribers have received the message. Consider an alternative version of the TopicServer, in which the receive method simply places the message into a temporary holding area and hence can quickly return to its caller. Meanwhile, a separate thread running in the TopicServer repeatedly loops, retrieving messages from the holding area and sending each in turn to the subscribers. What Java class from Chapter 4 would be appropriate to use for the holding area? Describe the pattern of synchronization provided by that class in terms that are specific to this particular application.
An implementation of a bounded buffer class should be sufficient for this scenario. In concurrent programming, bounded buffers are helpful to avoid typical deadlock problems. In this implemntation, the program should place the messages into a bounded buffer instead of waiting for the for loop to finish. In this case, multiple consumers can pull the stored messages from the bounded buffer while avoiding deadlock due to the nature of a bounded buffer. Messages can be placed and accessed from the bounded buffer concurrently. 
