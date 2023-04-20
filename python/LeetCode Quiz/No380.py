'''
Implement the RandomizedSet class:

RandomizedSet() Initializes the RandomizedSet object.

bool insert(int val) Inserts an item val into the set if not present. 
Returns true if the item was not present, false otherwise.

bool remove(int val) Removes an item val from the set if present. 
Returns true if the item was present, false otherwise.

int getRandom() Returns a random element from the current set of elements 
(it's guaranteed that at least one element exists when this method is called). 
Each element must have the same probability of being returned.

You must implement the functions of the class such that each function works in average O(1) time complexity.
'''
from typing import List
import random

class RandomizedSet:

    def __init__(self):
        self._map = dict()
        self._arr = []

    def insert(self, val: int) -> bool:
        if val not in self._map:
            self._map[val] = len(self._arr)
            self._arr.append(val)
            return True
        return False

    def remove(self, val: int) -> bool:
        if val in self._map:
            index = self._map[val]
            self._map[self._arr[-1]] = index
            self._arr[index] = self._arr[-1]
            self._arr.pop()
            del self._map[val]
            return True
        return False

    def getRandom(self) -> int:
        return self._arr[random.randint(0, len(self._arr)-1)]

def main():
    temp = RandomizedSet()
    print(temp.insert(1))
    print(temp.remove(1))
    print(temp.insert(2))
    print(temp.getRandom())
    print(temp.remove(1))
    print(temp.insert(2))
    print(temp.getRandom())

if __name__=='__main__':
    main()
