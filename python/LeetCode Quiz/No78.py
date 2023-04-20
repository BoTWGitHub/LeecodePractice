'''
Given an integer array nums of unique elements
, return all possible subsets (the power set).

The solution set must not contain duplicate subsets. 
Return the solution in any order.
'''
from typing import List

class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        res = [[]]
        for num in nums:
            res += [r+[num] for r in res]
        return res
    
    def subsets2(self, nums: List[int]) -> List[List[int]]: #backtrack
        def backtrack(step:int = 0, mem: List[int] = []):
            if len(mem)==length:
                res.append(mem.copy())
                return
            for i in range(step, len(nums)):
                mem.append(nums[i])
                backtrack(i+1, mem)
                mem.pop()

        res = []
        for length in range(len(nums)+1):
            backtrack()
        return res

    def subsets3(self, nums: List[int]) -> List[List[int]]: #backtrack
        def backtrack(step:int = 0, mem: List[int] = []):
            res.append(mem.copy())
            for i in range(step, len(nums)):
                mem.append(nums[i])
                backtrack(i+1, mem)
                mem.pop()

        res = []
        backtrack()
        return res

def main():
    solution = Solution()

    nums = [1,2,3]
    print(solution.subsets(nums))
    print(solution.subsets2(nums))
    print(solution.subsets3(nums))

if __name__=='__main__':
    main()
