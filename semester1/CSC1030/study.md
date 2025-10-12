# Quiz
Q1. When analysing the time complexity  of a method that loops over a list of n items, what aspect is the most crucial?
- Number of loops that depend on n.

Q2. What is the time complexity of the following function?
```
def multiply_all(lst):
    total = 1
    for i in lst:
        for j in lst:
            total *= i * j
    return total

```
- O(n^2) - quadratic

Q3. Given the method below, if there are n students, what is the time complexity?
```
def process_students(students):
    for s in students:
        print(s)
    print("Done")

```
- Linear

Q4. What is the time complexity of splitting by a delimiter? For example:
```
"John-Smith-5551234".split('-')
```
- Linear

Q5. What is the complexity of the pop() operation for a Python list used as a stack?
- O(1)
- Removing the last element of a list is a constant-time operation
- pop(0) (removing from the front) would be O(n) because all elements need to be shifted

Q6. What is the base case for a recursive function?
- The condition that stops further recursive calls

Q7. Complete the code to reverse a string recursively:
```
def reverse_string(s):
    if len(s) == 0:
        return s
    else:
        return __________

```
 ```
  reverse_string(s[1:] + s[0])
  ```

Q8. What is the time complexity of the recursive Fibonacci function below?
```
def fib(n):
    if n <= 1:
        return n
    else:
        return fib(n-1) + fib(n-2)

```
- O(2^n)

Q9. What will the following recursive function print?
Call: mystery(3)
```
def mystery(n):
    if n == 0:
        return
    print(n)
    mystery(n-1)

```
- 3 2 1


Q10. What is the return value of sum_digits(1234) in the following function?
```
def sum_digits(n):
    if n == 0:
        return 0
    return (n % 10) + sum_digits(n // 10)
```
-  10

Q11. Which of the following follows the **LIFO** principle?
- Stack

Q12. What is the output?
```
from collections import deque
dq = deque([1, 2, 3])
dq.appendleft(0)
dq.pop()
print(dq)
```
```
[0, 1, 2]
```

Q13. What is the time complexity of adding an element to the rear of a deque in Python?
- O(1)

Q14. Which operation is *not* typical in a **queue** data structure?
- Access element by index

Q15. What is the time complexity of this function?
```
FUNCTION is_palindrome(word):
    CREATE empty deque
    FOR each letter in word:
        ADD letter to rear of deque
    WHILE deque has more than one character:
        IF front ≠ rear:
            RETURN False
        REMOVE front and rear
    RETURN True
```
-  Linear

# time complexity

```
def power_list(lst):
    result = []
    for num in lst:
        val = 1
        for i in range(5):
            val *= num
        result.append(val)
    return result

-> O(n) - linear
```

```
def repeat(n):
    if n <= 1:
        return 1
    return repeat(n-1) + repeat(n-1)

-> O(2^n) - exponential
```

```
for i in range(n):
    for j in range(i, n):
        print(i, j)
-> O(n^2) - quadratic
```

```
def repeated_multiply(lst):
    for x in lst:
        for y in lst:
            for z in range(3):
                print(x*y*z)
-> O(n^2) - quadratic
```

```
def nested(n):
    if n <= 1:
        return 1
    nested(n-1)
    nested(n-1)
-> O(2^n) - exponential
```

```
for i in range(n):
    j = 1
    while j < n:
        j = j * 2
-> O(n log n)
```
# recursion

- Compute the sum of all numbers from 1 to n:
```
def sum_n(n):
    if n == 0:
        return 0
    else:
        return n + sum_n(n-1)
```

- What is the output?
```
def func(n):
    if n == 0:
        return
    print(n)
    func(n-2)
-> 5 3 1
```

- Calculate the factorial of n:
```
def factorial(n):
    if n == 0:
        return 1
    else:
        return n * factorial(n-1)

```

- Calculate the sum of the digits of n:
```
def sum_digits(n):
    if n == 0:
        return 0
    else:
        return n % 10 + sum_digits(n//10)
```

# pseudo code

-  Using the Stack class write an algorithm that will reverse the following string: "bus"
```
CLASS Stack():
	DEFINE __init__(self):
		initialise empty list self.lst
		
	DEFINE push(self, value):
		append the value at the end of the list
		
	DEFINE pop(self):
		return and remove the value at the end of the list
		
	DEFINE top(self):
		return the value at the end of the list without removing it
		
	DEFINE is_empty(self):
		return True if the length of self.lst is 0, otherwise return False
		
	DEFINE reverse(self):
		initialise an empty string reversed
		if self.is_empty is true:
			return none
		else pop the last element in the list and add it to the reversed string
		return reversed string
		
```