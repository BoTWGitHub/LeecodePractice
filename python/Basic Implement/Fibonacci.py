class Fibonacci:
    def recursive(self, n: int) -> int:
        if n==0:
            return 0
        if n==1:
            return 1
        return self.recursive(n-2)+self.recursive(n-1)

    def dp_bottom_up(self, n: int) -> int:
        table = [0, 1]
        switch = 0
        for _ in range(n-1):
            temp = table[0] + table[1]
            table[switch] = temp
            switch = 1-switch
        return temp
    
    def dp_top_down(self, n: int) -> int:
        mem = dict()
        def cal(n: int) -> int:
            if n==0 or n==1:
                return n
            if n not in mem:
                mem[n] = cal(n-1) + cal(n-2)
            return mem[n]

        return cal(n)

f = Fibonacci()
print(f.dp_bottom_up(40))