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

    def push_pop(self, str):
        for c in str:
            if c == '*':
                self.pop()
            else:
                self.push(c)


stack = Stack()
str = 'EAS*Y*QUE***ST***IO*N***'
print(stack.push_pop(str))