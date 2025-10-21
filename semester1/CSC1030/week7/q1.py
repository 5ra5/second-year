import unittest

class Node:
    def __init__(self, val, next=None):
        self.val = val # data
        self.next = next # pointer to the next node

    def get_next(self):
        return self.next

    def set_next(self, next):
        self.next = next

    def get_val(self):
        return self.val

    def set_val(self, val):
        self.val = val

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

        return node.get_val()

    def insert_end(self, val):
        pass

    def insert_sorted(self, val):
        pass

    def remove_start(self):
        pass

    def remove_end(self):
        if self.size == 0:
            return None

        if self.head == self.tail:
            node = self.head
            self.head = None
            self.tail = None
            self.size -= 1
            return node

        current = self.head
        while current.next.next:
            current = current.next

        node = current.next
        current.next = None
        self.tail = current
        self.size -= 1

        return node


    def find(self, val):
        node = self.head
        while node:
            if node.get_val() == val:
                return node
            else:
                node = node.get_next()
        return None


    def is_empty(self):
        return self.size == 0

    def __len__(self):
        return self.size

    def display(self):
        pass


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

    def test_remove_start_empty(self):
        self.assertIsNone(self.a.remove_start())
        self.assertEqual(len(self.a), 0)

    def test_remove_start_single(self):
        self.a.insert_end(7)
        v = self.a.remove_start()
        self.assertEqual(v, 7)
        self.assertTrue(self.a.is_empty())
        self.assertIsNone(self.a.head)
        self.assertIsNone(self.a.tail)

    def test_remove_start_multiple(self):
        for v in [1, 2, 3]:
            self.a.insert_end(v)
        v = self.a.remove_start()
        self.assertEqual(v, 1)
        self.assertEqual(self.a.display(), "2 -> 3")
        self.assertEqual(self.a.head.val, 2)
        self.assertEqual(self.a.tail.val, 3)
        self.assertEqual(len(self.a), 2)

    def test_remove_end_empty(self):
        self.assertIsNone(self.a.remove_end())
        self.assertEqual(len(self.a), 0)

    def test_remove_end_single(self):
        self.a.insert_start(9)
        v = self.a.remove_end()
        self.assertEqual(v, 9)
        self.assertTrue(self.a.is_empty())
        self.assertIsNone(self.a.head)
        self.assertIsNone(self.a.tail)

    def test_remove_end_multiple(self):
        for v in [1, 2, 3]:
            self.a.insert_end(v)
        v = self.a.remove_end()
        self.assertEqual(v, 3)
        self.assertEqual(self.a.display(), "1 -> 2")
        self.assertEqual(self.a.head.val, 1)
        self.assertEqual(self.a.tail.val, 2)
        self.assertEqual(len(self.a), 2)

    def test_find_found(self):
        for v in [4, 5, 6]:
            self.a.insert_end(v)
        n = self.a.find(5)
        self.assertIsNotNone(n)
        self.assertEqual(n.val, 5)

    def test_find_not_found(self):
        for v in [1, 2, 3]:
            self.a.insert_end(v)
        self.assertIsNone(self.a.find(99))

    def test_is_empty(self):
        self.assertTrue(self.a.is_empty())
        self.a.insert_end(1)
        self.assertFalse(self.a.is_empty())
        self.a.remove_start()
        self.assertTrue(self.a.is_empty())

    def test_len(self):
        self.assertEqual(len(self.a), 0)
        for v in [1, 2, 3, 4]:
            self.a.insert_end(v)
        self.assertEqual(len(self.a), 4)
        self.a.remove_end()
        self.assertEqual(len(self.a), 3)

    def test_display(self):
        self.assertEqual(self.a.display(), "")
        for v in [1, 3, 2]:
            self.a.insert_end(v)
        self.assertEqual(self.a.display(), "1 -> 3 -> 2")

if __name__ == "__main__":
    unittest.main()