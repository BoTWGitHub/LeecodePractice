class Solution:
    def longestPalindrome(self, s: str) -> int:
        count = {}
        for c in s:
            if c in count:
                count[c]+=1
            else:
                count[c]=1
        
        print(count)

        res = 0
        for c in count:
            res+=(count[c]-count[c]%2)
            
        return min(res+1, len(s))

solution = Solution()
s = 'abccccdd'
print(solution.longestPalindrome(s))