

import sys
import threading
import time


class Semaphore(object):

    def __init__(self, initial):
        self.lock = threading.Condition(threading.Lock())
        self.value = initial

    def up(self):
        with self.lock:
            self.value += 1
            self.lock.notify()

    def down(self):
        with self.lock:
            while self.value == 0:
                self.lock.wait()
            self.value -= 1


class Utensil(object):

    def __init__(self, number):
        self.number = number         
        self.user = -1                 # philosopher using it
        self.lock = threading.Condition(threading.Lock())
        self.taken = False

    def take(self, user):        
        with self.lock:
            while self.taken == True:
                self.lock.wait()
            self.user = user
            self.taken = True
            sys.stdout.write("p[%s] picked up c[%s]\n" % (user, self.number))
            self.lock.notifyAll()

    def drop(self, user):        
        with self.lock:
            while self.taken == False:
                self.lock.wait()
            self.user = -1
            self.taken = False
            sys.stdout.write("p[%s] put down c[%s]\n" % (user, self.number))
            self.lock.notifyAll()


class Philosopher (threading.Thread):

    def __init__(self, number, knives, fork, waiter):
        threading.Thread.__init__(self)
        self.number = number            # philosopher number
        self.knives = knives
        self.fork = fork
        self.waiter = waiter

    def run(self):
        for i in range(20):
    
            self.waiter.down()              
            time.sleep(0.1)                 # sleeping to simulate thinking
            self.knives.take(self.number)  
            time.sleep(0.1)
            self.fork.take(self.number)    
            time.sleep(0.1)                 # eating time
            self.fork.drop(self.number)    # drop fork utensil
            self.knives.drop(self.number)     # drop knives utensil
            self.waiter.up()            
        sys.stdout.write("p[%s] Thinking and Eating Time Finished\n" % self.number)


def main():
    # number of philosophers / utensils
    n = 5

    u = [Utensil(i) for i in range(n)]
    # https://en.wikipedia.org/wiki/Semaphore_(programming)
    waiter = Semaphore(n-1)

    # list of philsophers
    p = [Philosopher(i, u[i], u[(i+1) % n], waiter) for i in range(n)]

    for i in range(n):
        p[i].start()


if __name__ == "__main__":
    main()
