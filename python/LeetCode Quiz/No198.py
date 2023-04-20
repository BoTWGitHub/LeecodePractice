'''
You are a professional robber planning to rob houses along a street. 
Each house has a certain amount of money stashed
, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected
 and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house
, return the maximum amount of money you can rob tonight without alerting the police.
'''
from typing import List

class Solution:
    def rob(self, nums: List[int]) -> int:
        mem = dict()
        def robTheHouse(i: int) -> int:
            if i==0:
                return nums[i]
            if i==1:
                return max(nums[i-1], nums[i])
            if i not in mem:
                mem[i] = max(robTheHouse(i-2)+nums[i], robTheHouse(i-1))
            return mem[i]
        return robTheHouse(len(nums)-1)

    def rob2(self, nums: List[int]) -> int:
        temp = [nums[0], max(nums[0], nums[1])]
        for i in range(2, len(nums)):
            temp.append(max(temp[i-2]+nums[i], temp[i-1]))
        return temp[-1]

solution = Solution()
nums = [2,7,9,3,1]
print(solution.rob2(nums))