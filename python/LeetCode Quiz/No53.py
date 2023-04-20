from typing import List

class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        #kadane's algorithm
        max_sum = temp_sum = nums[0]
        for i in range(1, len(nums)):
            temp_sum = max(temp_sum + nums[i], nums[i])
            max_sum = max(max_sum, temp_sum)
        return max_sum

input = [-2,1,-3,4,-1,2,1,-5,4]
solution = Solution()
print(solution.maxSubArray(input))