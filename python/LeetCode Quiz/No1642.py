'''
You are given an integer array heights representing the heights of buildings, some bricks, and some ladders.

You start your journey from building 0 and move to the next building by possibly using bricks or ladders.

While moving from building i to building i+1 (0-indexed),

If the current building's height is greater than or equal to the next building's height, you do not need a ladder or bricks.
If the current building's height is less than the next building's height, you can either use one ladder or (h[i+1] - h[i]) bricks.

Return the furthest building index (0-indexed) you can reach if you use the given ladders and bricks optimally.
'''
from typing import List
import heapq

class Solution:
    def furthestBuilding(self, heights: List[int], bricks: int, ladders: int) -> int:
        res = 0
        diffs = []
        heapq.heapify(diffs)
        while res<len(heights)-1:
            diff = heights[res+1]-heights[res]
            if diff>0:
                if bricks>=diff:
                    bricks-=diff
                    heapq.heappush(diffs, -diff)
                else:
                    if ladders>0:
                        ladders-=1
                        if len(diffs)>0 and diff<(-diffs[0]):
                            bricks+=(-heapq.heappop(diffs))
                            bricks-=diff
                            heapq.heappush(diffs, -diff)
                    else:
                        return res
            res+=1
        return res

    def furthestBuilding2(self, heights: List[int], bricks: int, ladders: int) -> int:
        res = 0
        diffs = []
        heapq.heapify(diffs)
        while res<len(heights)-1:
            diff = heights[res+1]-heights[res]
            if diff>0:
                if ladders>0:
                    ladders-=1
                    heapq.heappush(diffs, diff)
                else:
                    if len(diffs)>0 and diff>diffs[0]:
                        bricks-=heapq.heappop(diffs)
                        heapq.heappush(diffs, diff)
                    else:
                        bricks-=diff
                    if bricks<0:
                        return res
            res+=1
        return res
    
    def furthestBuilding3(self, heights: List[int], bricks: int, ladders: int) -> int:
        def climb(index: int) -> bool:
            b=bricks
            l=ladders
            diffs = []
            for i in range(index):
                diff = heights[i+1]-heights[i]
                if diff>0:
                    diffs.append(diff)
            diffs.sort()
            print(f'i {index} {diffs}', end='')
            for diff in diffs:
                if b>=diff:
                    b-=diff
                elif l>0:
                    l-=1
                else:
                    print(' No')
                    return False
            print(' Yes')
            return True
        
        left = 0
        right = len(heights)-1
        while left<right:
            mid=(left+right)//2+1
            if climb(mid):
                left = mid+1
            else:
                right = mid-1
        print(left, right)
        return right
    
    def furthestBuilding4(self, heights: List[int], bricks: int, ladders: int) -> int:
        def climb(diffs: List[List[int]], index: int, b: int, l: int) -> bool:
            print(f'i {index} {diffs}', end='')
            for diff, i in diffs:
                if i>index:
                    continue
                if b>=diff:
                    b-=diff
                elif l>0:
                    l-=1
                else:
                    print(' No')
                    return False
            print(' Yes')
            return True
        
        diffs = []
        for i in range(len(heights)-1):
            diff = heights[i+1]-heights[i]
            if diff>0:
                diffs.append([diff, i+1])
        diffs.sort()

        left = 0
        right = len(heights)-1
        while left<right:
            mid=(left+right)//2+1
            if climb(diffs, mid, bricks, ladders):
                left = mid+1
            else:
                right = mid-1
        return right

def main():
    solution = Solution()

    heights = [4,2,7,6,9,14,12]
    bricks = 5
    ladders = 1
    print(solution.furthestBuilding4(heights, bricks, ladders))

if __name__=='__main__':
    main()
