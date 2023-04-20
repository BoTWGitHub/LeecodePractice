from typing import List

class Solution:
    def matrixReshape(self, mat: List[List[int]], r: int, c: int) -> List[List[int]]:
        nums_of_data = len(mat) * len(mat[0])
        print(nums_of_data, r*c)
        if r*c != nums_of_data:
            return mat
        
        temp = []
        for row in mat:
            for num in row:
                temp.append(num)
        if r==1:
            return [temp]
        
        res = []
        for i in range(r):
            res += [[temp[x+i*c] for x in range(c)]]
        return res

solution = Solution()
mat = [[1,2],[3,4]]
r = 1
c = 4
print(solution.matrixReshape(mat, r, c))