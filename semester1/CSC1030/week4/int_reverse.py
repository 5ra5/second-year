def n_reverse(n, i=0):
    if n == 0:
        return i

    last = n % 10
    previous = n // 10
    i = i * 10 + last
    return n_reverse(previous, i)

print(n_reverse(123))