'''
Given an array of strings strs, group the anagrams together. 
You can return the answer in any order.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase
, typically using all the original letters exactly once.
'''
from typing import List

class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        mem = dict()
        index = 0
        res = []
        for str in strs:
            temp = ''.join(sorted(str))
            if temp not in mem:
                mem[temp] = index
                index+=1
                res.append([str])
            else:
                res[mem[temp]].append(str)
        
        return res

def main():
    strs = ["eat","tea","tan","ate","nat","bat"]
    print(Solution.groupAnagrams(Solution(), strs))

if __name__=='__main__':
    main()
