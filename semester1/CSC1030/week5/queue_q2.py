class Queue:
    def __init__(self):
        self.lst = []

    def enqueue(self, value):
        self.lst.append(value)

    def dequeue(self):
        return self.lst.pop(0)

    def first(self):
        return self.lst[0]

    def is_empty(self):
        return len(self.lst) == 0

    def binary(self, n):
        output = []

        if self.is_empty():
            self.enqueue('1')

        for i in range(n):
            current = self.dequeue()
            output.append(current)

            self.enqueue(current + '0')
            self.enqueue(current + '1')

        return ' '.join(output)


queue = Queue()
print(queue.binary(16))