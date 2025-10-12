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

    def reverse(self):
        if self.is_empty():
            return
        current = self.dequeue()
        self.reverse()
        self.enqueue(current)
        return self.lst

    def find_min(self):
        if self.is_empty():
            return

        current = self.dequeue()
        if self.is_empty():
            min = current
        else:
            min = self.find_min()
            if current < min:
                min = current
        return min


queue = Queue()
queue.enqueue(1)
queue.enqueue(2)
queue.enqueue(3)
queue.enqueue(4)
queue.enqueue(5)
print(queue.reverse())
print(queue.find_min())


