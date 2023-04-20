'''
You have a lock in front of you with 4 circular wheels. 
Each wheel has 10 slots: '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'. 
The wheels can rotate freely and wrap around: for example we can turn '9' to be '0', or '0' to be '9'. 
Each move consists of turning one wheel one slot.

The lock initially starts at '0000', a string representing the state of the 4 wheels.

You are given a list of deadends dead ends
, meaning if the lock displays any of these codes
, the wheels of the lock will stop turning and you will be unable to open it.

Given a target representing the value of the wheels that will unlock the lock
, return the minimum total number of turns required to open the lock, or -1 if it is impossible.
'''

from typing import List

class Solution:
    def openLock(self, deadends: List[str], target: str) -> int:
        def neighbors(node: str):
            for i in range(4):
                x = int(node[i])
                for d in (-1, 1):
                    y = (x+d)%10
                    yield node[:i] + str(y) + node[i+1:]

        dead = set(deadends)
        seen = {'0000'}
        q = ['0000']
        count = 0

        while q:
            for _ in range(len(q)):
                node = q.pop(0)
                if node==target:
                    return count
                if node in dead:
                    continue
                for neighbor in neighbors(node):
                    if neighbor not in seen:
                        seen.add(neighbor)
                        q.append(neighbor)
            count+=1

        return -1

solution = Solution()
deadends = ["0201","0101","0102","1212","2002"]
target = "0202"
print(solution.openLock(deadends, target))