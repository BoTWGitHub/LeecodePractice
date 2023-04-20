'''
Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.

Implement the LRUCache class:

LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
int get(int key) Return the value of the key if the key exists, otherwise return -1.
void put(int key, int value) Update the value of the key if the key exists. 
Otherwise, add the key-value pair to the cache. 
If the number of keys exceeds the capacity from this operation, evict the least recently used key.
The functions get and put must each run in O(1) average time complexity.
'''

class LRUCache:
    def __init__(self, capacity: int):
        self.__size = 0
        self.__cap = capacity
        self.__map = dict()
        self.__head = self.__dlist()
        self.__tail = self.__dlist()
        self.__head.next = self.__tail
        self.__tail.prev = self.__head

    def get(self, key: int) -> int:
        if key not in self.__map:
            return -1
        else:
            self.__moveToFront(key)
            return self.__map[key].val

    def put(self, key: int, value: int) -> None:
        self.__checkKey(key, value)

    def __checkKey(self, key, val):
        if key not in self.__map:
            self.__insertNew(key, val)
        else:
            self.__map[key].val = val
            self.__moveToFront(key)

    def __insertNew(self, key, val):
        node = self.__dlist(key, val, self.__head.next, self.__head)
        self.__map[key] = node
        self.__head.next.prev = node
        self.__head.next = node
        self.__size+=1
        if self.__size>self.__cap:
            self.__removeLast()
    
    def __removeLast(self):
        node = self.__tail.prev
        key = node.key
        del self.__map[key]
        node.prev.next = self.__tail
        self.__tail.prev = node.prev
        self.__size-=1

    def __moveToFront(self, key):
        node = self.__map[key]
        node.next.prev = node.prev
        node.prev.next = node.next
        node.next = self.__head.next
        node.prev = self.__head
        self.__head.next.prev = node
        self.__head.next = node

    class __dlist:
        def __init__(self, key: int = 0, val: int = 0, next=None, prev=None):
            self.key = key
            self.val = val
            self.next = next
            self.prev = prev

def main():
    cache = LRUCache(2)
    cache.put(1, 1)
    cache.put(2, 2)
    cache.get(1)
    cache.put(3, 3)
    cache.get(2)
    cache.put(4, 4)
    cache.get(1)
    cache.get(3)
    cache.get(4)

if __name__=='__main__':
    main()

