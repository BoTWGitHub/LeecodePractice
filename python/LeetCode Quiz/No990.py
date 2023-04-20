'''
You are given an array of strings equations that represent relationships between variables 
where each string equations[i] is of length 4 and takes one of two different forms: "xi==yi" or "xi!=yi".
Here, xi and yi are lowercase letters (not necessarily different) that represent one-letter variable names.

Return true if it is possible to assign integers to variable names so as to satisfy all the given equations, or false otherwise.
'''
from typing import List

class Solution:
    def equationsPossible(self, equations: List[str]) -> bool:
        lowercase = 'abcdefghijklmnopqrstuvwxyz'
        graph = dict()
        for c in lowercase:
            graph[c] = set()
        checkList = []
        for i, s in enumerate(equations):
            if s[1]=='!':
                if s[0]==s[3]:
                    return False
                else:
                    checkList.append(i)
            else:
                if s[0]!=s[3]:
                    graph[s[0]].add(s[3])
                    graph[s[3]].add(s[0])
        # all the same letter will be in the same group

        checkMap = dict()
        for c in lowercase:
            checkMap[c] = c
        def dfs(node, c):
            if checkMap[node]==node:
                checkMap[node] = c
                for nei in graph[node]:
                    dfs(nei, c)
        for c in lowercase:
            if checkMap[c]==c:
                dfs(c, c)
        # make a map for letter to replaced the min letter in the same group
                
        for i in checkList:
            s = equations[i]
            if checkMap[s[0]]==checkMap[s[3]]:
                return False
        return True

def main():
    solution = Solution()

    equations = ["b!=f","c!=e","f==f","d==f","b==f","a==f"]
    print(solution.equationsPossible(equations))

if __name__=='__main__':
    main()
