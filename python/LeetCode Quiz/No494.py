from typing import List

class Solution:
    def findTargetSumWays(self, nums: List[int], target: int) -> int:
        mem = {0:{0:1}}
        for i in range(len(nums)):
            mem[i+1] = dict()
            for lastSum in mem[i]:
                if (lastSum+nums[i]) not in mem[i+1]:
                    mem[i+1][lastSum+nums[i]] = mem[i][lastSum]
                else:
                    mem[i+1][lastSum+nums[i]] += mem[i][lastSum]
                if (lastSum-nums[i]) not in mem[i+1]:
                    mem[i+1][lastSum-nums[i]] = mem[i][lastSum]
                else:
                    mem[i+1][lastSum-nums[i]] += mem[i][lastSum]
        print(mem)
        if target not in mem[len(nums)]:
            return 0
        return mem[len(nums)][target]

    def findTargetSumWays2(self, nums: List[int], target: int) -> int:
        dp = {0:1}
        for val in nums:
            next = dict()
            for lastSum in dp:
                sum_p = lastSum+val
                sum_m = lastSum-val
                if sum_p not in next:
                    next[sum_p] = 0
                if sum_m not in next:
                    next[sum_m] = 0
                next[sum_p] += dp[lastSum]
                next[sum_m] += dp[lastSum]
            dp = next

        if target not in dp:
            return 0
        return dp[target]

def main():
    nums = [1,1,1,1,1]
    target = 3
    print(Solution.findTargetSumWays2(Solution(), nums, target))

if __name__=='__main__':
    main()