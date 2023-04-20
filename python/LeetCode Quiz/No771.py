'''
You're given strings jewels representing the types of stones that are jewels
, and stones representing the stones you have. 
Each character in stones is a type of stone you have. 
You want to know how many of the stones you have are also jewels.

Letters are case sensitive, so "a" is considered a different type of stone from "A".
'''
class Solution:
    def numJewelsInStones(self, jewels: str, stones: str) -> int:
        j = set(jewels)
        res = 0
        for c in stones:
            if c in j:
                res+=1
        return res

def main():
    jewels = 'aA'
    stones = 'aAAbbbb'
    print(Solution.numJewelsInStones(Solution(), jewels, stones))

if __name__=='__main__':
    main()
