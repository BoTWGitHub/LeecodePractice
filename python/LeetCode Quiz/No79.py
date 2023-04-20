'''
Given an m x n grid of characters board and a string word
, return true if word exists in the grid.

The word can be constructed from letters of sequentially adjacent cells
, where adjacent cells are horizontally or vertically neighboring. 
The same letter cell may not be used more than once.
'''
from typing import List

class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        row = len(board)
        col = len(board[0])
        end = len(word)
        def backtrack(r, c, step):
            if step==end:
                return True
            if r<0 or r>=row or c<0 or c>=col or board[r][c]!=word[step]:
                return False
            
            board[r][c]=' '
            if backtrack(r+1, c, step+1):
                board[r][c]=word[step]
                return True
            if backtrack(r-1, c, step+1):
                board[r][c]=word[step]
                return True
            if backtrack(r, c+1, step+1):
                board[r][c]=word[step]
                return True
            if backtrack(r, c-1, step+1):
                board[r][c]=word[step]
                return True
            board[r][c]=word[step]
            return False
        for i in range(row):
            for j in range(col):
                if backtrack(i, j, 0):
                    return True
        return False

def main():
    solution = Solution()

    board = [["A","A","A","A","A","A"],["A","A","A","A","A","A"],["A","A","A","A","A","A"],["A","A","A","A","A","A"],["A","A","A","A","A","B"],["A","A","A","A","B","A"]]
    word = "AAAAAAAAAAAAABB"
    print(solution.exist(board, word))

if __name__=='__main__':
    main()
