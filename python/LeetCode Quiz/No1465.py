from typing import List

class Solution:
    def maxArea(self, h: int, w: int, horizontalCuts: List[int], verticalCuts: List[int]) -> int:
        horizontalCuts.sort()
        tempH = [horizontalCuts[0]]
        for i in range(1, len(horizontalCuts)):
            tempH+=[(horizontalCuts[i] - horizontalCuts[i-1])]
        tempH+=[h-horizontalCuts[-1]]
        maxH = max(tempH)
        print(tempH, maxH)

        verticalCuts.sort()
        tempV = [verticalCuts[0]]
        for i in range(1, len(verticalCuts)):
            tempV+=[(verticalCuts[i] - verticalCuts[i-1])]
        tempV+=[w-verticalCuts[-1]]
        maxV = max(tempV)
        print(tempV, maxV)
        
        return (maxV*maxH)%(10**9+7)

solution = Solution()
print(solution.maxArea(5, 4, [3], [3]))