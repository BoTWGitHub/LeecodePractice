'''
The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.

Given an integer n, return the number of distinct solutions to the n-queens puzzle.
'''
class Solution:
    def totalNQueens(self, n: int) -> int:
        self.__res = 0
        def backtrack(row: int = 0, col: set = set(), dia: set = set(), adia: set = set()):
            if row==n:
                self.__res+=1
                return
            for i in range(n):
                if i in col:
                    continue
                if row-i in dia:
                    continue
                if row+i in adia:
                    continue
                col.add(i)
                dia.add(row-i)
                adia.add(row+i)
                backtrack(row+1, col, dia, adia)
                col.remove(i)
                dia.remove(row-i)
                adia.remove(row+i)
        backtrack()
        return self.__res

def main():
    solution = Solution()

    n = 1
    print(solution.totalNQueens(n))

if __name__=='__main__':
    main()
