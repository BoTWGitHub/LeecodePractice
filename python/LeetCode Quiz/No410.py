'''
Given an array nums which consists of non-negative integers and an integer m
, you can split the array into m non-empty continuous subarrays.

Write an algorithm to minimize the largest sum among these m subarrays.
'''
from typing import List

class Solution:
    def splitArray(self, nums: List[int], m: int) -> int:
        def split(maxSum: int) -> int:
            res = 0
            tempSum = 0
            for num in nums:
                if tempSum+num<=maxSum:
                    tempSum+=num
                else:
                    tempSum = num
                    res+=1

            return res+1
                
        left, right = max(nums), sum(nums)
        minRes = right
        while left<right:
            mid = (left+right)//2
            if split(mid)<=m:
                minRes=mid
                right=mid
            else:
                left=mid+1
        return minRes

def main():
    solution = Solution()

    nums = [1,4,4]
    m = 3
    print(solution.splitArray(nums, m))

if __name__=='__main__':
    main()
