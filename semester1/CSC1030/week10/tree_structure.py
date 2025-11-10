class TreeNode:
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None
        self.children = []
        size = 0

class Tree:
    def __init__(self, is_binary=True):
        self.is_binary = is_binary
        self.root = None

    def set_root(self, val):
        self.root = val
        return self.root

    def is_leaf(self, node):
        node = TreeNode(node)
        if node.children:
            return False
        return True

    def children(self, node):
        return node.children

    def add_child(self, parent, val):
        if self.is_binary:
            raise ValueError("use insert_left/insert_right for binary trees")
        node = TreeNode(parent)
        node.children.append(val)
        return node.children

t = Tree(is_binary=False)
r = t.set_root("A")
b = t.add_child(r, "B")
c = t.add_child(r, "C")
d = t.add_child(r, "D")
