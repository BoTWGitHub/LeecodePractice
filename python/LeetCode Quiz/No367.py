'''
Given a positive integer num, write a function which returns True if num is a perfect square else False.

Follow up: Do not use any built-in library function such as sqrt.
'''
class Solution:
    def isPerfectSquare(self, num: int) -> bool:
        left, right = 1, num
        while left<=right:
            mid=(left+right)//2
            val=mid**2
            if val==num:
                return True
            elif val>num:
                right=mid-1
            else:
                left=mid+1
        return False

def main():
    solution = Solution()

    num = 16
    print(solution.isPerfectSquare(num))

if __name__=='__main__':
    main()
