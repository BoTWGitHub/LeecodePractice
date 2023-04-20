'''
There are n rooms labeled from 0 to n - 1 and all the rooms are locked except for room 0. 
Your goal is to visit all the rooms. 
However, you cannot enter a locked room without having its key.

When you visit a room, you may find a set of distinct keys in it. 
Each key has a number on it, denoting which room it unlocks
, and you can take all of them with you to unlock the other rooms.

Given an array rooms where rooms[i] is the set of keys that you can obtain if you visited room i
, return true if you can visit all the rooms, or false otherwise.
'''
from typing import List

class Solution:
    def canVisitAllRooms(self, rooms: List[List[int]]) -> bool: #BFS
        visited = [True] + [False] * (len(rooms)-1)
        q = [0]
        while q:
            for _ in range(len(q)):
                visit = q.pop(0)
                for key in rooms[visit]:
                    if not visited[key]:
                        visited[key] = True
                        q.append(key)

        return all(visited)

    def canVisitAllRooms2(self, rooms: List[List[int]]) -> bool: #DFS
        visited = [True] + [False] * (len(rooms)-1)
        stack = [0]
        while stack:
            room = stack.pop()
            for key in rooms[room]:
                if not visited[key]:
                    visited[key] = True
                    stack.append(key)

        return all(visited)

def main():
    solution = Solution()

    rooms = [[1,3],[3,0,1],[2],[0]]
    print(solution.canVisitAllRooms(rooms))

if __name__=='__main__':
    main()
