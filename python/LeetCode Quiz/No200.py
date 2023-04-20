'''
Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. 
You may assume all four edges of the grid are all surrounded by water.
'''

from typing import List

class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        dirs = [[1, 0], [0, 1], [-1, 0], [0, -1]]
        rows, cols = len(grid), len(grid[0])
        count = 0
        for x in range(rows):
            for y in range(cols):
                if grid[x][y] == "1":
                    count+=1
                    q = set()
                    q.add((x, y))
                    while q:
                        m, n = q.pop()
                        grid[m][n] = "0"
                        for dir in dirs:
                            newX, newY = m+dir[0], n+dir[1]
                            if newX>=0 and newX<rows and newY>=0 and newY<cols and grid[newX][newY]=="1":
                                q.add((newX, newY))
        
        return count

solution = Solution()
grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
print(solution.numIslands(grid))