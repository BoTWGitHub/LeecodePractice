'''
Given an array arr
, replace every element in that array with the greatest element among the elements to its right
, and replace the last element with -1.

After doing so, return the array.
'''
from typing import List

class Solution:
    def replaceElements(self, arr: List[int]) -> List[int]:
        i = len(arr)-2
        temp = arr[-1]
        while i>-1:
            if arr[i]>temp:
                temp2 = arr[i]
                arr[i] = temp
                temp = temp2
            else:
                arr[i] = temp
            i-=1
        arr[-1] = -1
        return arr

arr = [56903,18666,60499,57517,26961]
print(Solution.replaceElements(Solution(), arr))