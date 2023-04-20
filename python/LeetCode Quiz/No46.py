'''
Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.
'''
from typing import List

class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        def p(nums: List[int], res: List[List[int]], step: int = 0):
            if step==len(nums):
                res.append(nums)
                return
            for i in range(step, len(nums)):
                tempNums = nums.copy()
                tempNums[i], tempNums[step] = tempNums[step], tempNums[i]
                p(tempNums, res, step+1)
        res = []
        p(nums, res)
        return res

def main():
    solution = Solution()
    nums = [1,2,3]
    print(solution.permute(nums))

if __name__=='__main__':
    main()