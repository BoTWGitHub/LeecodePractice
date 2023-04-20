'''
Given a list of 24-hour clock time points in "HH:MM" format
, return the minimum minutes difference between any two time-points in the list.
'''

from typing import List

class Solution:
    def findMinDifference(self, timePoints: List[str]) -> int:
        timePoints.sort()

        def timepointsToMm(point:str) -> int:
            sep = point.find(':')
            hh = int(point[:sep])
            mm = int(point[sep+1:])
            return hh*60+mm

        mms = []
        for point in timePoints:
            mms.append(timepointsToMm(point))

        diffs = []
        for i in range(len(mms)):
            diff = abs(mms[i] - mms[i-1])
            if diff>720:
                diff = abs(diff-1440)
            diffs.append(diff)

        return min(diffs)

solution = Solution()
timePoints = ["17:41","22:06","20:59","17:37","04:14"]
#timePoints = ["01:01","02:01","03:00"]
print(solution.findMinDifference(timePoints))
