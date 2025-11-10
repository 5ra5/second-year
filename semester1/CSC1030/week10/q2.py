# Part 1
def hashing_function(value):
    hsum = 0
    for char in value:
        hsum += ord(char)

    return hsum

# Part 2
def compression(value):
    buckets = [[] for _ in range(10)]
    index = hashing_function(value) % 11
    buckets[index] = value
    return buckets

# Part 3
def insert(str, buckets):
    hash_sum = 0
    for char in str:
        hash_sum += ord(char)

    index = hash_sum % 10
    buckets[index].append(str)
