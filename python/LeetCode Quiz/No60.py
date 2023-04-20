'''
The set [1, 2, 3, ..., n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order
, we get the following sequence for n = 3:

"123"
"132"
"213"
"231"
"312"
"321"
Given n and k, return the kth permutation sequence.
'''

class Solution:
    def getPermutation(self, n: int, k: int) -> str:
        res = ''
        nums = [x for x in range(1, n+1)]
        fac = 1
        top = n-1
        for i in range(2, n):
            fac*=i

        while len(nums)>0:
            group = (k-1)//fac
            k%=fac
            fac//=top
            top = top-1 if top-1>1 else 1     # top = top-1>1 ? top-1 : 1
            res+=str(nums[group])
            nums.pop(group)
        return res
        
        

def main():
    n=8
    k=20161
    print(Solution.getPermutation(Solution(), n, k))

if __name__=='__main__':
    main()
