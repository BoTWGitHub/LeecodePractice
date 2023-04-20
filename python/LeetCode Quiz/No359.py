class Logger:
    def __init__(self):
        self.log = {}

    def shouldPrintMessage(self, timestamp: int, message: str) -> bool:
        if message not in self.log:
            self.log[message] = timestamp
            return True
        else:
            if timestamp-self.log[message]>=10:
                self.log[message] = timestamp
                return True
            else:
                return False

logger = Logger()
messages = [[1, "foo"], [2, "bar"], [3, "foo"], [8, "bar"], [10, "foo"], [11, "foo"]]
for message in messages:
    print(logger.shouldPrintMessage(message[0], message[1]))