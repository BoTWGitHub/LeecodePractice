'''
Given a sorted integer array arr, two integers k and x
, return the k closest integers to x in the array. 
The result should also be sorted in ascending order.

An integer a is closer to x than an integer b if:

|a - x| < |b - x|, or
|a - x| == |b - x| and a < b
'''
from typing import List

class Solution:
    def findClosestElements(self, arr: List[int], k: int, x: int) -> List[int]:
        left, right = 0, len(arr)-k
        while left<right:
            mid=(left+right)//2
            if x-arr[mid]>arr[mid+k]-x:
                left=mid+1
            else:
                right=mid
        return arr[left:left+k]

def main():
    solution = Solution()

    arr = [1,3]
    k = 1
    x = 2
    print(solution.findClosestElements(arr, k, x))

if __name__=='__main__':
    main()
