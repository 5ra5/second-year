import sys

class Deque(object):

    def __init__(self):
        self.lst = []

    def add_last(self, val):
        self.lst.append(val)

    def add_first(self, val):
        self.lst.insert(0, val)

    def first(self):
        return self.lst.pop(0)

    def last(self):
        return self.lst.pop()

    def is_empty(self):
        return len(self.lst) == 0

    def is_palindrome(self):
        while len(self.lst) > 1:
            first = self.first()
            last = self.last()
            if first != last:
                return False
        return True

deque = Deque()
line = sys.stdin.readline()
line = line.strip().lower()
for c in line:
    deque.add_last(c)

print(deque.is_palindrome())

