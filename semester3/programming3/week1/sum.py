def q1_sum(l):
    evens = []
    for item in l:
       evens += [i for i in item if i % 2 == 0]
    print(sum(evens))