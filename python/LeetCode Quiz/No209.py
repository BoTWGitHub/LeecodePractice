'''
Given an array of positive integers nums and a positive integer target
, return the minimal length of a contiguous subarray [numsl, numsl+1, ..., numsr-1, numsr]
 of which the sum is greater than or equal to target. 
 
 If there is no such subarray, return 0 instead.
'''
from typing import List

class Solution:
    def minSubArrayLen(self, target: int, nums: List[int]) -> int:
        temp_sum = 0
        left = 0
        res = 100001
        for i, val in enumerate(nums):
            temp_sum+=val
            while temp_sum>target:
                temp_sum-=nums[left]
                res = min(res, i-left+1)
                left+=1
        return res if res<100001 else 0

def main():
    target = 11
    nums = [1,1,3,4,5]
    print(Solution.minSubArrayLen(Solution(), target, nums))

if __name__=='__main__':
    main()
