'''
Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].

You must write an algorithm with O(log n) runtime complexity.
'''
from typing import List

class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        res = [-1, -1]
        left, right = 0, len(nums)-1
        while left<=right:
            mid=(left+right)//2
            if nums[mid]==target:
                if mid==left or nums[mid-1]<target:
                    res[0]=mid
                    break
                else:
                    right=mid-1
            elif nums[mid]>target:
                right=mid-1
            else:
                left=mid+1
        if res[0]==-1:
            return res
        
        left, right = 0, len(nums)-1
        while left<=right:
            mid=(left+right)//2
            if nums[mid]==target:
                if mid==right or nums[mid+1]>target:
                    res[1]=mid
                    break
                else:
                    left=mid+1
            elif nums[mid]>target:
                right=mid-1
            else:
                left=mid+1

        return res

def main():
    solution = Solution()

    nums = [5,7,7,8,8,10]
    target = 8
    print(solution.searchRange(nums, target))

if __name__=='__main__':
    main()
