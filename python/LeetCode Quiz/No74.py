from typing import List

class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool: #brute-force
        for row in range(len(matrix)):
            if matrix[row][0] == target:
                return True
            elif matrix[row][0] > target:
                if target in matrix[row-1]:
                    return True
                else:
                    return False
        
        if target in matrix[row]:
            return True

        return False
    
    def searchMatrix3(self, matrix: List[List[int]], target: int) -> bool: #double-binary-search
        left, right = 0, len(matrix)-1
        while left<right:
            mid=(left+right)//2+1
            if matrix[mid][0]==target:
                return True
            elif matrix[mid][0]>target:
                right=mid-1
            else:
                left=mid
        r = left
        left, right = 0, len(matrix[0])-1
        while left<=right:
            mid=(left+right)//2
            if matrix[r][mid]==target:
                return True
            elif matrix[r][mid]>target:
                right=mid-1
            else:
                left=mid+1
        return False
    
    def searchMatrix4(self, matrix: List[List[int]], target: int) -> bool: #single-binary-search
        r = len(matrix)
        c = len(matrix[0])
        left, right = 0, r*c-1
        while left<=right:
            mid = (left+right)//2
            if matrix[mid//c][mid%c]==target:
                return True
            elif matrix[mid//c][mid%c]>target:
                right=mid-1
            else:
                left=mid+1
        return False


solution = Solution()
matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]]
target = 13
print(solution.searchMatrix3(matrix, target))