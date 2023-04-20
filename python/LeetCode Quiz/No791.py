'''
You are given two strings order and s. All the characters of order are unique and were sorted in some custom order previously.

Permute the characters of s so that they match the order that order was sorted. More specifically
, if a character x occurs before a character y in order, then x should occur before y in the permuted string.

Return any permutation of s that satisfies this property.
'''

class Solution:
    def customSortString(self, order: str, s: str) -> str:
        count = {}
        for c in order:
            count[c] = 0
        res = ''
        for c in s:
            if c not in count:
                res+=c
            else:
                count[c]+=1

        for c in count:
            res+=(c*count[c])

        return res

solution = Solution()
order = 'cbafg'
s = 'abcd'
print(solution.customSortString(order, s))