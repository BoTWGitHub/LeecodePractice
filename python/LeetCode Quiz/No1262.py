from typing import List

class Solution:
    def maxSumDivThree(self, nums: List[int]) -> int:
        dp = [0]*3
        for num in nums:
            temp = dp.copy()
            for i in temp:
                dp[(i+num)%3] = max(dp[(i+num)%3], i+num)
        return dp[0]

solution = Solution()
print(solution.maxSumDivThree([3,6,5,1,8]))