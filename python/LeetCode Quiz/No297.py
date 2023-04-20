'''
Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer
, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.

Design an algorithm to serialize and deserialize a binary tree. 
There is no restriction on how your serialization/deserialization algorithm should work. 
You just need to ensure that a binary tree can be serialized to a string and this string can be deserialized to the original tree structure.
'''
# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x, left=None, right=None):
        self.val = x
        self.left = left
        self.right = right

class Codec:

    def serialize(self, root):
        """Encodes a tree to a single string.
        
        :type root: TreeNode
        :rtype: str
        """
        if not root:
            return ',N'
        return ',' + str(root.val) + self.serialize(root.left) + self.serialize(root.right)

    def deserialize(self, data):
        """Decodes your encoded data to tree.
        
        :type data: str
        :rtype: TreeNode
        """
        self._decode = []
        while data:
            data = data[1:]
            if ',' in data:
                self._decode.append(data[:data.index(',')])
                data = data[data.index(','):]
            else:
                self._decode.append(data)
                data = []
        
        def builder():
            if self._decode:
                c = self._decode.pop(0)
                if c == 'N':
                    return None
                else:
                    return TreeNode(c, builder(), builder())
        return builder()

def main():
    codec = Codec()

    root = TreeNode(4, TreeNode(-7), TreeNode(-3, TreeNode(-9, TreeNode(9, TreeNode(6, TreeNode(0, None, TreeNode(-1)), TreeNode(6, TreeNode(-4)))), TreeNode(-7, TreeNode(-6, TreeNode(5)), TreeNode(-6, TreeNode(9, TreeNode(-2))))), TreeNode(-3, TreeNode(-4))))

    encode = codec.serialize(root)
    print(encode)
    root2 = codec.deserialize(encode)
    print(codec.serialize(root2))
    

if __name__=='__main__':
    main()
