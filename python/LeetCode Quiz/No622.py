'''
Design your implementation of the circular queue.
The circular queue is a linear data structure in which 
the operations are performed based on FIFO (First In First Out) principle 
and the last position is connected back to the first position to make a circle. 
It is also called "Ring Buffer".

One of the benefits of the circular queue is that we can make use of the spaces in front of the queue. 
In a normal queue, once the queue becomes full, we cannot insert the next element 
even if there is a space in front of the queue. 
But using the circular queue, we can use the space to store new values.
'''

class MyCircularQueue:

    def __init__(self, k: int):
        self.__nums = [0]*k
        self.__tail = -1
        self.__head = -1
        

    def enQueue(self, value: int) -> bool:
        if self.isFull():
            return False
        if self.isEmpty():
            self.__head = 0

        self.__tail = (self.__tail+1)%len(self.__nums)
        self.__nums[self.__tail] = value
        return True
        

    def deQueue(self) -> bool:
        if self.isEmpty():
            return False
        if self.__head == self.__tail:
            self.__head = -1
            self.__tail = -1
            return True
        self.__head = (self.__head+1)%len(self.__nums)
        return True

    def Front(self) -> int:
        if self.isEmpty():
            return -1
        return self.__nums[self.__head]
        

    def Rear(self) -> int:
        if self.isEmpty():
            return -1
        return self.__nums[self.__tail]
        

    def isEmpty(self) -> bool:
        return self.__head==-1
        

    def isFull(self) -> bool:
        return (self.__tail+1)%len(self.__nums)==self.__head

q = MyCircularQueue(6)
print(q.enQueue(6))
print(q.Rear())
print(q.Rear())
print(q.deQueue())
print(q.enQueue(5))
print(q.Rear())
print(q.deQueue())
print(q.Front())
print(q.deQueue())
print(q.deQueue())
print(q.deQueue())