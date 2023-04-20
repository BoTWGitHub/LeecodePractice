'''
Implement pow(x, n), which calculates x raised to the power n.
'''

class Solution:
    def myPow(self, x: float, n: int) -> float:
        if n==0:
            return 1
        if n==2:
            return x*x
        if n%2==0:
            return self.myPow(self.myPow(x, n//2), 2)
        elif n>0:
            return x*self.myPow(self.myPow(x, n//2), 2)
        else:
            return 1/x*self.myPow(self.myPow(x, -(-n//2)), 2)

def main():
    x=2.0
    n=-2
    print(Solution.myPow(Solution(), x, n))

if __name__=='__main__':
    main()
