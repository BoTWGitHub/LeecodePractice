'''
Given an integer array nums, return the maximum result of nums[i] XOR nums[j], where 0 <= i <= j < n.
'''
from typing import List

class Solution:
    def findMaximumXOR(self, nums: List[int]) -> int:
        trie = Trie(max(nums))
        res = 0
        for num in nums:
            trie.insert(num)
            res = max(res, trie.findMaxXor(num))
        return res

class Trie:
    def __init__(self, maxNum: int):
        height = 1
        while maxNum//(2**height)>0:
            height+=1
        self._height = height
        self._root = self._trie_node()

    def insert(self, num: int):
        cur = self._root
        h=2**(self._height-1)
        while h>0:
            bit = num//h
            num %= h
            if bit not in cur.children:
                cur.children[bit] = self._trie_node()
            cur = cur.children[bit]
            h >>= 1

    def findMaxXor(self, num: int) -> int:
        res = 0
        cur = self._root
        h = 2**(self._height-1)
        while h>0:
            bit = num//h
            num %= h
            if 1-bit in cur.children:
                res |= h
                cur = cur.children[1-bit]
            else:
                cur = cur.children[bit]
            h >>= 1
        return res
    
    class _trie_node:
        def __init__(self):
            self.children = dict()

def main():
    solution = Solution()

    nums = [3,10,5,25,2,8]
    print(solution.findMaximumXOR(nums))

if __name__=='__main__':
    main()
