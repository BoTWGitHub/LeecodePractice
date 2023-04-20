'''
A trie (pronounced as "try") or prefix tree is a tree data structure used to efficiently store 
and retrieve keys in a dataset of strings. 
There are various applications of this data structure, such as autocomplete and spellchecker.

Implement the Trie class:

Trie() Initializes the trie object.
void insert(String word) Inserts the string word into the trie.
boolean search(String word) Returns true if the string word is in the trie (i.e., was inserted before), and false otherwise.
boolean startsWith(String prefix) Returns true if there is a previously inserted string word that has the prefix prefix, and false otherwise.
'''

class Trie:

    def __init__(self):
        self._root = self._node()

    def insert(self, word: str) -> None:
        cur = self._root
        for c in word:
            if c not in cur.children:
                cur.children[c] = self._node()
            cur = cur.children[c]
        cur.isWord = True

    def search(self, word: str) -> bool:
        cur = self._root
        for c in word:
            if c not in cur.children:
                return False
            cur = cur.children[c]
        return cur.isWord

    def startsWith(self, prefix: str) -> bool:
        cur = self._root
        for c in prefix:
            if c not in cur.children:
                return False
            cur = cur.children[c]
        return True 

    class _node:
        def __init__(self, isWord:bool = False):
            self.isWord = isWord
            self.children = dict()

def main():
    t = Trie()
    t.insert('apple')
    print(t.search('apple'))
    print(t.search('app'))
    print(t.startsWith('app'))
    t.insert('app')
    print(t.search('app'))

if __name__=='__main__':
    main()
