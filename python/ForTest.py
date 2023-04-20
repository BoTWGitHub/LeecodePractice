class Test:
    def __init__(self, temp: int):
        self.__temp = temp

    def func1(self, a, b):
        def insideFunc():
            self.__temp = a+b
        insideFunc()
        return a+b+self.__temp

test = Test(3)
print(test.func1(1,4))
print(test.__temp)