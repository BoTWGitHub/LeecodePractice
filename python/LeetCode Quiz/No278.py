bad = 1702766719

def isBadVersion(i):
    if i >= bad:
        return True
    return False

class Solution:
    def firstBadVersion(self, n: int) -> int:
        left, right = 1, n
        while left<right:
            mid=(left+right)//2
            if isBadVersion(mid):
                right=mid
            else:
                left=mid+1
        if left<n+1 and isBadVersion(left):
            return left
        return left+1
        
solution = Solution()
print(solution.firstBadVersion(2126753391))