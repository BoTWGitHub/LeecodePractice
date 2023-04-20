from typing import List

class Solution:
    def minimumLengthEncoding(self, words: List[str]) -> int:
        if len(words)==1:
            return len(words[0])+1
            
        words = sorted(words, key=len, reverse=True)
        
        res = len(words[0])+1
        temp = {}
        temp[words[0]] = 1
        for i in range(1, len(words)):
            if words[i] not in temp:
                find = False
                for word in temp:
                    if word.endswith(words[i]):
                        find = True
                        break
                if not find:
                    res+=(len(words[i])+1)
                    temp[words[i]]=1
        
        return res

solution = Solution()
words = ['me', 'time']#['time', 'me', 'bell']
print(solution.minimumLengthEncoding(words))