import unittest

from q1 import BinarySearchTree

class BSTTest(unittest.TestCase):

    def test_upsert(self):

        tree = BinarySearchTree()

        for node in [50, 20, 60, 19, 25, 51, 62]:
            tree.upsert(node, f"{node}_val")

        self.assertEqual(50, tree.root.key)

    def test_in_order(self):

        tree = BinarySearchTree()
        for node in [50, 20, 60, 19, 25, 51, 62]:
            tree.upsert(node, f"{node}_val")

        self.assertEqual([19, 20, 25, 50, 51, 60, 62], tree.in_order())

    def test_in_order_using_before(self):

        tree = BinarySearchTree()
        for node in [50, 20, 60, 19, 25, 51, 62]:
            tree.upsert(node, f"{node}_val")

        self.assertEqual([19, 20, 25, 50, 51, 60, 62], tree.in_order_using_before())

    def test_in_order_using_after(self):

        tree = BinarySearchTree()
        for node in [50, 20, 60, 19, 25, 51, 62]:
            tree.upsert(node, f"{node}_val")

        self.assertEqual([19, 20, 25, 50, 51, 60, 62], tree.in_order_using_after())

    def test_first(self):

        tree = BinarySearchTree()
        for node in [50, 20, 60, 19, 25, 51, 62]:
            tree.upsert(node, f"{node}_val")

        self.assertEqual(19, tree.first().key)

    def test_last(self):

        tree = BinarySearchTree()
        for node in [50, 20, 60, 19, 25, 51, 62]:
            tree.upsert(node, f"{node}_val")

        self.assertEqual(62, tree.last().key)

    def test_before_has_left(self):

        tree = BinarySearchTree()
        for node in [50, 20, 60, 19, 25, 51, 62]:
            tree.upsert(node, f"{node}_val")

        self.assertEqual(25, tree.before(tree.root).key)

    def test_before_no_left(self):

        tree = BinarySearchTree()
        for node in [50, 20, 60, 19, 25, 51, 62]:
            tree.upsert(node, f"{node}_val")

        node_25 = tree.find(25)
        self.assertEqual("25_val", node_25.value)

        self.assertEqual(20, tree.before(node_25).key)

        node_51 = tree.find(51)
        self.assertEqual("51_val", node_51.value)

        self.assertEqual(50, tree.before(node_51).key)

    def test_after_has_right(self):

        tree = BinarySearchTree()
        for node in [50, 20, 60, 19, 25, 51, 62]:
            tree.upsert(node, f"{node}_val")

        self.assertEqual(51, tree.after(tree.root).key)

    def test_after_no_right(self):

        tree = BinarySearchTree()
        for node in [50, 20, 60, 19, 25, 51, 62]:
            tree.upsert(node, f"{node}_val")

        node_51 = tree.find(51)
        self.assertEqual("51_val", node_51.value)

        self.assertEqual(60, tree.after(node_51).key)

    def test_preorder(self):

        tree = BinarySearchTree()
        for node in [50, 20, 60, 19, 25, 51, 62]:
            tree.upsert(node, f"{node}_val")

        self.assertEqual([50, 20, 19, 25, 60, 51, 62], tree.preorder())

    def test_postorder(self):

        tree = BinarySearchTree()
        for node in [50, 20, 60, 19, 25, 51, 62]:
            tree.upsert(node, f"{node}_val")

        self.assertEqual([19, 25, 20, 51, 62, 60, 50], tree.postorder())

    """
    Testing Delete when Node/Position has zero or one child
    """
    def test_delete_one_child(self):

        tree = BinarySearchTree()
        for node in [50, 20, 60, 19, 18, 17, 25, 51, 62]:
            tree.upsert(node, f"{node}_val")

        node_19 = tree.find(19)

        tree.delete(node_19)

        self.assertEqual([17, 18, 25, 20, 51, 62, 60, 50], tree.postorder())
        self.assertEqual([50, 20, 18, 17, 25, 60, 51, 62], tree.preorder())
        self.assertEqual([17, 18, 20, 25, 50, 51, 60, 62], tree.in_order())

    def test_delete_zero_children(self):

        tree = BinarySearchTree()
        for node in [50, 20, 60, 19, 18, 17, 25, 51, 62]:
            tree.upsert(node, f"{node}_val")

        node_17 = tree.find(17)

        tree.delete(node_17)

        self.assertEqual([18, 19, 25, 20, 51, 62, 60, 50], tree.postorder())
        self.assertEqual([50, 20, 19, 18, 25, 60, 51, 62], tree.preorder())
        self.assertEqual([18, 19, 20, 25, 50, 51, 60, 62], tree.in_order())

    def test_delete_single_root_node(self):

        tree = BinarySearchTree()
        for node in [50]:
            tree.upsert(node, f"{node}_val")

        node_50 = tree.find(50)

        tree.delete(node_50)

        self.assertEqual(None, tree.root)

    def test_delete_root_with_single_left_child(self):

        tree = BinarySearchTree()
        for node in [50, 20]:
            tree.upsert(node, f"{node}_val")

        node_50 = tree.find(50)

        tree.delete(node_50)

        self.assertEqual(20, tree.root.key)

    def test_delete_root_with_single_right_child(self):

        tree = BinarySearchTree()
        for node in [50, 60]:
            tree.upsert(node, f"{node}_val")

        node_50 = tree.find(50)

        tree.delete(node_50)

        self.assertEqual(60, tree.root.key)

    """
    Testing Delete when Node/Position has two children
    """
    def test_delete_two_children(self):

        tree = BinarySearchTree()
        for node in [50, 20, 60, 19, 18, 17, 25, 51, 62]:
            tree.upsert(node, f"{node}_val")

        node_20 = tree.find(20)

        tree.delete(node_20)

        self.assertEqual([17, 18, 25, 19, 51, 62, 60, 50], tree.postorder())
        self.assertEqual([50, 19, 18, 17, 25, 60, 51, 62], tree.preorder())
        self.assertEqual([17, 18, 19, 25, 50, 51, 60, 62], tree.in_order())

    def test_delete_root_two_children(self):

        tree = BinarySearchTree()
        for node in [50, 20, 60, 19, 18, 17, 25, 51, 62]:
            tree.upsert(node, f"{node}_val")

        tree.delete(tree.root)

        self.assertEqual([17, 18, 19, 20, 51, 62, 60, 25], tree.postorder())
        self.assertEqual([25, 20, 19, 18, 17, 60, 51, 62], tree.preorder())
        self.assertEqual([17, 18, 19, 20, 25, 51, 60, 62], tree.in_order())


if __name__ == '__main__':
    unittest.main()
