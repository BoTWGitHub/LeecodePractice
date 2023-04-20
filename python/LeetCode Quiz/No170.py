'''
Design a data structure that accepts a stream of integers and checks if it has a pair of integers that sum up to a particular value.

Implement the TwoSum class:

TwoSum() Initializes the TwoSum object, with an empty array initially.
void add(int number) Adds number to the data structure.
boolean find(int value) Returns true if there exists any pair of numbers whose sum is equal to value, otherwise, it returns false.
'''

class TwoSum:
    def __init__(self):
        self._mem = dict()

    def add(self, number: int) -> None:
        if number not in self._mem:
            self._mem[number] = 1
        else:
            self._mem[number]+=1

    def find(self, value: int) -> bool:
        for num in self._mem:
            target = value-num
            if target==num:
                if self._mem[num]>1:
                    return True
            else:
                if target in self._mem:
                    return True
        return False

def main():
    temp = TwoSum()
    temp.add(1)
    temp.add(3)
    temp.add(5)
    print(temp.find(4))
    print(temp.find(7))

if __name__=='__main__':
    main()
