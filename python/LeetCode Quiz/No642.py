'''
Design a search autocomplete system for a search engine. 
Users may input a sentence (at least one word and end with a special character '#').

You are given a string array sentences and an integer array times both of length n 
where sentences[i] is a previously typed sentence and times[i] is the corresponding number of times the sentence was typed. 
For each input character except '#', return the top 3 historical hot sentences that have the same prefix as the part of the sentence already typed.

Here are the specific rules:

The hot degree for a sentence is defined as the number of times a user typed the exactly same sentence before.
The returned top 3 hot sentences should be sorted by hot degree (The first is the hottest one). 
If several sentences have the same hot degree, use ASCII-code order (smaller one appears first).
If less than 3 hot sentences exist, return as many as you can.
When the input is a special character, it means the sentence ends, and in this case, you need to return an empty list.
Implement the AutocompleteSystem class:

AutocompleteSystem(String[] sentences, int[] times) Initializes the object with the sentences and times arrays.
List<String> input(char c) This indicates that the user typed the character c.
Returns an empty array [] if c == '#' and stores the inputted sentence in the system.
Returns the top 3 historical hot sentences that have the same prefix as the part of the sentence already typed. 
If there are fewer than 3 matches, return them all.
'''
from typing import List

class AutocompleteSystem:
    def __init__(self, sentences: List[str], times: List[int]):
        self.__root = self.__trie()
        for i, s in enumerate(sentences):
            self.__insert(s, times[i])
        self.__prefix = ''

    def input(self, c: str) -> List[str]:
        if c=='#':
            self.__insert(self.__prefix)
            self.__prefix = ''
            return []
        self.__prefix += c
        return self.__search()

    def __insert(self, sentence: str, times: int = 1):
        if not sentence:
            return
        cur = self.__root
        for c in sentence:
            if c not in cur.children:
                cur.children[c] = self.__trie()
            cur = cur.children[c]
        cur.times+=times

    def __search(self) -> List[str]:
        cur = self.__root
        for c in self.__prefix:
            if c not in cur.children:
                return []
            cur = cur.children[c]
        
        freq = dict()
        if cur.times>0:
            freq[cur.times] = [self.__prefix]
        q = []
        for c in cur.children:
            q.append([self.__prefix, c, cur.children[c]])
        while q:
            for _ in range(len(q)):
                prefix, char, node = q.pop(0)
                if node.times>0:
                    if node.times not in freq:
                        freq[node.times] = [prefix+char]
                    else:
                        freq[node.times].append(prefix+char)
                for child in node.children:
                    q.append([prefix+char, child, node.children[child]])
        
        count = sorted(freq, reverse = True)
        res = []
        for c in count:
            freq[c].sort()
            for s in freq[c]:
                res.append(s)
                if len(res)==3:
                    return res
        return res
    
    class __trie:
        def __init__(self, times: int = 0):
            self.times = times
            self.children = dict()

def main():
    a = AutocompleteSystem(["i love you", "island", "iroman", "i love leetcode"], [5, 3, 2, 2])
    print(a.input('i'))
    print(a.input(' '))
    print(a.input('a'))
    print(a.input('#'))
    print(a.input('i'))
    print(a.input(' '))

if __name__=='__main__':
    main()

