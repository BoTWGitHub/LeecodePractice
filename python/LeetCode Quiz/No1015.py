class Solution:
    def smallestRepunitDivByK(self, k: int) -> int:
        if k%2 == 0 or k%5 == 0:
            return -1
        d = 1
        res = 1
        rep = set()
        while d%k != 0:
            rem = d%k
            if rem in rep:
                return -1
            rep.add(rem)
            d*=10
            d+=1
            res+=1
        
        return res

solution = Solution()
print(solution.smallestRepunitDivByK(17))