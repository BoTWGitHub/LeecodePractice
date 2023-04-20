from typing import List

class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        mem = dict()
        for i, val in enumerate(nums):
            temp = target - val
            if temp in mem:
                return [mem[temp], i]
            mem[val] = i
        return [-1]

def main():
    nums = [3,2,4]
    target = 6
    print(Solution.twoSum(Solution(), nums, target))

if __name__=='__main__':
    main()
