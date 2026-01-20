from multiprocessing import *
import time

def greet2(q, length):
    for i in range(1, length+1):
        print("(child process) Waiting for name", i)
        name = q.get()
        print("(child process) Well, hi", name)

def sendName2():
    q = Queue()

    names = ["Jimmy", "Mary", "Steve", "Ciaran", "Aoife"]
    
    for p in range(len(names)):
        p = Process(target=greet2, args=(q, len(names)))
        p.start()
    
        for name in names:
            time.sleep(5)
            print("(parent process) Ok, I'll send the name")
            q.put(name)

#execute
sendName2()