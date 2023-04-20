from typing import List

class Solution:
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        mem = dict()
        def climb(n: int) -> int:
            if n < 2:
                return 0
            if n not in mem:
                mem[n] = min(climb(n-1) + cost[n-1], climb(n-2)+cost[n-2])
            return mem[n]
        return climb(len(cost))
    
solution = Solution()
cost = [10,15,20]
print(solution.minCostClimbingStairs(cost))