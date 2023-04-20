'''
Design a HashMap without using any built-in hash table libraries.

Implement the MyHashMap class:

MyHashMap() initializes the object with an empty map.
void put(int key, int value) inserts a (key, value) pair into the HashMap. If the key already exists in the map, update the corresponding value.
int get(int key) returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key.
void remove(key) removes the key and its corresponding value if the map contains the mapping for the key.
'''

class MyHashMap:

    def __init__(self):
        self._hash_size = 1000
        self._buckets = [None] * self._hash_size

    def put(self, key: int, value: int) -> None:
        node = self._find(key)
        if node:
            node.val = value
        else:
            index = self._hash_function(key)
            if not self._buckets[index]:
                self._buckets[index] = self._list_node(key, value)
            else:
                node = self._buckets[index]
                while node.next:
                    node = node.next
                node.next = self._list_node(key, value)

    def get(self, key: int) -> int:
        node = self._find(key)
        if node:
            return node.val
        else:
            return -1

    def remove(self, key: int) -> None:
        index = self._hash_function(key)
        if not self._buckets[index]:
            return
        else:
            if self._buckets[index].key == key:
                self._buckets[index] = self._buckets[index].next
            else:
                node = self._buckets[index]
                while node.next:
                    if node.next.key == key:
                        node.next = node.next.next
                        return
                    node = node.next

    def _find(self, key: int):
        index = self._hash_function(key)
        if not self._buckets[index]:
            return None
        else:
            node = self._buckets[index]
            while node:
                if node.key == key:
                    return node
                node = node.next
        return None

    def _hash_function(self, key: int) -> int:
        return key%self._hash_size

    class _list_node:
        def __init__(self, key, val, next = None):
            self.key = key
            self.val = val
            self.next = next

def main():
    temp = MyHashMap()
    print(temp.get(8))
    temp.put(8, 220)
    print(temp.get(8))
    temp.put(1008, 110)
    print(temp.get(1008))
    temp.remove(8)
    print(temp.get(8))
    print(temp.get(1008))

if __name__=='__main__':
    main()
