'''
Given an m x n board of characters and a list of strings words, return all words on the board.

Each word must be constructed from letters of sequentially adjacent cells
, where adjacent cells are horizontally or vertically neighboring. 
The same letter cell may not be used more than once in a word.
'''
from typing import List

class Solution:
    def findWords(self, board: List[List[str]], words: List[str]) -> List[str]:
        def backtrack(r, c, temp, node):
            if not node:
                return
            
            chr = board[r][c]
            if chr not in node.children:
                return
            cur = node.children[chr]
            temp = temp+chr
            if cur.isWord:
                res.append(temp)
                cur.isWord = False
            board[r][c] = ' '
            for dx, dy in [[1,0],[-1,0],[0,1],[0,-1]]:
                nr = r+dx
                nc = c+dy
                if nr>=0 and nr<self.row and nc>=0 and nc<self.col and board[nr][nc] in cur.children:
                    backtrack(nr, nc, temp, cur)
            temp = temp[:-1]
            board[r][c] = chr
            if len(cur.children)==0:
                del node.children[chr]
        self.row = len(board)
        self.col = len(board[0])
        res = []
        self.__root = self.__trie()
        for word in words:
            self.__insertWord(word)
        for i in range(self.row):
            for j in range(self.col):
                backtrack(i, j, '', self.__root)
                if len(self.__root.children)==0:
                    return res
        return res

    def __insertWord(self, word: str):
        cur = self.__root
        for c in word:
            if c not in cur.children:
                cur.children[c] = self.__trie()
            cur = cur.children[c]
        cur.isWord = True
    
    class __trie:
        def __init__(self, isWord: bool = False):
            self.isWord = isWord
            self.children = dict()

def main():
    solution = Solution()

    board = [['a', 'b'], ['c', 'd']]
    words = ['ac', 'abdc']
    print(solution.findWords(board, words))

if __name__=='__main__':
    main()
