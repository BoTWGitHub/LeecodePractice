from typing import Optional

# Definition for a Node.
class Node:
    def __init__(self, x: int, next: 'Node' = None, random: 'Node' = None):
        self.val = int(x)
        self.next = next
        self.random = random

class Solution:
    def copyRandomList(self, head: 'Optional[Node]') -> 'Optional[Node]':
        if not head:
            return None
        
        #make node-index map with original list
        cur = head
        nodeMap = dict()
        i = 0
        while cur:
            nodeMap[cur] = i
            cur = cur.next
            i+=1

        #make index-node map with copy list
        copy_head = Node(0)
        indexMap = []
        cur = copy_head
        for node in nodeMap:
            cur.next = Node(node.val)
            cur = cur.next
            indexMap.append(cur)
        copy_head = copy_head.next #remove first dummy node

        #link the random pointer by two maps
        cur = head
        cur2 = copy_head
        while cur:
            if cur.random:
                cur2.random = indexMap[nodeMap[cur.random]]
            cur = cur.next
            cur2 = cur2.next

        return copy_head

def printPtrList(head: Node):
    cur = head
    while cur:
        print(f'{cur.val}', end='')
        if cur.random:
            print(f'v{cur.random.val}^', end='')
        print('->', end='')
        cur = cur.next
    print('')

def main():
    head = Node(7, Node(13, Node(11, Node(10, Node(1)))))
    head.next.random = head
    head.next.next.random = head.next.next.next.next
    head.next.next.next.random = head.next.next
    head.next.next.next.next.random = head
    printPtrList(head)

    temp = Solution.copyRandomList(Solution(), head)
    printPtrList(temp)

if __name__=='__main__':
    main()
