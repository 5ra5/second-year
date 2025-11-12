import unittest

class Node:
    def __init__(self, val):
        self.val = val
        self.next = None

class SinglyLinkedList:
    def __init__(self):
        self.head = None
        self.tail = None
        self.size = 0

    def insert_start(self, val):
        node = Node(val)
        if not self.head:
            self.head = node
            self.tail = node
        else:
            node.next = self.head
            self.head = node
        self.size += 1

    def insert_end(self, val):
        node = Node(val)
        # if the list is empty the val is going to be both head and tail
        if not self.head:
            self.head = node
            self.tail = node
        else:
            # traverse to the last position, starting from head
            current = self.head
            while current.next: # while there is a node after the current one
                current = current.next
            # inserting the node
            current.next = node
            self.tail = node

        self.size += 1

    def insert_sorted(self, val):
        node = Node(val)
        # Empty list
        if not self.head:
            self.head = node
            self.tail = node
            self.size += 1
            return node

        # node.val is less than head val
        if node.val < self.head.val:
            node.next = self.head
            self.head = node
            self.size += 1
            return node

        # traversing to find an appropriate position if there is multiple values
        current = self.head
        while current.next and current.next.val < node.val:
            current = current.next
        node.next = current.next
        current.next = node

        # if we get to the last node
        if not node.next:
            self.tail = node
        self.size += 1
        return node

    def display(self):
        output = []
        current = self.head
        while current:
            output.append(str(current.val))
            current = current.next
        return " -> ".join(output)

    def __len__(self):
        return self.size


class TestSinglyLinkedList(unittest.TestCase):

    def setUp(self):
        self.a = SinglyLinkedList()
        self.b = SinglyLinkedList()

    def test_insert_start(self):
        self.a.insert_start(2)
        self.a.insert_start(1)
        self.assertEqual(self.a.head.val, 1)
        self.assertEqual(self.a.tail.val, 2)
        self.assertEqual(len(self.a), 2)
        self.assertEqual(self.a.display(), "1 -> 2")

    def test_insert_end(self):
        self.a.insert_end(1)
        self.a.insert_end(2)
        self.assertEqual(self.a.head.val, 1)
        self.assertEqual(self.a.tail.val, 2)
        self.assertEqual(len(self.a), 2)
        self.assertEqual(self.a.display(), "1 -> 2")

    def test_insert_sorted_into_empty(self):
        n = self.a.insert_sorted(5)
        self.assertEqual(self.a.head, n)
        self.assertEqual(self.a.tail, n)
        self.assertEqual(self.a.display(), "5")
        self.assertEqual(len(self.a), 1)
        n = self.a.insert_sorted(6)
        self.assertEqual(self.a.display(), "5 -> 6")

    def test_insert_sorted_maintains_order(self):
        for v in [10, 5, 20, 15, 8, 8]:
            self.a.insert_sorted(v)
        self.assertEqual(self.a.display(), "5 -> 8 -> 8 -> 10 -> 15 -> 20")
        self.assertEqual(self.a.head.val, 5)
        self.assertEqual(self.a.tail.val, 20)
        self.assertEqual(len(self.a), 6)