from typing import List

class Solution:
    _morseTable = [".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."]
    def uniqueMorseRepresentations(self, words: List[str]) -> int:
        def strToMorse(word: str) -> str:
            res = ''
            for c in word:
                res+=self._morseTable[ord(c)-ord('a')]
            return res
        mem = set()
        for word in words:
            mem.add(strToMorse(word))
        return len(mem)

def main():
    words = ["gin","zen","gig","msg"]
    print(Solution.uniqueMorseRepresentations(Solution(), words))

if __name__=='__main__':
    main()