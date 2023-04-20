'''
Given an integer array data representing the data
, return whether it is a valid UTF-8 encoding 
(i.e. it translates to a sequence of valid UTF-8 encoded characters).

A character in UTF8 can be from 1 to 4 bytes long, subjected to the following rules:

For a 1-byte character, the first bit is a 0, followed by its Unicode code.
For an n-bytes character, the first n bits are all one's, the n + 1 bit is 0, followed by n - 1 bytes with the most significant 2 bits being 10.
'''
from typing import List

class Solution:
    def validUtf8(self, data: List[int]) -> bool:
        index = 0
        state = 0
        count = 0
        while index<len(data):
            match(state):
                case 0:
                    if data[index]>>3==0x1E:
                        count=3
                        state=1
                    elif data[index]>>4==0x0E:
                        count=2
                        state=1
                    elif data[index]>>5==0x06:
                        count=1
                        state=1
                    elif data[index]>>7==0x00:
                        pass
                    else:
                        return False
                case 1:
                    if data[index]>>6==0x02:
                        count-=1
                        if count==0:
                            state=0
                    else:
                        return False
            index+=1
        
        if state==0:
            return True
        return False

def main():
    solution = Solution()

    data = [197,130,1]
    print(solution.validUtf8(data))

if __name__=='__main__':
    main()
