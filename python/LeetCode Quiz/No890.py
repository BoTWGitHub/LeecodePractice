'''
Given a list of strings words and a string pattern, return a list of words[i] that match pattern. 
You may return the answer in any order.

A word matches the pattern if there exists a permutation of letters p so that after replacing every letter x in the pattern with p(x), we get the desired word.

Recall that a permutation of letters is a bijection from letters to letters: every letter maps to another letter, and no two letters map to the same letter.
'''
from typing import List

class Solution:
    def findAndReplacePattern(self, words: List[str], pattern: str) -> List[str]:
        def encoder(word: str) -> str:
            p = dict()
            i = 0
            enc_str = ''
            for c in word:
                if c not in p:
                    p[c] = i
                    i+=1
                enc_str+=str(p[c])
            return enc_str

        enc_pattern = encoder(pattern)
        res = []
        for word in words:
            if encoder(word)==enc_pattern:
                res.append(word)
        return res

solution = Solution()
words = ["abc","deq","mee","aqq","dkd","ccc"]
pattern = 'abb'
print(solution.findAndReplacePattern(words, pattern))