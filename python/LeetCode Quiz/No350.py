from typing import List

class Solution:
    def intersect(self, nums1: List[int], nums2: List[int]) -> List[int]:
        res = []
        temp1 = {}
        for num in nums1:
            if num in temp1:
                temp1[num]+=1
            else:
                temp1[num]=1
        temp2 = {}
        for num in nums2:
            if num in temp2:
                temp2[num]+=1
            else:
                temp2[num]=1
        
        for num in temp1:
            if num in temp2:
                res += [num]*min(temp1[num], temp2[num])
        
        return res

solution = Solution()
print(solution.intersect([1,2,2,1], [2,2]))