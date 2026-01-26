from multiprocessing import *

def sayHi2(n):
    print("Hi", n, "from process", current_process().pid)

def greetings():
    name = str(input("Type in your name: "))
    process = int(input("How many greetings you want: "))

    for proc in range(process):
        proc = Process(target=sayHi2, args=(name,))
        proc.start()

greetings()
