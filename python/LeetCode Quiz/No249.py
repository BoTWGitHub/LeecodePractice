'''
We can shift a string by shifting each of its letters to its successive letter.

For example, "abc" can be shifted to be "bcd".
We can keep shifting the string to form a sequence.

For example, we can keep shifting "abc" to form the sequence: "abc" -> "bcd" -> ... -> "xyz".
Given an array of strings strings, group all strings[i] that belong to the same shifting sequence. 
You may return the answer in any order.
'''
from typing import List

class Solution:
    def groupStrings(self, strings: List[str]) -> List[List[str]]:
        mem = dict()
        index = 0
        res = []
        def shiftToA(s: str) -> str:
            first_ord = ord(s[0])
            temp = ''
            for c in s:
                temp_ord = ord(c) - first_ord
                if temp_ord >= 0:
                    temp += chr(temp_ord+97)
                else:
                    temp += chr(temp_ord+123)
            return temp
            
        for s in strings:
            key = shiftToA(s)
            if key not in mem:
                mem[key] = index
                index+=1
                res.append([s])
            else:
                res[mem[key]].append(s)
        
        return res


def main():
    strings = ["abc","bcd","acef","xyz","az","ba","a","z"]
    print(Solution.groupStrings(Solution(), strings))

if __name__=='__main__':
    main()
