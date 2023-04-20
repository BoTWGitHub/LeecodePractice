'''
You are given an integer array nums. 
You want to maximize the number of points you get by performing the following operation any number of times:

Pick any nums[i] and delete it to earn nums[i] points. 
Afterwards, you must delete every element equal to nums[i] - 1 and every element equal to nums[i] + 1.
Return the maximum number of points you can earn by applying the above operation some number of times.
'''
from typing import List

class Solution:
    def deleteAndEarn(self, nums: List[int]) -> int:
        nums.sort()
        count = dict()
        for num in nums:
            if num in count:
                count[num]+=1
            else:
                count[num]=1
        res = [0]*len(count)

solution = Solution()
nums = [3,4,2]
print(solution.deleteAndEarn(nums))