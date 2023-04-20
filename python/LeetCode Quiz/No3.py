'''
Given a string s, 
find the length of the longest substring without repeating characters.
'''

class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        if len(s) == 0 or len(s) == 1:
            return len(s)
        w = {s[0]}
        left, right = 0, 1
        ans = 1
        while right<len(s):
            if s[right] in w:
                while s[left]!=s[right]:
                    w.remove(s[left])
                    left+=1
                left+=1
            w.add(s[right])
            ans = max(ans, right-left+1)
            right+=1
        return ans

def main():
    solution = Solution()
    
    s = 'abcabcbb'
    print(solution.lengthOfLongestSubstring(s))

    s = 'tmmzuxt'
    print(solution.lengthOfLongestSubstring(s))

    s = 'pwwkew'
    print(solution.lengthOfLongestSubstring(s))

if __name__=='__main__':
    main()
