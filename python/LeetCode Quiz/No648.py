'''
In English, we have a concept called root
, which can be followed by some other word to form another longer word - let's call this word successor. 
For example, when the root "an" is followed by the successor word "other", we can form a new word "another".

Given a dictionary consisting of many roots and a sentence consisting of words separated by spaces
, replace all the successors in the sentence with the root forming it. 
If a successor can be replaced by more than one root, replace it with the root that has the shortest length.

Return the sentence after the replacement.
'''
from typing import List

class Trie:
    def __init__(self):
        self._root = self._node()
    
    def insert(self, word: str):
        cur = self._root
        for c in word:
            if c not in cur.children:
                cur.children[c] = self._node()
            cur = cur.children[c]
        cur.isWord = True

    def search(self, word: str) -> str:
        cur = self._root
        res = ''
        for c in word:
            if c not in cur.children:
                return word
            cur = cur.children[c]
            res+=c
            if cur.isWord:
                return res
        return res

    class _node:
        def __init__(self, isWord: bool = False):
            self.isWord = isWord
            self.children = dict()

class Solution:
    def replaceWords(self, dictionary: List[str], sentence: str) -> str:
        trie = Trie()
        for word in dictionary:
            trie.insert(word)
        
        left, right = 0, 0
        res = ''
        while left<len(sentence):
            while right<len(sentence) and sentence[right]!=' ':
                right+=1
            res = res + trie.search(sentence[left:right]) + ' '
            right+=1
            left = right
        return res[:-1]

def main():
    solution = Solution()

    dictionary = ["cat","bat","rat"]
    sentence = "the cattle was rattled by the battery"
    print(solution.replaceWords(dictionary, sentence))

if __name__=='__main__':
    main()

