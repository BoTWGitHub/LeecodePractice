from typing import List

class Solution:
    def generatePalindromes(self, s: str) -> List[str]:
        if not self.canBePalindrome(s):
            return []
        
        count = self.stringCounter(s)
        
        half_str = ''
        odd_char = ''
        for c in count:
            half_str+=c*(count[c]//2)
            if count[c]%2==1:
                odd_char+=c
        
        permute_set = set()
        self.permuteString(half_str, permute_set)

        res = list(permute_set)
        for i in range(len(res)):
            res[i] = res[i] + odd_char + res[i][::-1]
        
        return res

    def canBePalindrome(self, s: str) -> bool:
        count = dict()
        odd_count = 0
        for c in s:
            if c not in count:
                count[c] = 1
                odd_count+=1
            else:
                count[c] += 1
                odd_count-=1
        return odd_count<2
    
    def stringCounter(self, s: str) -> dict():
        count = dict()
        for c in s:
            if c not in count:
                count[c] = 1
            else:
                count[c] += 1
        return count

    def permuteString(self, s: List[str], res: set(), step: int=0):
        if step==len(s):
            res.add(''.join(s))
        
        for i in range(step, len(s)):
            s_copy = [c for c in s]
            s_copy[i], s_copy[step] = s_copy[step], s_copy[i]

            self.permuteString(s_copy, res, step+1)

def main():
    solution = Solution()
    s = 'aabbc'
    print(solution.generatePalindromes(s))

if __name__=='__main__':
    main()
    