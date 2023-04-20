'''
Given an n x n matrix where each of the rows and columns is sorted in ascending order, return the kth smallest element in the matrix.

Note that it is the kth smallest element in the sorted order, not the kth distinct element.

You must find a solution with a memory complexity better than O(n2).
'''
from typing import List
import heapq

class Solution:
    def kthSmallest(self, matrix: List[List[int]], k: int) -> int:
        heap = []
        heapq.heapify(heap)
        for col in matrix:
            for num in col:
                if len(heap)<k:
                    heapq.heappush(heap, -num)
                elif -num>heap[0]:
                    heapq.heappop(heap)
                    heapq.heappush(heap, -num)
        return -heap[0]

def main():
    solution = Solution()

    matrix = [[-5]]
    k = 1
    print(solution.kthSmallest(matrix, k))

if __name__=='__main__':
    main()
