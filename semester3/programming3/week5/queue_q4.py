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

    def enqueue_dequeue(self, str):
        dequeued = []
        for c in str:
            if c == "*":
                dequeued.append(self.dequeue())
            else:
                self.enqueue(c)
        return dequeued


queue = Queue()
str = 'EAS*Y*QUE***ST***IO*N***'
print(queue.enqueue_dequeue(str))
