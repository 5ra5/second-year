from multiprocessing import *

def dig(lock, name, ID):
    lock.acquire()

    print("Hiddy-ho!    I'm worker", name, "and today I have to dig hole", ID)
    lock.release()

def assignDiggers():
    lock1 = Lock()
    names = ["A", "B", "C", "D", "E", "F", "G", "H", "I", "J"]

    for ID in range(len(names)):
        process = Process(target=dig, args=(lock1, names[ID], ID)).start()

assignDiggers()