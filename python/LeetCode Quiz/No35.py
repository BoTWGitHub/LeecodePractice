from typing import List

class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        left = 0
        right = len(nums)-1

        while right-left > 1:
            index = (right+left)//2
            print(left, index, right)
            if nums[index] == target:
                return index
            elif nums[index] > target:
                right = index-1
            else:
                left = index+1

        print(left, right)
        if nums[left]>=target:
            return left
        elif nums[right]<target:
            return right+1

        return right

solution = Solution()
nums = [1,3,5,6]
target = 7
print(solution.searchInsert(nums, target))