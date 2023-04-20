class Solution:       
    def minDistance(self, word1: str, word2: str) -> int:
        def lcs(s1, s2):
            l1 = len(s1)
            l2 = len(s2)
            count = [[0]*(l2+1) for x in range(l1+1)]
            for i in range(1, l1+1):
                for j in range(1, l2+1):
                    if s1[i-1]==s2[j-1]:
                        count[i][j] = count[i-1][j-1]+1
                    else:
                        count[i][j] = max(count[i-1][j], count[i][j-1])
            return count[-1][-1]
        return len(word1) + len(word2) - 2*lcs(word1, word2)

solution = Solution()
word1 = 'dinitrophenylhydrazine'
word2 = 'acetylphenylhydrazine'
print(solution.minDistance(word1, word2))