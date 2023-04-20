class MovingAverage:

    def __init__(self, size: int):
        self.__nums = []
        self.__len = size
        self.__tempSum = 0

    def next(self, val: int) -> float:
        self.__nums.append(val)
        self.__tempSum+=val
        if len(self.__nums)>self.__len:
            self.__tempSum-=self.__nums.pop(0)

        return self.__tempSum/len(self.__nums)

ave = MovingAverage(3)
print(ave.next(1))
print(ave.next(10))
print(ave.next(3))
print(ave.next(5))