def insert(str, buckets):
    n = len(str)
    p = 31 # prime number
    hash_code = 0
    pow = 1
    for i in range(n):
        hash_code = (hash_code + (ord(str[i]))^pow) % 101
        pow = (pow * p) % 101
    index = hash_code % 10
    buckets[index].append(str)

