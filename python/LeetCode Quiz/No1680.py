'''
Given an integer n
, return the decimal value of the binary string formed by concatenating the binary representations of 1 to n in order
, modulo 109 + 7.
'''
class Solution:
    def concatenatedBinary(self, n: int) -> int:
        s = ''
        for i in range(1, n+1):
            s+=f'{i:b}'
        return int(s, 2)%(10**9+7)

def main():
    solution = Solution()
    
    n=24
    print(solution.concatenatedBinary(n))

if __name__=='__main__':
    main()
