'''
Design a data structure that supports adding new words and finding if a string matches any previously added string.

Implement the WordDictionary class:

WordDictionary() Initializes the object.
void addWord(word) Adds word to the data structure, it can be matched later.
bool search(word) Returns true if there is any string in the data structure that matches word or false otherwise. 
word may contain dots '.' where dots can be matched with any letter.
'''

class WordDictionary:
    def __init__(self):
        self._root = self._trie_node()

    def addWord(self, word: str) -> None:
        cur = self._root
        for c in word:
            if c not in cur.children:
                cur.children[c] = self._trie_node()
            cur = cur.children[c]
        cur.isWord = True

    def search(self, word: str) -> bool:
        return self._searchByNode(self._root, word)

    def _searchByNode(self, node, word) -> bool:
        if len(word)==0:
            return node.isWord
        if word[0] == '.':
            for c in node.children:
                if self._searchByNode(node.children[c], word[1:]):
                    return True
            return False
        elif word[0] not in node.children:
            return False
        else:
            return self._searchByNode(node.children[word[0]], word[1:])

    class _trie_node:
        def __init__(self, isWord: bool = False):
            self.isWord = isWord
            self.children = dict()

def main():
    w = WordDictionary()
    w.addWord('bad')
    w.addWord('dad')
    w.addWord('mad')

    print(w.search('pad'))
    print(w.search('bad'))
    print(w.search('.ad'))
    print(w.search('b..'))

if __name__=='__main__':
    main()
