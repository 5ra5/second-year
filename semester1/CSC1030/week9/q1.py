import unittest

class Position:

    def __init__(self, key, value, parent=None):
        self.key = key
        self.value = value
        self.parent = parent
        self.left = None
        self.right = None

    def __repr__(self):
        return f"({self.key}, {self.value})"

class BinarySearchTree:

    def __init__(self):
        self.root = None


    def upsert(self, key, val):
        temp = Position(key, val)

        # checking if the root exists, if not add that number as a root
        if self.root is None:
            self.root = temp
            return temp

        current = self.root
        while current is not None:
            if current.key > key and current.left is not None:
                current = current.left
            elif current.key < key and current.right is not None:
                current = current.right
            else:
                break

        if current.key > key:
            current.left = temp
        else:
            current.right = temp

        return self.root

    def first(self):



class BSTTest(unittest.TestCase):

    def test_upsert(self):

        tree = BinarySearchTree()

        for node in [50, 20, 60, 19, 25, 51, 62]:
            tree.upsert(node, f"{node}_val")

        self.assertEqual(50, tree.root.key)

    def test_first(self):

        tree = BinarySearchTree()
        for node in [50, 20, 60, 19, 25, 51, 62]:
            tree.upsert(node, f"{node}_val")

        self.assertEqual(19, tree.first().key)