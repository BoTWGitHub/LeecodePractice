from typing import List

class Solution:
    def countKDifference(self, nums: List[int], k: int) -> int:
        count = 0
        for i in range(len(nums)-1):
            for j in range(i, len(nums)):
                if abs(nums[i] - nums[j]) == k:
                    count+=1
        return count

    def countKDifference2(self, nums: List[int], k: int) -> int:
        count = 0
        
        hash = {}
        
        for i in nums:
            if i in hash:
                hash[i] +=1
            else:
                hash[i] = 1
                
        print(hash)
        for i in hash:
            print(i)
            if i+k in hash:
                count+=hash[i]*hash[i+k]
                
        return count
    
solution = Solution()
print(solution.countKDifference2([3,2,1,5,4], 2))