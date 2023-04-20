'''
Given an array of strings words and a width maxWidth
, format the text such that each line has exactly maxWidth characters and is fully (left and right) justified.

You should pack your words in a greedy approach; that is
, pack as many words as you can in each line. Pad extra spaces ' ' when necessary 
so that each line has exactly maxWidth characters.

Extra spaces between words should be distributed as evenly as possible. 
If the number of spaces on a line does not divide evenly between words
, the empty slots on the left will be assigned more spaces than the slots on the right.

For the last line of text, it should be left-justified, and no extra space is inserted between words.

Note:

    A word is defined as a character sequence consisting of non-space characters only.
    Each word's length is guaranteed to be greater than 0 and not exceed maxWidth.
    The input array words contains at least one word.
'''

from typing import List

class Solution:
    def fullJustify(self, words: List[str], maxWidth: int) -> List[str]:
        res = []
        
        temp = []
        lenSum = 0
        for word in words:
            if lenSum + len(word) <= maxWidth:
                #not reach the maxWidth yet, put words in temp list
                temp.append(word)
                lenSum+=(len(word)+1)
            else:
                #reach the maxWidth, count the spaces in between the words
                wordLen = 0
                wordCount = 0
                for w in temp:
                    wordLen+=len(w)
                    wordCount+=1
                spaceCount = wordCount-1
                if spaceCount > 0:
                    spaces = [(maxWidth-wordLen)//spaceCount]*spaceCount
                    extraSpace = (maxWidth-wordLen)%spaceCount
                    for i in range(len(spaces)):
                        if extraSpace>0:
                            spaces[i]+=1
                            extraSpace-=1
                        else:
                            break
                else:
                    spaces = [(maxWidth-wordLen)]

                #make the string for anwser
                tempStr = ''
                for w in temp:
                    tempStr+=w
                    if len(spaces)>0:
                        tempStr+=' '*spaces.pop(0)
                res.append(tempStr)

                #add word into temp list since this one havn't used
                lenSum = len(word)+1
                temp.clear()
                temp.append(word)
        
        if len(temp)>0:
            tempStr = ''
            wordLen = 0
            for w in temp:
                wordLen+=len(w)+1
                tempStr+=(w+' ')
            tempStr = tempStr[:-1]
            spaces = maxWidth-wordLen+1
            tempStr+=' '*spaces
            res.append(tempStr)            

        return res

solution = Solution()
#words = ["This", "is", "an", "example", "of", "text", "justification."]
words = ["What","must","be","acknowledgment","shall","be"]
maxWidth = 16
print(solution.fullJustify(words, maxWidth))