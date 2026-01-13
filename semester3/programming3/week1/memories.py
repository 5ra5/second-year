class Memories(object):
    def __init__(self, name, age=0, salary=0):
        self.name = name
        self.age = age
        self.salary = salary

    def remember(self, attribute):
        x = hasattr(self, attribute)
        if x:
            print(getattr(self, attribute))
        else:
            print(False)