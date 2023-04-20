from typing import List

class Solution:
    def sortArrayByParityII(self, nums: List[int]) -> List[int]:
        odd = 0
        even = 1
        while odd<len(nums) and even<len(nums):
            if nums[odd]%2==0:
                odd+=2
                continue
            if nums[even]%2==1:
                even+=2
                continue
            nums[odd], nums[even] = nums[even], nums[odd]

        return nums

solution = Solution()
#nums = [4, 2, 5, 7]
nums = [2, 3]
print(solution.sortArrayByParityII(nums))