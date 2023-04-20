'''
Given an array of integers temperatures represents the daily temperatures
, return an array answer such that answer[i] is the number of days you have to wait after the ith day to get a warmer temperature. 
If there is no future day for which this is possible, keep answer[i] == 0 instead.
'''
from typing import List

class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        stack = [[0, temperatures[0]]]
        res = [0]*len(temperatures)
        for i, temp in enumerate(temperatures):
            while stack:
                if temp>stack[-1][1]:
                    index, _ = stack.pop()
                    res[index] = i-index
                else:
                    break
            stack.append([i, temp])
            
        return res

solution = Solution()
temperatures = [73,74,75,71,69,72,76,73]
print(solution.dailyTemperatures(temperatures))