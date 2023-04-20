'''
There are n cities. 
Some of them are connected, while some are not. 
If city a is connected directly with city b
, and city b is connected directly with city c
, then city a is connected indirectly with city c.

A province is a group of directly or indirectly connected cities and no other cities outside of the group.

You are given an n x n matrix isConnected
 where isConnected[i][j] = 1 if the ith city and the jth city are directly connected
 , and isConnected[i][j] = 0 otherwise.

Return the total number of provinces.
'''

from typing import List

class Solution:
    def findCircleNum(self, isConnected: List[List[int]]) -> int:
        province = 0
        def dfs(conn: List[List[int]], index: int, seen: set, p: int) -> int:
            if index in seen:
                return p
            seen.add(index)
            p+=1
            for i, c in enumerate(conn[index]):
                if i==index or i in seen:
                    continue
                if c==1:
                    dfs(conn, i, seen, p)

            return p
        
        seen = set()
        for i in range(len(isConnected)):
            province = dfs(isConnected, i, seen, province)
        return province

solution = Solution()
isConnected = [[1,1,0],[1,1,0],[0,0,1]]
print(solution.findCircleNum(isConnected))
