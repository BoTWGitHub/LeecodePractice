from typing import List

class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        """
        Do not return anything, modify nums1 in-place instead.
        """
        index = 0
        while index < n:
            nums1[nums1.index(0)] = nums2[index]
            index+=1

        print(nums1)

solution = Solution()
solution.merge([1,2,3,0,0,0], 3, [2,5,6], 3)