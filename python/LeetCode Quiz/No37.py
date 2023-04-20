'''
Write a program to solve a Sudoku puzzle by filling the empty cells.

A sudoku solution must satisfy all of the following rules:

Each of the digits 1-9 must occur exactly once in each row.
Each of the digits 1-9 must occur exactly once in each column.
Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
The '.' character indicates empty cells.
'''
from typing import List

def printBoard(board: List[List[str]]):
    for row in board:
        print(row)

class Solution:
    def solveSudoku(self, board: List[List[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        def backtrack(r=0, c=0):
            if c==9:
                r+=1
                if r==9:
                    self.__done = True
                    return
                c=0
            
            if board[r][c]!='.':
                backtrack(r, c+1)
            else:
                for n in range(9):
                    if self.__row[r][n] or self.__col[c][n] or self.__blo[r//3*3+c//3][n]:
                        continue
                    board[r][c] = chr(n+ord('1'))
                    self.__row[r][n] = True
                    self.__col[c][n] = True
                    self.__blo[r//3*3+c//3][n] = True
                    backtrack(r, c+1)
                    if not self.__done:
                        board[r][c] = '.'
                        self.__row[r][n] = False
                        self.__col[c][n] = False
                        self.__blo[r//3*3+c//3][n] = False
            
        self.__done = False
        self.__row = [[False]*9 for _ in range(9)]
        self.__col = [[False]*9 for _ in range(9)]
        self.__blo = [[False]*9 for _ in range(9)]
        for r in range(9):
            for c in range(9):
                if board[r][c]!='.':
                    index = int(board[r][c]) - int('1')
                    self.__row[r][index] = True
                    self.__col[c][index] = True
                    self.__blo[r//3*3+c//3][index] = True
        backtrack()

def main():
    solution = Solution()

    board = [["5","3",".",".","7",".",".",".","."],
             ["6",".",".","1","9","5",".",".","."],
             [".","9","8",".",".",".",".","6","."],
             ["8",".",".",".","6",".",".",".","3"],
             ["4",".",".","8",".","3",".",".","1"],
             ["7",".",".",".","2",".",".",".","6"],
             [".","6",".",".",".",".","2","8","."],
             [".",".",".","4","1","9",".",".","5"],
             [".",".",".",".","8",".",".","7","9"]]
    
    solution.solveSudoku(board)
    printBoard(board)

if __name__=='__main__':
    main()
