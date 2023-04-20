class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        return ''.join(sorted(s))==''.join(sorted(t))

solution = Solution()
s1 = 'anagram'
s2 = 'nagaram'
print(solution.isAnagram(s1, s2))