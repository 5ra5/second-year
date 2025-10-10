def sum_q1(n):
    if n == 0:
        return 0
    return n + sum_q1(n - 1)

print(sum_q1(6))