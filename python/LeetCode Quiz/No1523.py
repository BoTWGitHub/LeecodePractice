class Solution:
    def countOdds(self, low: int, high: int) -> int:
        count = 0
        for _ in range(low+(low+1)%2, high+1, 2):
            count+=1
        return count

    def countOdds2(self, low: int, high: int) -> int:
        return ((high-(high+1)%2) - (low + (low+1)%2))//2+1

solution = Solution()
print(solution.countOdds2(806545180, 881747173))