'''
Given a characters array letters that is sorted in non-decreasing order and a character target
, return the smallest character in the array that is larger than target.

Note that the letters wrap around.

For example, if target == 'z' and letters == ['a', 'b'], the answer is 'a'.
'''
from typing import List

class Solution:
    def nextGreatestLetter(self, letters: List[str], target: str) -> str:
        left, right = 0, len(letters)-1
        while left<right:
            mid=(left+right)//2
            if letters[mid]>target:
                right=mid
            else:
                left=mid+1
        if left==len(letters)-1 and target>=letters[left]:
            return letters[0]
        return letters[left]


def main():
    solution = Solution()

    letters = ["a","b","c"]
    target = "c"
    print(solution.nextGreatestLetter(letters, target))

if __name__=='__main__':
    main()
