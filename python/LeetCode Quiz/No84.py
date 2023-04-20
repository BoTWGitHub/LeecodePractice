'''
Given an array of integers heights representing the histogram's bar height where the width of each bar is 1
, return the area of the largest rectangle in the histogram.
'''
from typing import List

class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:
        stack = []
        max_area = 0
        for i, h in enumerate(heights):
            while len(stack)>0 and h<heights[stack[-1]]:
                height = heights[stack.pop()]
                if len(stack)>0:
                    max_area = max(max_area, height*(i-stack[-1]-1))
                else:
                    max_area = max(max_area, height*i)
            stack.append(i)
        while len(stack)>0:
            height = heights[stack.pop()]
            if len(stack)>0:
                max_area = max(max_area, height*(len(heights)-stack[-1]-1))
            else:
                max_area = max(max_area, height*len(heights))
        return max_area

def main():
    solution = Solution()

    heights = [2,1,5,6,2,3]
    print(solution.largestRectangleArea(heights))

if __name__=='__main__':
    main()
