'''
The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.

Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.
'''
from typing import List

class Solution:
    def solveNQueens(self, n: int) -> List[List[str]]:
        self.__res = []
        def backtrack(row:int = 0, temp:List[str] = [], col:set = set(), dia:set = set(), adia:set = set()):
            if row==n:
                self.__res.append(temp.copy())
                return
                
            for i in range(n):
                if i in col or row-i in dia or row+i in adia:
                    continue
                temp.append('.'*i + 'Q' + '.'*(n-i-1))
                col.add(i)
                dia.add(row-i)
                adia.add(row+i)
                backtrack(row+1, temp, col, dia, adia)
                temp.pop()
                col.remove(i)
                dia.remove(row-i)
                adia.remove(row+i)
        backtrack()
        return self.__res

def main():
    solution = Solution()

    n = 4
    print(solution.solveNQueens(n))

if __name__=='__main__':
    main()
