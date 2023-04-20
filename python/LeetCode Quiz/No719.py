'''
The distance of a pair of integers a and b is defined as the absolute difference between a and b.

Given an integer array nums and an integer k
, return the kth smallest distance among all the pairs nums[i] and nums[j] where 0 <= i < j < nums.length.
'''
from typing import List

class Solution:
    def smallestDistancePair(self, nums: List[int], k: int) -> int:
        def guess(dis: int) -> bool:
            p1, p2=0, 1
            count=0
            while p1<len(nums)-1:
                while p2<len(nums) and nums[p2]-nums[p1]<=dis:
                    p2+=1
                p1+=1
                count+=(p2-p1)
            return count>=k
        
        nums.sort()
        left, right = 0, nums[-1]-nums[0]
        while left<right:
            mid=(left+right)//2
            if guess(mid):
                right=mid
            else:
                left=mid+1
        return left

def main():
    solution = Solution()

    nums=[62,100,4]
    k=2
    print(solution.smallestDistancePair(nums, k))

if __name__=='__main__':
    main()
