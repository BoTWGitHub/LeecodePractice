'''
Given a binary array nums
, return the maximum number of consecutive 1's in the array if you can flip at most one 0.
'''
from typing import List

class Solution:
    def findMaxConsecutiveOnes(self, nums: List[int]) -> int:
        if len(nums)==1:
            return 1
        temp = [nums[0]]
        for i in range(1, len(nums)):
            if nums[i] == 1:
                if temp[-1]>0:
                    temp[-1]+=1
                else:
                    temp.append(1)
            else:
                temp.append(0)

        if len(temp)==1:
            return temp[0]
        res = 0
        for i, val in enumerate(temp):
            if val == 0:
                if i==0:
                    res = max(res, temp[1]+1)
                elif i==len(temp)-1:
                    res = max(res, temp[-2]+1)
                else:
                    res = max(res, temp[i-1] + temp[i+1] + 1)
        return res


def main():
    nums = [1,1]
    print(Solution.findMaxConsecutiveOnes(Solution(), nums))

if __name__=='__main__':
    main()