'''
You are given an m x n binary matrix grid.

In one operation, you can choose any row or column and flip each value in that row or column 
(i.e., changing all 0's to 1's, and all 1's to 0's).

Return true if it is possible to remove all 1's from grid using any number of operations or false otherwise.
'''
from typing import List

class Solution:
    def removeOnes(self, grid: List[List[int]]) -> bool:
        rows, cols = len(grid), len(grid[0])
        if rows < 2 or cols < 2:
            return True
            
        for i in range(rows-1):
            for j in range(cols-1):
                count = grid[i][j] + grid[i+1][j] + grid[i][j+1] + grid[i+1][j+1]
                if count == 1 or count == 3:
                    return False
        
        return True

solution = Solution()
grid = [[1,1,0],[0,0,0],[0,0,0]]
print(solution.removeOnes(grid))