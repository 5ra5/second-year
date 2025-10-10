import sys

class Stack(object):
    def __init__(self):
        self.lst = []

    def push(self, val):
        self.lst.append(val)

    def pop(self):
        return self.lst.pop()

    def top(self):
        return self.lst[len(self.lst) - 1]

    def is_empty(self):
        return len(self.lst) == 0

    def print_stack(self):
        print(self.lst)

    def reverse(self):
        rev = ""
        while not self.is_empty():
            rev += self.lst.pop()
        return rev

stack = Stack()
line = sys.stdin.readline()
for s in line:
    stack.push(s)

print(stack.reverse())