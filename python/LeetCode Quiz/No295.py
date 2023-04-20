'''
The median is the middle value in an ordered integer list. 
If the size of the list is even, there is no middle value and the median is the mean of the two middle values.

For example, for arr = [2,3,4], the median is 3.
For example, for arr = [2,3], the median is (2 + 3) / 2 = 2.5.
Implement the MedianFinder class:

MedianFinder() initializes the MedianFinder object.
void addNum(int num) adds the integer num from the data stream to the data structure.
double findMedian() returns the median of all elements so far. 
Answers within 10-5 of the actual answer will be accepted.
'''
import heapq

class MedianFinder:

    def __init__(self):
        self._left = []
        self._right = []
        heapq.heapify(self._left)
        heapq.heapify(self._right)

    def addNum(self, num: int) -> None:
        heapq.heappush(self._left, -num)
        heapq.heappush(self._right, -(heapq.heappop(self._left)))

        if len(self._left)<len(self._right):
            heapq.heappush(self._left, -(heapq.heappop(self._right)))

    def findMedian(self) -> float:
        if len(self._left)==len(self._right):
            return (-self._left[0]+self._right[0])/2
        else:
            return -self._left[0]

def main():
    m = MedianFinder()
    m.addNum(1)
    m.addNum(2)
    print(m.findMedian())
    m.addNum(3)
    print(m.findMedian())

if __name__=='__main__':
    main()
