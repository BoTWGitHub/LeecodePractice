from typing import List

class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        temp = []

        for row in board:
            temp = []
            for c in row:
                if c.isdigit():
                    if int(c) in temp:
                        return False
                    else:
                        temp+=[int(c)]

        for col in range(len(board[0])):
            temp = []
            for row in range(len(board)):
                if board[row][col].isdigit():
                    if int(board[row][col]) in temp:
                        return False
                    else:
                        temp+=[int(board[row][col])]

        for i in range(3):
            for j in range(3):
                temp = []
                for row in range(i*3, i*3+3):
                    for col in range(j*3, j*3+3):
                        if board[row][col].isdigit():
                            if int(board[row][col]) in temp:
                                return False
                            else:
                                temp+=[int(board[row][col])]

        return True

solution = Solution()
board = [["5","3",".",".","7",".",".",".","."]
        ,["6",".",".","1","9","5",".",".","."]
        ,[".","9","8",".",".",".",".","6","."]
        ,["8",".",".",".","6",".",".",".","3"]
        ,["4",".",".","8",".","3",".",".","1"]
        ,["7",".",".",".","2",".",".",".","6"]
        ,[".","6",".",".",".",".","2","8","."]
        ,[".",".",".","4","1","9",".",".","5"]
        ,[".",".",".",".","8",".",".","7","9"]]

board2 = [["8","3",".",".","7",".",".",".","."]
         ,["6",".",".","1","9","5",".",".","."]
         ,[".","9","8",".",".",".",".","6","."]
         ,["8",".",".",".","6",".",".",".","3"]
         ,["4",".",".","8",".","3",".",".","1"]
         ,["7",".",".",".","2",".",".",".","6"]
         ,[".","6",".",".",".",".","2","8","."]
         ,[".",".",".","4","1","9",".",".","5"]
         ,[".",".",".",".","8",".",".","7","9"]]

print(solution.isValidSudoku(board2))