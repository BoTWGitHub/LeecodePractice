'''
Given a reference of a node in a connected undirected graph.

Return a deep copy (clone) of the graph.
'''

# Definition for a Node.
class Node:
    def __init__(self, val = 0, neighbors = None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []

class Solution:
    def cloneGraph(self, node: 'Node') -> 'Node':
        if not node:
            return node
        def dfsNode(node: 'Node', clone: 'Node', seen: dict):
            clone.val = node.val
            seen[node] = clone
            for i, n in enumerate(node.neighbors):
                if n not in seen:
                    clone.neighbors.append(Node(n.val))
                    dfsNode(n, clone.neighbors[i], seen)
                else:
                    clone.neighbors.append(seen[n])

        clone = Node(node.val)
        seen = dict()
        dfsNode(node, clone, seen)
        return clone

solution = Solution()
node = Node(1, [Node(2), Node(4)])
node2 = node.neighbors[0]
node4 = node.neighbors[1]
node2.neighbors = [Node(3, [node4, node2]), node]
node4.neighbors = [node, node2]

res = solution.cloneGraph(node)

def printNode(node: Node, seen: set):
    print(node.val, '->')
    seen.add(node)
    for n in node.neighbors:
        if n not in seen:
            printNode(n, seen)
    print('<-')

seen = set()
printNode(res, seen)