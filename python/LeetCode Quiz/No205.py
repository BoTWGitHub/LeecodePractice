class Solution:
    def isIsomorphic(self, s: str, t: str) -> bool:
        mem = {}
        encode1 = []
        index = 0
        for c in s:
            if c not in mem:
                mem[c] = index
                index+=1
            encode1 += [mem[c]]

        print(encode1)

        mem = {}
        encode2 = []
        index = 0
        for c in t:
            if c not in mem:
                mem[c] = index
                index+=1
            encode2 += [mem[c]]

        print(encode2)
        
        return encode1==encode2

solution = Solution()
s = 'egg'
t = 'add'
print(solution.isIsomorphic(s, t))