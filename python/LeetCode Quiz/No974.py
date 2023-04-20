'''
Given an array of points where points[i] = [xi, yi] represents a point on the X-Y plane and an integer k, 
return the k closest points to the origin (0, 0).

The distance between two points on the X-Y plane is the Euclidean distance (i.e., √(x1 - x2)2 + (y1 - y2)2).

You may return the answer in any order. 
The answer is guaranteed to be unique (except for the order that it is in).
'''
from typing import List
import heapq
import random

class Solution:
    def kClosest(self, points: List[List[int]], k: int) -> List[List[int]]:
        heap = []
        heapq.heapify(heap)
        for x, y in points:
            length = x*x+y*y
            if len(heap)<k:
                heapq.heappush(heap, [-length, x, y])
            elif -length>heap[0][0]:
                heapq.heappop(heap)
                heapq.heappush(heap, [-length, x, y])
        return [[x, y] for _, x, y in heap]
    def kClosest2(self, points: List[List[int]], k: int) -> List[List[int]]:
        def partition(left, right, pi):
            pivot = points[pi][0]**2+points[pi][1]**2
            points[pi], points[right] = points[right], points[pi]
            index = left
            for i in range(left, right):
                length = points[i][0]**2+points[i][1]**2
                if length<pivot:
                    points[index], points[i] = points[i], points[index]
                    index+=1
            points[right], points[index] = points[index], points[right]
            return index

        def find(left, right, k):
            if left>right:
                return

            res = partition(left, right, random.randint(left, right))
            if res==k:
                return
            elif res>k:
                find(left, res-1, k)
            else:
                find(res+1, right, k)
        
        find(0, len(points)-1, k)
        return points[:k]

def main():
    solution = Solution()

    points = [[3,3],[5,-1],[-2,4]]
    k = 2
    print(solution.kClosest2(points, k))

if __name__=='__main__':
    main()
