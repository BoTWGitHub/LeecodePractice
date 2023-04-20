from typing import List

class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        if len(nums) <= 1:
            return
        
        k = k%len(nums)
        def reverseList(left, right):
            while left<right:
                nums[left], nums[right] = nums[right], nums[left]
                left+=1
                right-=1

        reverseList(0, len(nums)-1)
        reverseList(0, k-1)
        reverseList(k, len(nums)-1)

solution = Solution()
nums = [-1]
k = 2
solution.rotate(nums, k)
print(nums)