'''
The abbreviation of a word is a concatenation of its first letter
, the number of characters between the first and last letter
, and its last letter. 

If a word has only two characters, then it is an abbreviation of itself.
'''
from typing import List

class ValidWordAbbr:

    def __init__(self, dictionary: List[str]):
        self._mem = dict()
        for word in dictionary:
            temp = self._abbreviation(word)
            if temp not in self._mem:
                self._mem[temp] = {word}
            else:
                self._mem[temp].add(word)

    def isUnique(self, word: str) -> bool:
        temp = self._abbreviation(word)
        if temp not in self._mem:
            return True
        else:
            if len(self._mem[temp])==1 and list(self._mem[temp])[0]==word:
                return True
        return False

    def _abbreviation(self, word: str) -> str:
        if len(word)<=2:
            return word
        return word[0] + str(len(word[1:-1])) + word[-1]

def main():
    pass

if __name__=='__main__':
    main()

