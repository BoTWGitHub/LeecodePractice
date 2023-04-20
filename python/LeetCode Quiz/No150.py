'''
Evaluate the value of an arithmetic expression in Reverse Polish Notation.

Valid operators are +, -, *, and /. Each operand may be an integer or another expression.

Note that division between two integers should truncate toward zero.

It is guaranteed that the given RPN expression is always valid.
That means the expression would always evaluate to a result, and there will not be any division by zero operation.
'''

from typing import List

class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        stack = []
        for s in tokens:
            if s.isdigit():
                stack.append(int(s))
            elif s.startswith('-') and s[1:].isdigit():
                stack.append(int(s))
            else:
                b = stack.pop()
                a = stack.pop()
                match s:
                    case '+':
                        stack.append(a+b)
                    case '-':
                        stack.append(a-b)
                    case '*':
                        stack.append(a*b)
                    case '/':
                        stack.append(int(a/b))
        
        return stack[0]

solution = Solution()
#tokens = ["2","1","+","3","*"]
#tokens = ["4","13","5","/","+"]
#tokens = ["10","6","9","3","+","-11","*","/","*","17","+","5","+"]
#tokens = ["4","-2","/","2","-3","-","-"]
tokens = ["-78","-33","196","+","-19","-","115","+","-","-99","/","-18","8","*","-86","-","-","16","/","26","-14","-","-","47","-","101","-","163","*","143","-","0","-","171","+","120","*","-60","+","156","/","173","/","-24","11","+","21","/","*","44","*","180","70","-40","-","*","86","132","-84","+","*","-","38","/","/","21","28","/","+","83","/","-31","156","-","+","28","/","95","-","120","+","8","*","90","-","-94","*","-73","/","-62","/","93","*","196","-","-59","+","187","-","143","/","-79","-89","+","-"]
print(solution.evalRPN(tokens))