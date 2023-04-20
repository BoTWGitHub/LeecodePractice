'''
Design a class to find the kth largest element in a stream. 
Note that it is the kth largest element in the sorted order, not the kth distinct element.

Implement KthLargest class:

KthLargest(int k, int[] nums) Initializes the object with the integer k and the stream of integers nums.
int add(int val) Appends the integer val to the stream and returns the element representing the kth largest element in the stream.
'''
from typing import List
import heapq

class KthLargest:

    def __init__(self, k: int, nums: List[int]):
        self._k = k
        self._nums = nums
        heapq.heapify(self._nums)
        while len(self._nums)>k:
            heapq.heappop(self._nums)

    def add(self, val: int) -> int:
        heapq.heappush(self._nums, val)
        if len(self._nums)>self._k:
            heapq.heappop(self._nums)
        return self._nums[0]

def main():
    test = KthLargest(3, [3, 5, 8, 2])
    print(test.add(3))
    print(test.add(5))
    print(test.add(10))
    print(test.add(9))
    print(test.add(4))

if __name__=='__main__':
    main()
