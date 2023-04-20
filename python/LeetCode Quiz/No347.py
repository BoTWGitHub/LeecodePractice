'''
Given an integer array nums and an integer k, return the k most frequent elements. 
You may return the answer in any order.
'''
from typing import List

class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        count = dict()
        for num in nums:
            if num not in count:
                count[num]=1
            else:
                count[num]+=1
        temp = sorted(count, key=lambda k:count[k], reverse=True)
        return temp[:k]
        

def main():
    solution = Solution()
    nums = [1,1,1,2,2,3]
    k = 2
    print(solution.topKFrequent(nums, k))

if __name__=='__main__':
    main()
