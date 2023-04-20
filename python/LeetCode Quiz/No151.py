'''
Given an input string s
, reverse the order of the words.

A word is defined as a sequence of non-space characters.
The words in s will be separated by at least one space.

Return a string of the words in reverse order concatenated by a single space.

Note that s may contain leading or trailing spaces or multiple spaces between two words. 
The returned string should only have a single space separating the words. 
Do not include any extra spaces.
'''

class Solution:
    def reverseWords(self, s: str) -> str:
        res = ''
        left = 0
        while left<len(s):
            if s[left] != ' ':
                right = left+1
                while right<len(s):
                    if s[right] == ' ':
                        if len(res)==0:
                            res = s[left:right]
                        else:
                            res = s[left:right] + ' ' + res
                        left = right
                        break
                    right+=1
                if right==len(s):
                    if len(res)==0:
                        res = s[left:right]
                    else:
                        res = s[left:right] + ' ' + res
                    break
            left+=1
        return res

def main():
    s = "  hello world  "
    res = '_' + Solution.reverseWords(Solution(), s) + '_'
    print(res)

if __name__=='__main__':
    main()
