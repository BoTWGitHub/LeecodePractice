'''
Given a string containing digits from 2-9 inclusive
, return all possible letter combinations that the number could represent. 
Return the answer in any order.

A mapping of digits to letters (just like on the telephone buttons) is given below. 
Note that 1 does not map to any letters.
'''
from typing import List

class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        def backtrack(step: int = 0, temp:str = ''):
            if step==len(digits):
                res.append(temp)
                return

            for c in map[digits[step]]:
                temp = temp+c
                backtrack(step+1, temp)
                temp = temp[:-1]
        
        map = {'2':'abc', '3':'def', '4':'ghi', '5':'jkl'
             , '6':'mno', '7':'pqrs', '8':'tuv', '9':'wxyz'}
        res = []
        if len(digits)>0:
            backtrack()
        return res

def main():
    solution = Solution()

    digits = '23'
    print(solution.letterCombinations(digits))

if __name__=='__main__':
    main()
