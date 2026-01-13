def multiply(x, y):
    if x == 0:
        return 0

    if x < 0 and y < 0:
        return multiply(-x, -y)

    return x + multiply(x, y - 1)

multiply(10, 2)
multiply(-51, -4)
multiply(3, 9)