'''
Given two integers n and k, return all possible combinations of k numbers chosen from the range [1, n].

You may return the answer in any order.
'''
from typing import List

class Solution:
    def combine(self, n: int, k: int) -> List[List[int]]:
        def backtrack(step=1, temp = []):
            if len(temp)==k:
                res.append(temp.copy())
                return
            for i in range(step, n+1):
                temp.append(i)
                backtrack(i+1, temp)
                temp.pop()
        
        res = []
        backtrack()
        return res

def main():
    solution = Solution()

    n = 4
    k = 2
    print(solution.combine(n, k))

if __name__=='__main__':
    main()
