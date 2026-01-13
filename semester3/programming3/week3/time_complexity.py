#Q1.
def search_q1(Y, n, x):

    for i in range (0, n):
        if Y[i] == x:
            return i
    return -1

Y = ['apple', 'banana', 'mango', 'grapes', 'pineapple', 'durian']
x = "pineapple"

n = len(Y)
result = search_q1(Y, n, x)
if result == -1:
    print("Element is not present in the list")
else:
    print("Element", x, "is present at index", result)

# O(n) - linear
# Justification:
# Code runs in O(n) time because the loop will run maximum n times.
# for i in range(0, n)

#Q2.
def search_q2(X, item):
    first = 0
    last = len(X)-1
    found = False
    while first<=last and not found:
        mid = (first + last)//2
        if X[mid] == item:
            found = True
            print("The element item", item, "was found at index ", X.index(60))
        else:
            if item < X[mid]:
                last = mid - 1
            else:
                first = mid + 1
    return found


print(search_q2([10, 15, 35, 42, 60, 70, 82, 94], 60))

# 0(logn) - logarithmic
# Justification:
# Code runs in O(logn) time because its a binary search. It finds a mid value and
# if that value isn't the one we're looking for it continues with the same process
# which halves the data we're searching every time

#Q3.
test = 0 # 0(1) constant
n = 10 # 0(1) constant
for i in range(n): # runs n times
   test = test + 1 # 0(1)

for j in range(n): # runs n times
   test = test - 1 # 0(1)

# 0(n) - linear
# Justification:
# Code runs in O(n) time because both loops run n times and do
# a constant time operation independently of each other
# O(1) + O(n) + O(n) = O(2n+1) = O(n)

#Q4.
i = n # O(1) - constant
while i > 0: # runs until i = 0
   k = 2 + 2 # O(1) - constant
   i = i // 2 # O(1) - constant

# O(logn) - logarithm
# Justification:
# The program runs until 0 is reached, which is a characteristic of logarithmic time complexity
# while i > 0

#Q5.
mat = [[1, 2, 3], [1, 1, 1], [5, 7, 8]] # O(1)
add = 0 # O(1)
for i in range(len(mat)): # runs n times
    for j in range(len(mat[0])): # runs m times
        add += mat[i][j] # O(1)
print(add)

# O(n^2) - quadratic
# Justification:
# Both loops are affected if n changes, therefore the time complexity
# is O(n^2).
# in this case O(n*m)

#Q6.
def fibonacci(n):
    if n<2:
        return n
    return fibonacci(n-1) + fibonacci(n-2)


for n in range(2,12,2):
    print("Series sum for {} is {}".format(n, fibonacci(n)))

# O(2^n) - exponential
# Justification:
# Fibonacci scripts have exponential time complexity because of its recursive structure
# It doubles the number of calls at each iteration, so the total number of calls would be 2^n.
