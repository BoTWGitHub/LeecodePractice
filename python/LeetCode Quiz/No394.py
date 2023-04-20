'''
Given an encoded string, return its decoded string.

The encoding rule is: k[encoded_string]
, where the encoded_string inside the square brackets is being repeated exactly k times. 
Note that k is guaranteed to be a positive integer.

You may assume that the input string is always valid; 
there are no extra white spaces, square brackets are well-formed, etc. 
Furthermore, you may assume that the original data does not contain any digits 
and that digits are only for those repeat numbers, k. 
For example, there will not be input like 3a or 2[4].

The test cases are generated so that the length of the output will never exceed 10^5.
'''
class Solution:
    def decodeString(self, s: str) -> str:
        stack = []
        for c in s:
            if c != ']':
                stack.append(c)
            else:
                found = False
                temp_s = ''
                temp_num = ''
                while stack:
                    if not found:
                        if stack[-1]!='[':
                            temp_s = stack.pop() + temp_s
                        else:
                            found = True
                            stack.pop()
                    else:
                        if stack[-1].isdigit():
                            temp_num = stack.pop() + temp_num
                        else:
                            stack.append(temp_s*int(temp_num))
                            break
                if not stack:
                    stack.append(temp_s*int(temp_num))

        return ''.join(stack)

def main():
    solution = Solution()

    s = '3[z]2[2[y]pq4[2[jk]e1[f]]]ef'
    ans = 'zzzyypqjkjkefjkjkefjkjkefjkjkefyypqjkjkefjkjkefjkjkefjkjkefef'
    res = solution.decodeString(s)

    print('PASS' if res==ans else 'FAIL')

if __name__=='__main__':
    main()
