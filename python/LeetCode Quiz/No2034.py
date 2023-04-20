'''
You are given a stream of records about a particular stock. 
Each record contains a timestamp and the corresponding price of the stock at that timestamp.

Unfortunately due to the volatile nature of the stock market, the records do not come in order. 
Even worse, some records may be incorrect. 
Another record with the same timestamp may appear later in the stream correcting the price of the previous wrong record.
'''

from sortedcontainers import SortedDict

class StockPrice:

    def __init__(self):
        self.__records = {}
        self.__latest = 0
        self.__priceMap = SortedDict()

    def update(self, timestamp: int, price: int) -> None:
        self.__latest = max(self.__latest, timestamp)
        if timestamp in self.__records:
            oldPrice = self.__records[timestamp]
            self.__priceMap[oldPrice]-=1

            if self.__priceMap[oldPrice]==0:
                del self.__priceMap[oldPrice]
        
        self.__records[timestamp] = price
        if price in self.__priceMap:
            self.__priceMap[price]+=1
        else:
            self.__priceMap[price]=1 

    def current(self) -> int:
        return self.__records[self.__latest]

    def maximum(self) -> int:
        return self.__priceMap.peekitem(-1)[0]

    def minimum(self) -> int:
        return self.__priceMap.peekitem(0)[0]
        
stock = StockPrice()
stock.update(1, 10)
stock.update(2, 5)
print(stock.current())
print(stock.maximum())
stock.update(1, 3)
print(stock.maximum())
stock.update(4, 2)
print(stock.minimum())










