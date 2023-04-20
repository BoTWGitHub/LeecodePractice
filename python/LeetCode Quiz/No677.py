'''
Design a map that allows you to do the following:

Maps a string key to a given value.
Returns the sum of the values that have a key with a prefix equal to a given string.
Implement the MapSum class:

MapSum() Initializes the MapSum object.
void insert(String key, int val) Inserts the key-val pair into the map. If the key already existed
, the original key-value pair will be overridden to the new one.
int sum(string prefix) Returns the sum of all the pairs' value whose key starts with the prefix.
'''
class MapSum:

    def __init__(self):
        self._mem = dict()
        self._root = self._node()

    def insert(self, key: str, val: int) -> None:
        cur = self._root
        if key not in self._mem:
            self._mem[key] = val
            for c in key:
                if c not in cur.children:
                    cur.children[c] = self._node()
                cur = cur.children[c]
                cur.val += val
        else:
            delta = val - self._mem[key]
            self._mem[key] = val
            for c in key:
                if c not in cur.children:
                    cur.children[c] = self._node()
                cur = cur.children[c]
                cur.val += delta

    def sum(self, prefix: str) -> int:
        cur = self._root
        for c in prefix:
            if c not in cur.children:
                return 0
            cur = cur.children[c]

        return cur.val

    class _node:
        def __init__(self, val: int = 0):
            self.val = val
            self.children = dict()

def main():
    m = MapSum()
    m.insert('apple', 3)
    print(m.sum('ap'))
    m.insert('app', 2)
    print(m.sum('ap'))
    m.insert('apple', 5)
    print(m.sum('ap'))

if __name__=='__main__':
    main()
