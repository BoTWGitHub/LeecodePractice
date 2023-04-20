'''
We build a table of n rows (1-indexed). 
We start by writing 0 in the 1st row. 
Now in every subsequent row
, we look at the previous row and replace each occurrence of 0 with 01
, and each occurrence of 1 with 10.

For example, for n = 3, the 1st row is 0, the 2nd row is 01, and the 3rd row is 0110.
Given two integer n and k
, return the kth (1-indexed) symbol in the nth row of a table of n rows.
'''

class Solution:
    def kthGrammar(self, n: int, k: int) -> int:
        def getNthRow(n: int) -> str:
            if n==1:
                return '0'
            else:
                temp = getNthRow(n-1)
                temp2 = ''
                for c in temp:
                    if c=='0':
                        temp2+='01'
                    else:
                        temp2+='10'
                return temp2
        s = getNthRow(n)
        return int(s[k-1])

def main():
    n=25
    k=11
    print(Solution.kthGrammar(Solution(), n, k))

if __name__=='__main__':
    main()
