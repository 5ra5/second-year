
class TreeNode:
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None
        self.children_lst = []

class Tree:
    def __init__(self, is_binary=True):
        self.root = None
        self.is_binary = is_binary
        self.size = 0

    def set_root(self, val):
        node = TreeNode(val)
        self.root = node
        self.size = 1
        return node

    def is_leaf(self, node):
        if self.is_binary:
            return node.left is None and node.right is None
        return len(node.children_lst) == 0

    def children(self, node):
        if self.is_binary:
            result = []
            if node.left:
                result.append(node.left)
            if node.right:
                result.append(node.right)
            return result
        else:
            return list(node.children_lst)

    def add_child(self, parent, val):
        if self.is_binary:
            raise ValueError("use insert_left/insert_right for binary trees")
        node = TreeNode(val)
        parent.children_lst.append(node)
        self.size += 1
        return node

    def insert_left(self, parent, val):
        if not self.is_binary:
            raise ValueError("use add_child for general trees")
        if parent.left is not None:
            raise ValueError("left already set")
        node = TreeNode(val)
        parent.left = node
        self.size += 1
        return node

    def insert_right(self, parent, val):
        if not self.is_binary:
            raise ValueError("use add_child for general trees")
        if parent.right is not None:
            raise ValueError("right already set")
        node = TreeNode(val)
        parent.right = node
        self.size += 1
        return node

    def preorder(self):
        out = []

        def pre(node):
            if not node:
                return
            out.append(node.val)
            if self.is_binary:
                pre(node.left)
                pre(node.right)
            else:
                for c in node.children_lst:
                    pre(c)

        pre(self.root)
        return out

    def postorder(self):
        out = []

        def post(node):
            if not node:
                return
            if self.is_binary:
                post(node.left)
                post(node.right)
            else:
                for c in node.children_lst:
                    post(c)
            out.append(node.val)

        post(self.root)
        return out

    def inorder(self):
        out = []

        def iin(node):
            if not node:
                return
            if self.is_binary:
                iin(node.left)
                out.append(node.val)
                iin(node.right)
            else:
                if not node.children_lst:
                    out.append(node.val)
                else:
                    iin(node.children_lst[0])
                    out.append(node.val)
                    for c in node.children_lst[1:]:
                        iin(c)
        iin(self.root)
        return out

import unittest

class TestTree(unittest.TestCase):
    def test_binary_tree_structure_and_leaf(self):
        t = Tree(is_binary=True)
        r = t.set_root(10)
        self.assertTrue(t.is_leaf(r))
        l = t.insert_left(r, 5)
        self.assertFalse(t.is_leaf(r))
        self.assertTrue(t.is_leaf(l))
        r2 = t.insert_right(r, 15)
        self.assertEqual([n.val for n in t.children(r)], [5, 15])
        self.assertEqual(t.size, 3)

    def test_binary_traversals(self):
        t = Tree(is_binary=True)
        r = t.set_root(10)
        a = t.insert_left(r, 5)
        b = t.insert_right(r, 15)
        t.insert_left(a, 2)
        t.insert_right(a, 7)
        t.insert_left(b, 12)
        t.insert_right(b, 20)
        self.assertEqual(t.preorder(), [10, 5, 2, 7, 15, 12, 20])
        self.assertEqual(t.inorder(), [2, 5, 7, 10, 12, 15, 20])
        self.assertEqual(t.postorder(), [2, 7, 5, 12, 20, 15, 10])

    def test_binary_enforcement(self):
        t = Tree(is_binary=True)
        r = t.set_root(1)
        with self.assertRaises(ValueError):
            t.add_child(r, 2)
        t.insert_left(r, 2)
        with self.assertRaises(ValueError):
            t.insert_left(r, 3)

    def test_general_tree_structure_and_leaf(self):
        t = Tree(is_binary=False)
        r = t.set_root("A")
        self.assertTrue(t.is_leaf(r))
        b = t.add_child(r, "B")
        c = t.add_child(r, "C")
        d = t.add_child(r, "D")
        self.assertFalse(t.is_leaf(r))
        self.assertTrue(t.is_leaf(b))
        self.assertEqual([n.val for n in t.children(r)], ["B", "C", "D"])
        self.assertEqual(t.size, 4)

    def test_general_traversals(self):
        t = Tree(is_binary=False)
        r = t.set_root("A")
        b = t.add_child(r, "B")
        c = t.add_child(r, "C")
        d = t.add_child(r, "D")
        t.add_child(b, "E")
        t.add_child(b, "F")
        t.add_child(d, "G")
        self.assertEqual(t.preorder(), ["A", "B", "E", "F", "C", "D", "G"])
        self.assertEqual(t.postorder(), ["E", "F", "B", "C", "G", "D", "A"])
        self.assertEqual(t.inorder(), ["E", "B", "F", "A", "C", "G", "D"])

    def test_general_enforcement(self):
        t = Tree(is_binary=False)
        r = t.set_root(1)
        with self.assertRaises(ValueError):
            t.insert_left(r, 2)
        with self.assertRaises(ValueError):
            t.insert_right(r, 3)

if __name__ == "__main__":
    unittest.main()


