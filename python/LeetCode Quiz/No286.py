'''
You are given an m x n grid rooms initialized with these three possible values.

    -1 A wall or an obstacle.
     0 A gate.
    INF Infinity means an empty room. We use the value 231 - 1 = 2147483647 to represent INF as you may assume that the distance to a gate is less than 2147483647.

Fill each empty room with the distance to its nearest gate. If it is impossible to reach a gate, it should be filled with INF.
'''

from typing import List

class Solution:
    def wallsAndGates(self, rooms: List[List[int]]) -> None:
        """
        Do not return anything, modify rooms in-place instead.
        """
        dirs = [[1, 0], [0, 1], [-1, 0], [0, -1]]
        rows, cols = len(rooms), len(rooms[0])
        gates = []
        for r in range(rows):
            for c in range(cols):
                if rooms[r][c] == 0:
                    gates.append([r, c])

        while len(gates)>0:
            gate = gates.pop(0)
            q = [gate]
            step = 1
            while len(q)>0:
                for i in range(len(q)):
                    x, y = q.pop(0)
                    for dir in dirs:
                        new_x, new_y = x+dir[0], y+dir[1]
                        if new_x>=0 and new_x<rows and new_y>=0 and new_y<cols:
                            if rooms[new_x][new_y]!=0 and rooms[new_x][new_y]!=-1 and rooms[new_x][new_y]>step:
                                rooms[new_x][new_y] = step
                                q.append([new_x, new_y])
                step+=1

solution = Solution()
rooms = [[2147483647,-1,0,2147483647],[2147483647,2147483647,2147483647,-1],[2147483647,-1,2147483647,-1],[0,-1,2147483647,2147483647]]
solution.wallsAndGates(rooms)
print(rooms)