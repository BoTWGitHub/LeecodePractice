class Solution:
    def longestPalindrome(self, s: str) -> str:
        l = len(s)
        dp = [[False]*l for _ in range(l)]

        for i in range(l):
            dp[i][i] = True

        max_sub_str = s[0]
        for left in range(l, -1, -1):
            for right in range(left+1, l):
                if s[left] == s[right]:
                    if right-left == 1 or dp[left+1][right-1] == True:
                        dp[left][right] = True
                        if len(max_sub_str) < right-left+1:
                            max_sub_str = s[left:right+1]    
                            
        return max_sub_str

solution = Solution()
print(solution.longestPalindrome("cbbf"))