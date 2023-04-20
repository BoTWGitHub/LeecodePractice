'''
The Tribonacci sequence Tn is defined as follows: 

T0 = 0, T1 = 1, T2 = 1, and Tn+3 = Tn + Tn+1 + Tn+2 for n >= 0.

Given n, return the value of Tn.
'''

class Solution:
    def tribonacci(self, n: int) -> int:
        mem = dict()
        def cal(n: int) -> int:
            if n<2:
                return n
            if n==2:
                return 1
            if n not in mem:
                mem[n] = cal(n-3) + cal(n-2) + cal(n-1)
            return mem[n]
        return cal(n)

solution = Solution()
n = 25
print(solution.tribonacci(n))