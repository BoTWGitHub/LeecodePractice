'''
You are given an m x n integer matrix points (0-indexed). Starting with 0 points, you want to maximize the number of points you can get from the matrix.

To gain points, you must pick one cell in each row. Picking the cell at coordinates (r, c) will add points[r][c] to your score.

However, you will lose points if you pick a cell too far from the cell that you picked in the previous row. For every two adjacent rows r and r + 1 (where 0 <= r < m - 1), picking cells at coordinates (r, c1) and (r + 1, c2) will subtract abs(c1 - c2) from your score.

Return the maximum number of points you can achieve.
'''

from typing import List

class Solution:
    def maxPoints(self, points: List[List[int]]) -> int:
        rows = len(points)
        cols = len(points[0])
        dp = points[0].copy()
        left = [0]*cols
        right = [0]*cols
        print(dp)
        for i in range(1, rows):
            for j in range(cols):
                if j==0:
                    left[j] = dp[j]
                else:
                    left[j] = max(left[j-1]-1, dp[j])
            for j in range(cols-1, -1, -1):
                if j==cols-1:
                    right[j] = dp[j]
                else:
                    right[j] = max(right[j+1]-1, dp[j])
            for j in range(cols):
                dp[j] = max(left[j], right[j])+points[i][j]
            
            print('row: [', i, ']')
            print('left:  ', left)
            print('right: ', right)
            print('dp:    ', dp)
            print()
                    
        return max(dp)
        
solution = Solution()
#points = [[1,2,3],[1,5,1],[3,1,1]]
points = [[5,2,1,2],[2,1,5,2],[5,5,5,0]]
print(solution.maxPoints(points))