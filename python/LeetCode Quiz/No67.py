'''
Given two binary strings a and b
, return their sum as a binary string.

Input: a = "11", b = "1"
Output: "100"
'''

class Solution:
    def addBinary(self, a: str, b: str) -> str:
        i1, i2 = len(a)-1, len(b)-1
        c = 0
        res = ''
        while i1>-1 or i2>-1:
            s = c
            if i1>-1:
                s+=int(a[i1])
                i1-=1
            if i2>-1:
                s+=int(b[i2])
                i2-=1
            res = str(s%2) + res
            if s>1:
                c = 1
            else:
                c = 0
        
        if c==1:
            res = '1' + res

        return res
    
    def addBinary2(self, a: str, b: str) -> str:
        x, y = int(a, 2), int(b, 2)
        while y:
            x, y = x^y, (x&y)<<1
        return bin(x)[2:]


def main():
    a = '1010'
    b = '1011'
    print(Solution.addBinary2(Solution(), a, b))

if __name__=='__main__':
    main()
