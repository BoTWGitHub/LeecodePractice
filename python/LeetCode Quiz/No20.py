'''
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']'
, determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
'''

class Solution:
    def isValid(self, s: str) -> bool:
        opening = ('(', '[', '{')
        temp = []
        for c in s:
            if c in opening:
                temp.append(c)
            else:
                if len(temp)>0:
                    if c == ')'and temp[-1] == '(':
                        temp.pop()
                    elif c == ']' and temp[-1] == '[':
                        temp.pop()
                    elif c == '}' and temp[-1] == '{':
                        temp.pop()
                    else:
                        return False
                else:
                    return False
                
        if temp == []:
            return True
        return False

solution = Solution()
s = '()[]{}'
print(solution.isValid(s))