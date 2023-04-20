from typing import List

class Solution:
    def sortedSquares(self, nums: List[int]) -> List[int]:
        res = []
        left = 0
        right = len(nums)-1
        
        while left<=right:
            if abs(nums[left]) > abs(nums[right]):
                res+=[nums[left]**2]
                left+=1
            else:
                res+=[nums[right]**2]
                right-=1

        return res[::-1]

solution = Solution()
nums = [-4,-1,0,3,10]
print(solution.sortedSquares(nums))