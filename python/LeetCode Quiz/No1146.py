'''
Implement a SnapshotArray that supports the following interface:

SnapshotArray(int length) initializes an array-like data structure with the given length.  Initially, each element equals 0.
void set(index, val) sets the element at the given index to be equal to val.
int snap() takes a snapshot of the array and returns the snap_id: the total number of times we called snap() minus 1.
int get(index, snap_id) returns the value at the given index, at the time we took the snapshot with the given snap_id
'''
from typing import List

class SnapshotArray:
    def __init__(self, length: int):
        self.__snapId = 0
        self.__records = [[[0, 0]] for _ in range(length)]

    def set(self, index: int, val: int) -> None:
        if self.__records[index][-1][0]==self.__snapId:
            self.__records[index][-1][1] = val
        else:
            self.__records[index].append([self.__snapId, val])

    def snap(self) -> int:
        self.__snapId+=1
        return self.__snapId-1

    def get(self, index: int, snap_id: int) -> int:
        record = self.__records[index]
        i = self.__binarySearch(record, snap_id)
        return record[i][1]

    def __binarySearch(self, record: List[List[int]], target: int) -> int:
        left, right = 0, len(record)-1
        while left<right:
            mid = (left+right)//2
            if record[mid][0] == target:
                return mid
            elif record[mid][0] < target:
                left = mid+1
            else:
                right = mid-1

        if record[left][0] <= target or left == 0:
            return left
        return left-1

    def printRecords(self):
        print(self.__records)
        
# Your SnapshotArray object will be instantiated and called as such:
# obj = SnapshotArray(length)
# obj.set(index,val)
# param_2 = obj.snap()
# param_3 = obj.get(index,snap_id)

snap = SnapshotArray(1)
snap.printRecords()

print('take a snap: ', snap.snap())
snap.printRecords()

print('take a snap: ', snap.snap())
snap.printRecords()

snap.set(0, 4)
snap.printRecords()

print('take a snap: ', snap.snap())
snap.printRecords()

print('get snap 1 index 0: ', snap.get(0, 1))

snap.set(0, 12)
snap.printRecords()

print('get snap 1 index 0: ', snap.get(0, 1))

print('take a snap: ', snap.snap())
snap.printRecords()

print('get snap 3 index 0: ', snap.get(0, 3))
