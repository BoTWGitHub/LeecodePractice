'''
Given an m x n binary matrix mat, return the distance of the nearest 0 for each cell.

The distance between two adjacent cells is 1.
'''
from typing import List

class Solution:
    def updateMatrix(self, mat: List[List[int]]) -> List[List[int]]:
        rows, cols = len(mat), len(mat[0])
        dirs = [[1, 0], [-1, 0], [0, 1], [0, -1]]
        mem = set()
        q = []

        for i, row in enumerate(mat):
            for j, val in enumerate(row):
                if val==0:
                    q.append((i, j))

        index = 0
        while q:
            index+=1
            for _ in range(len(q)):
                org_x, org_y = q.pop(0)
                for dir_x, dir_y in dirs:
                    mov_x, mov_y = org_x+dir_x, org_y+dir_y
                    if mov_x>=0 and mov_x<rows and mov_y>=0 and mov_y<cols and mat[mov_x][mov_y]!=0:
                        if (mov_x, mov_y) not in mem:
                            mat[mov_x][mov_y] = index
                            q.append((mov_x, mov_y))
                            mem.add((mov_x, mov_y))
                        elif index<mat[mov_x][mov_y]:
                            mat[mov_x][mov_y] = index
                            q.append((mov_x, mov_y))

        return mat
                        

def printMatrix(mat: List[List[int]]):
    for r in mat:
        print(r)
    print('')

def main():
    solution = Solution()
    mat = [[0,0,0],[0,1,0],[1,1,1]]
    printMatrix(mat)

    mat = solution.updateMatrix(mat)
    printMatrix(mat)

if __name__=='__main__':
    main()
