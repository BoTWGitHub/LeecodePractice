class MaxHeap:
    def __init__(self):
        self.__nums = []
    
    def insert(self, val: int):
        #Insert to the last of array
        self.__nums.append(val)
        index = len(self.__nums)-1
        #Check if parent node need to swap
        while index > 0:
            if self.__nums[(index-1)//2]<val:
                self.__nums[(index-1)//2], self.__nums[index] = self.__nums[index], self.__nums[(index-1)//2]
                index = (index-1)//2
            else:
                break
    
    def getMax(self) -> int:
        if not self.__nums:
            return []
        return self.__nums[0]

    def popMax(self) -> int:
        if not self.__nums:
            return []
        #Swap root and last element and pop the Max value
        self.__nums[0], self.__nums[-1] = self.__nums[-1], self.__nums[0]
        res = self.__nums.pop()
        index = 0
        #Check if the root need to sink
        while (index*2+1)<len(self.__nums):
            left, right = index*2+1, index*2+2
            swap = left
            if right<len(self.__nums) and self.__nums[right]>self.__nums[left]:
                swap = right
            
            if self.__nums[swap]>self.__nums[index]:
                self.__nums[index], self.__nums[swap] = self.__nums[swap], self.__nums[index]
                index = swap
            else:
                break
        return res
    
    def getLen(self):
        return len(self.__nums)

    def printHeap(self):
        print('\nprint heap')
        for num in self.__nums:
            print(num, end=",")
        print('\n')
    
heap = MaxHeap()
nums = [95942,106998,97211,139575,138600,194849,349290,364587,477020,257807,215501,226137,314039,484201,483480,853040,970066,964099,892477,842555,678763,255308,458293,673059,248529,521419,317295,516376,853983,986277,721583,998828,915337]

for num in nums:
    heap.insert(num)

heap.printHeap()
print(heap.popMax())
heap.printHeap()
print(heap.popMax())
heap.printHeap()
print(heap.popMax())
heap.printHeap()