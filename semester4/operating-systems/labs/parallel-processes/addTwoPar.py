from multiprocessing import *
import time

def addTwoNumbers(a, b, q):
    time.sleep(5) # In case you want to slow things down to see what is happening.
    q.put(a+b)

def addTwoPar():
    x = eval(input("Enter first number: "))
    y = eval(input("Enter second number: "))

    q = Queue()
    p1 = Process(target=addTwoNumbers, args=(x, y, q))
    p1.start()
    print("(parent process) get the result")
    result = q.get()

    p1.join()
    print(result)
    print("Done!")

addTwoPar()