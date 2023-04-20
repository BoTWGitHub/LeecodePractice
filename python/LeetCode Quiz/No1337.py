'''
You are given an m x n binary matrix mat of 1's (representing soldiers) and 0's (representing civilians). 
The soldiers are positioned in front of the civilians. 
That is, all the 1's will appear to the left of all the 0's in each row.

A row i is weaker than a row j if one of the following is true:

The number of soldiers in row i is less than the number of soldiers in row j.
Both rows have the same number of soldiers and i < j.
Return the indices of the k weakest rows in the matrix ordered from weakest to strongest.
'''
from typing import List
import heapq

class Solution:
    def kWeakestRows(self, mat: List[List[int]], k: int) -> List[int]:
        temp = []
        heapq.heapify(temp)
        for i, r in enumerate(mat):
            heapq.heappush(temp, [r.count(1), i])
        res = []
        for _ in range(k):
            res.append(heapq.heappop(temp)[1])
        return res

def main():
    solution = Solution()

    mat = [[1,1,0,0,0],
           [1,1,1,1,0],
           [1,0,0,0,0],
           [1,1,0,0,0],
           [1,1,1,1,1]]
    k = 3
    print(solution.kWeakestRows(mat, k))

if __name__=='__main__':
    main()
