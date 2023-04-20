'''
Write an efficient algorithm that searches for a value target in an m x n integer matrix matrix. 
This matrix has the following properties:

Integers in each row are sorted in ascending from left to right.
Integers in each column are sorted in ascending from top to bottom.
'''
from typing import List

class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool: #divide and conquer
        def find(r1, r2, c1, c2) -> bool:
            if r2<r1 or c2<c1:
                return False
            if r1==r2 and c1==c2:
                if matrix[r1][c1]==target:
                    return True
                else:
                    return False
            r = (r1+r2)//2
            c = (c1+c2)//2
            if target==matrix[r][c]:
                return True
            elif target>matrix[r][c]:
                if find(r1, r2, c+1, c2):
                    return True
                elif find(r+1, r2, c1, c):
                    return True
                else:
                    return False
            else:
                if find(r1, r-1, c1, c2):
                    return True
                elif find(r, r2, c1, c-1):
                    return True
                else:
                    return False
        return find(0, len(matrix)-1, 0, len(matrix[0])-1)
    
    def searchMatrix2(self, matrix: List[List[int]], target: int) -> bool: #move
        r = len(matrix)-1
        c = 0
        while r>=0 and c<len(matrix[0]):
            if matrix[r][c]==target:
                return True
            elif matrix[r][c]>target:
                r-=1
            else:
                c+=1
        return False

def main():
    solution = Solution()

    matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]]
    target = 5
    print(solution.searchMatrix2(matrix, target))

if __name__=='__main__':
    main()
