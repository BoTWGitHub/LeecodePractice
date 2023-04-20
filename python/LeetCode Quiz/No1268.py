from typing import List

class Solution:
    def suggestedProducts(self, products: List[str], searchWord: str) -> List[List[str]]:
        products = sorted(products)
        print(products)
        res = []
        for i in range(len(searchWord)):
            typingWord = searchWord[:i+1]
            suggested = []
            for s in products:
                if s[:i+1]==typingWord:
                    suggested+=[s]
                    if len(suggested)==3:
                        break
            res+=[suggested]

        return res

solution = Solution()
products = ["mobile","mouse","moneypot","monitor","mousepad"]
searchWord = "mouse"

print(solution.suggestedProducts(products, searchWord))