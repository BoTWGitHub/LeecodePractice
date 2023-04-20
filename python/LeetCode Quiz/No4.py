'''
Given two sorted arrays nums1 and nums2 of size m and n respectively
, return the median of the two sorted arrays.

The overall run time complexity should be O(log (m+n)).
'''
from typing import List

class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        if len(nums1)>len(nums2):
            return self.findMedianSortedArrays(nums2, nums1)
        
        total = len(nums1)+len(nums2)
        half = total//2
        left, right = 0, len(nums1)-1
        while True:
            i = (left+right)//2
            j = half-i-2
            left1 = nums1[i] if i>=0 else float('-inf')
            left2 = nums2[j] if j>=0 else float('-inf')
            right1 = nums1[i+1] if i+1<len(nums1) else float('inf')
            right2 = nums2[j+1] if j+1<len(nums2) else float('inf')

            if left1 <= right2 and left2 <= right1:
                if total%2==1:
                    return min(right1, right2)
                else:
                    return (max(left1, left2)+min(right1, right2))/2
            elif left1>right2:
                right=i-1
            else:
                left=i+1

def main():
    solution = Solution()

    nums1 = [1,2]
    nums2 = [3,4,5,6,7,8]
    print(solution.findMedianSortedArrays(nums1, nums2))

if __name__=='__main__':
    main()
