'''
Given an integer n, return the least number of perfect square numbers that sum to n.

A perfect square is an integer that is the square of an integer; 
in other words, it is the product of some integer with itself. 
For example, 1, 4, 9, and 16 are perfect squares while 3 and 11 are not.
'''

class Solution:
    def numSquares(self, n: int) -> int:
        nodes = []
        for i in range(1, n+1):
            if i**2<=n:
                nodes.append(i**2)
            else:
                break

        q = [0]
        mem = set()
        count = 0
        while q:
            size = len(q)
            count+=1
            for _ in range(size):
                num = q.pop(0)
                for val in nodes:
                    temp_sum = num+val
                    if temp_sum == n:
                        return count
                    if temp_sum not in mem and temp_sum<n:
                        q.append(temp_sum)
                        mem.add(temp_sum)
            
        return -1

def main():
    solution = Solution()
    
    n = 12
    print(solution.numSquares(n))

if __name__=='__main__':
    main()
