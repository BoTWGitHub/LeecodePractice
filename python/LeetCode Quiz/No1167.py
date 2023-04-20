'''
You have some number of sticks with positive integer lengths. 
These lengths are given as an array sticks, where sticks[i] is the length of the ith stick.

You can connect any two sticks of lengths x and y into one stick by paying a cost of x + y. 
You must connect all the sticks until there is only one stick remaining.

Return the minimum cost of connecting all the given sticks into one stick in this way.
'''
from typing import List
import heapq

class Solution:
    def connectSticks(self, sticks: List[int]) -> int:
        heapq.heapify(sticks)
        res = 0
        while len(sticks)>1:
            s1 = heapq.heappop(sticks)
            s2 = heapq.heappop(sticks)
            res += (s1+s2)
            heapq.heappush(sticks, s1+s2)
        return res

def main():
    solution = Solution()

    sticks = [1,8,3,5]
    print(solution.connectSticks(sticks))

if __name__=='__main__':
    main()
