'''
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
'''
from typing import List

class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        def backtrack(left=n, right=n, count=0, temp=''):
            if len(temp)==n*2:
                res.append(temp)
            if count==0 and left>0:
                temp+='('
                backtrack(left-1, right, count+1, temp)
                temp = temp[:-1]
            else:
                if left>0:
                    temp+='('
                    backtrack(left-1, right, count+1, temp)
                    temp = temp[:-1]
                if right>0:
                    temp+=')'
                    backtrack(left, right-1, count-1, temp)
                    temp = temp[:-1]
        res = []
        backtrack()
        return res
        
def main():
    solution = Solution()

    n=3
    print(solution.generateParenthesis(n))

if __name__=='__main__':
    main()
