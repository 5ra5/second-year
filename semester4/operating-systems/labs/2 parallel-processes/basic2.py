from multiprocessing import *

def sayHi():
    print("Hi from process", current_process().pid)

def procEx():
    print("Hi from process", current_process().pid, "(parent process)")

    proc1 = Process(target=sayHi, args=())
    proc2 = Process(target=sayHi, args=())
    proc3 = Process(target=sayHi, args=())

    proc1.start()
    proc2.start()
    proc3.start()

procEx()