from typing import List

class Search:
    def LinearSearch(self, nums: List[int], target: int) -> int:
        for i, num in enumerate(nums):
            if num >= target:
                return i
    
    def BinarySearch(self, nums: List[int], target: int) -> int: 
        left, right = 0, len(nums)-1
        while left<right:
            mid = (left+right)//2
            print(left, mid, right, nums[mid], target)
            if nums[mid]<target:
                left = mid+1
            else:
                right = mid-1
        return left-1


search = Search()
nums = [1,1,2,5,8,9,10,12,15,18,32,33,35,35,36,37,37,39,42,44]
target = 40
#nums = [0, 2]
#target = 1
#print(search.LinearSearch(nums, target))
index = search.BinarySearch(nums, target)
print(nums[index])