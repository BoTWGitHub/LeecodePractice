class MyQueue:
    stacks = []

    def __init__(self):
        self.stacks = []

    def push(self, x: int) -> None:
        self.stacks+=[x]

    def pop(self) -> int:
        if len(self.stacks) == 0:
            return None
        
        temp = self.stacks[0]
        self.stacks = self.stacks[1:]
        return temp

    def peek(self) -> int:
        if len(self.stacks) == 0:
            return None

        return self.stacks[0]

    def empty(self) -> bool:
        if len(self.stacks) == 0:
            return True

        return False

    def output(self):
        print(self.stacks)


obj = MyQueue()
obj.output()

obj.push(3)
obj.output()

obj.push(5)
obj.output()

print(obj.pop())
obj.output()

print(obj.peek())
obj.output()

print(obj.empty())

print(obj.pop())
obj.output()

print(obj.empty())
