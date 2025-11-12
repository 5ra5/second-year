import unittest

class Node:
    def __init__(self,val):
        self.val = val
        self.next = None

class SinglyLinkedList:

    def __init__(self):
        self.head = None
        self.tail = None
        self.size = 0

    def insert_start(self, val):
        newest = Node(val)
        if not self.head:
            self.head = newest
            self.tail = newest
        else:
            newest.next = self.head
            self.head = newest
        self.size = self.size + 1

    def insert_end(self, val):
        newest = Node(val)
        if not self.head:
            self.head = newest
            self.tail = newest
        else:
            current = self.head
            while current:
                current = current.next
            newest.next = None
            self.tail.next = newest
            self.tail = newest
        self.size = self.size + 1

    def insert_sorted(self, val):
        newest = Node(val)
        # If Linked List is empty
        if not self.head:
            self.head = newest
            self.tail = newest
            self.size = self.size + 1
            return newest

        # If newest.val < self.head
        elif newest.val < self.head.val:
            newest.next = self.head
            self.head = newest
            self.size = self.size + 1
            return newest

        # Find a node that has a value greater than new value
        # Insert before that value
        current = self.head
        while current.next and newest.val > current.next.val:
            current = current.next
        newest.next = current.next
        current.next = newest

        # Inserting at the end
        if not newest.next:
            self.tail = newest

        self.size = self.size + 1
        return newest

    def remove_start(self):
        if self.size == 1:
            self.head = None
            self.tail = Non

    def is_empty(self):
        if not self.head:
            return True
        return False

    def __len__(self):
        return self.size

    def display(self):
        output = []
        current = self.head
        while current:
            output.append(str(current.val))
            current = current.next
        return " -> ".join(output)


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

    def test_remove_start_single(self):
        self.a.insert_end(7)
        v = self.a.remove_start()
        self.assertEqual(v, 7)
        self.assertTrue(self.a.is_empty())
        self.assertIsNone(self.a.head)
        self.assertIsNone(self.a.tail)