class MyLinkedList:

    class ListNode:
        def __init__(self, val, next: "MyLinkedList.ListNode"= None):
            self.val = val
            self.next = next

    def __init__(self):
        self.head : MyLinkedList.ListNode = None

    def get(self, index: int) -> int:
        if not self.head:
            return -1
        count = 0
        cur = self.head
        while cur.next and count<index:
            cur = cur.next
            count+=1
        if count==index:
            return cur.val
        return -1

    def addAtHead(self, val: int) -> None:
        self.head = self.ListNode(val, self.head)

    def addAtTail(self, val: int) -> None:
        if not self.head:
            self.head = self.ListNode(val)
        else:
            cur = self.head
            while cur.next:
                cur = cur.next
            cur.next = self.ListNode(val)

    def addAtIndex(self, index: int, val: int) -> None:
        if index==0:
            if not self.head:
                self.head = self.ListNode(val)
            else:
                self.head = self.ListNode(val, self.head)
        if not self.head:
            return
        count = 0
        cur = self.head
        while cur.next and count<index-1:
            cur = cur.next
            count+=1
        if count==index-1:
            node = self.ListNode(val)
            node.next = cur.next
            cur.next = node

    def deleteAtIndex(self, index: int) -> None:
        if not self.head:
            return
        if index==0:
            self.head = self.head.next
            return
        count = 0
        cur = self.head
        while cur.next and count<index-1:
            cur = cur.next
            count+=1
        if count==index-1 and cur.next:
            cur.next = cur.next.next
    
    def printList(self):
        cur = self.head
        print('===print list===')
        while cur:
            print(f' {cur.val} ->', end='')
            cur = cur.next
        print('\n===print done===\n')


# Your MyLinkedList object will be instantiated and called as such:
# obj = MyLinkedList()
# param_1 = obj.get(index)
# obj.addAtHead(val)
# obj.addAtTail(val)
# obj.addAtIndex(index,val)
# obj.deleteAtIndex(index)

def main():
    testList = MyLinkedList()

    testList.addAtIndex(0, 10)
    testList.printList()
    
    testList.addAtIndex(0, 20)
    testList.printList()

    testList.addAtIndex(1, 30)
    testList.printList()

    print(testList.get(0))

if __name__=='__main__':
    main()