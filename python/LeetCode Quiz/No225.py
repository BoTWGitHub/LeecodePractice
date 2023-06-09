'''
Implement a last-in-first-out (LIFO) stack using only two queues.
The implemented stack should support all the functions of a normal stack (push, top, pop, and empty).

Implement the MyStack class:

void push(int x) Pushes element x to the top of the stack.
int pop() Removes the element on the top of the stack and returns it.
int top() Returns the element on the top of the stack.
boolean empty() Returns true if the stack is empty, false otherwise.
Notes:

You must use only standard operations of a queue, which means that only push to back, peek/pop from front, size and is empty operations are valid.
Depending on your language, the queue may not be supported natively.
You may simulate a queue using a list or deque (double-ended queue) as long as you use only a queue's standard operations.
'''

import queue

class MyStack:

    def __init__(self):
        self.__q1 = queue.Queue()
        self.__q2 = queue.Queue()

    def push(self, x: int) -> None:
        self.__q2.put(x)
        while not self.__q1.empty():
            self.__q2.put(self.__q1.get())
        while not self.__q2.empty():
            self.__q1.put(self.__q2.get())

    def pop(self) -> int:
        return self.__q1.get()
        
    def top(self) -> int:
        return self.__q1.queue[0]

    def empty(self) -> bool:
        return self.__q1.empty()

stack = MyStack()
stack.push(3)