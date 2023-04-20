'''
You are given a list of songs where the ith song has a duration of time[i] seconds.

Return the number of pairs of songs for which their total duration in seconds is divisible by 60. 
Formally, we want the number of indices i, j such that i < j with (time[i] + time[j]) % 60 == 0.
'''
from typing import List

class Solution:
    def numPairsDivisibleBy60(self, time: List[int]) -> int:
        table = dict()
        for t in time:
            if t%60 not in table:
                table[t%60] = 1
            else:
                table[t%60] += 1

        print(table)
        res = 0
        for t in table:
            if t==0 or t==30:
                res+=(table[t]*(table[t]-1))//2
            else:
                if 60-t in table:
                    res+=table[t]*table[60-t]
                    table[60-t] = 0
        return res
                
def main():
    solution = Solution()

    time = [30,20,150,100,40]
    print(solution.numPairsDivisibleBy60(time))

if __name__=='__main__':
    main()
