'''
Implement strStr().

Given two strings needle and haystack, return the index of the first occurrence of needle in haystack
, or -1 if needle is not part of haystack.
'''

class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        if not needle in haystack:
            return -1

        found = False
        for i, c in enumerate(haystack):
            if c==needle[0]:
                found = True
                for j, c2 in enumerate(needle):
                    if haystack[i+j]!=c2:
                        found = False
                        break
                if found:
                    return i


def main():
    haystack = 'aaaaa'
    needle = 'bba'
    print(Solution.strStr(Solution(), haystack, needle))

if __name__=='__main__':
    main()
