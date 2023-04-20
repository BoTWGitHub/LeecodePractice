'''
There is a robot on an m x n grid. 
The robot is initially located at the top-left corner (i.e., grid[0][0]). 
The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). 
The robot can only move either down or right at any point in time.

Given the two integers m and n, return the number of possible unique paths that the robot can take to reach the bottom-right corner.

The test cases are generated so that the answer will be less than or equal to 2 * 10^9.
'''

class Solution:
    def uniquePaths(self, m: int, n: int) -> int: #top-down
        mem = {}
        def dp(x: int, y: int) -> int:
            if x==0 or y==0:
                return 1
            if (x, y) not in mem:
                mem[(x, y)] = dp(x-1, y) + dp(x, y-1)
            return mem[(x, y)]
        return dp(m-1, n-1)

    def uniquePaths2(self, m: int, n: int) -> int: #bottom-up
        dp = [[0]*(n) for _ in range(m)]
        for i in range(m):
            for j in range(n):
                if i==0 or j==0:
                    dp[i][j] = 1
                else:
                    dp[i][j] = dp[i-1][j] + dp[i][j-1]
        return dp[-1][-1]


solution = Solution()
m, n = 3, 7
print(solution.uniquePaths(m, n))