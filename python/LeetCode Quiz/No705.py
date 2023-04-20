'''
Design a HashSet without using any built-in hash table libraries.

Implement MyHashSet class:

void add(key) Inserts the value key into the HashSet.
bool contains(key) Returns whether the value key exists in the HashSet or not.
void remove(key) Removes the value key in the HashSet. If key does not exist in the HashSet, do nothing.
'''

class MyHashSet:
    def __init__(self):
        self._hash_size = 1000
        self.buckets = [None]*self._hash_size

    def add(self, key: int) -> None:
        if self.contains(key):
            return
        index = self._hash_function(key)
        if not self.buckets[index]:
            self.buckets[index] = self._list_node(key)
        else:
            node = self.buckets[index]
            while node.next:
                node = node.next
            node.next = self._list_node(key)

    def remove(self, key: int) -> None:
        if not self.contains(key):
            return
        index = self._hash_function(key)
        if self.buckets[index].val == key:
            self.buckets[index] = self.buckets[index].next
        else:
            node = self.buckets[index]
            while node.next.val != key:
                node = node.next
            node.next = node.next.next    

    def contains(self, key: int) -> bool:
        index = self._hash_function(key)
        if not self.buckets[index]:
            return False
        else:
            node = self.buckets[index]
            while node:
                if node.val == key:
                    return True
                node = node.next
        return False

    def _hash_function(self, key: int) -> int:
        return key%self._hash_size

    class _list_node:
        def __init__(self, val, next = None) -> None:
            self.val = val
            self.next = next

def main():
    temp = MyHashSet()
    print(temp.contains(2))
    temp.add(2)
    print(temp.contains(2))
    temp.remove(2)
    print(temp.contains(2))

if __name__=='__main__':
    main()
