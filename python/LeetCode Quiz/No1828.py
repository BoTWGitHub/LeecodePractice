from typing import List

class Solution:
    def countPoints(self, points: List[List[int]], queries: List[List[int]]) -> List[int]:
        res = [0]*len(queries)
        for i in range(len(queries)):
            for point in points:
                #print(queries[i][2], point[0], point[1])
                if queries[i][2]**2 >= (point[0]-queries[i][0])**2 + (point[1]-queries[i][1])**2:
                    res[i]+=1
        return res

solution = Solution()
print(solution.countPoints([[1,1],[2,2],[3,3],[4,4],[5,5]], [[1,2,2],[2,2,2],[4,3,2],[4,3,3]]))