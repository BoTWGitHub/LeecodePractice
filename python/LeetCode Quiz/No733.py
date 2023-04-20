'''
An image is represented by an m x n integer grid image where image[i][j] represents the pixel value of the image.

You are also given three integers sr, sc, and color. 
You should perform a flood fill on the image starting from the pixel image[sr][sc].

To perform a flood fill, consider the starting pixel
, plus any pixels connected 4-directionally to the starting pixel of the same color as the starting pixel
, plus any pixels connected 4-directionally to those pixels (also with the same color), and so on. 
Replace the color of all of the aforementioned pixels with color.

Return the modified image after performing the flood fill.
'''
from typing import List

class Solution:
    def floodFill(self, image: List[List[int]], sr: int, sc: int, color: int) -> List[List[int]]:
        def fill(r, c, target):
            if r<0 or r>=len(image) or c<0 or c>=len(image[0]) or image[r][c]==color or image[r][c] != target:
                return
            image[r][c] = color
            fill(r+1, c, target)
            fill(r-1, c, target)
            fill(r, c+1, target)
            fill(r, c-1, target)

        fill(sr, sc, image[sr][sc])
        return image

def main():
    solution = Solution()

    image = [[0,0,0],[0,0,0]]
    sr = 0
    sc = 0
    color = 1

    for r in image:
        print(r)

    res = solution.floodFill(image, sr, sc, color)

    print('-----------------')
    
    for r in res:
        print(r)

if __name__=='__main__':
    main()
