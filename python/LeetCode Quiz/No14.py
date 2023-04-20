'''
Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".
'''
from typing import List

class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        res = ''
        min_len = 200
        for str in strs:
            min_len = min(min_len, len(str))

        for i in range(min_len):
            comp=strs[0][i]
            for str in strs:
                if str[i]!=comp:
                    return res
            res+=comp
        return res

def main():
    strs = ["flower","flow","flight"]
    print(Solution.longestCommonPrefix(Solution(), strs))

if __name__=='__main__':
    main()
