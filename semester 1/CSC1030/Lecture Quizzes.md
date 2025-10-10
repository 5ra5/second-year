# Quiz 1

Q1. What is the primary resource that run-time analysis seeks to minimise?
- Execution time

Q2. Which of these is considered a primitive operation?
- Assigning a value to a variable

Q3. Why are primitive operations assumed to take constant time?
- They correspond to low-level instructions with fixed cost

Q4. Why is average-case analysis often avoided?
- It needs a probability distribution over inputs, which is hard to define

Q5. What is the growth rate of the constant function f(n) = c?
- It grows slower than logarithmic

Q6. Which function represents doing one operation per input element?
- n

Q7. Which complexity class typically describes the fastest possible general sorting algorithms?
- O(n log n)

Q8. Nested loops where each loop runs n times typically have what complexity?
- O(n^2)

Q9. In the polynomial ```f(n) = a0 + a1*n + a2*n + ... + ad*n```, what is d called?
- Degree

Q10. Why are exponential-time algorithms impractical?
 - Their growth rate outpaces feasible input sizes very quickly

Q11. Which function grows slowest as n becomes large?
- log n

Q12. Why might floor and ceiling functions appear in analysis?
- Because logarithms produce non-integers but operation counts must be integers

Q13. What does asymptotic analysis focus on?
- Behaviour for large input sizes?

Q14. What does Big-O represent?
- Upper bound

Q15. If an algorithm runs in O(n) time, what happens if input size doubles?
- Time doubles



# Quiz 2

Q1. Which of the following best defines recursion in computer science?
- A function calling itself during execution

Q2. In the recursive factorial definition, what is the base case?
- n = 0, return 1

Q3. What is the time complexity of recursive factorial(n)?
- O(n)

Q4. In binary search, what happens if the target is smaller than data[mid]?
 - Search continues in the left half.

Q5. What is the time complexity of recursive binary search in a sorted array?
- O(n log n)

Q6. In file system recursion, what defines the problem size n?
-  The number of file-system entries

Q7. The recursive disk_usage  algorithm has which time complexity?
- O(n)

Q8. What does S.top() return in a stack?
- Returns the top element without removing it.

Q9. If a stack is empty, calling pop() will:
- Raise an error

Q10. Which operation adds an element to the back of the queue?
- enqueue

Q11. Which operation removes an element from the front of the queue?
- dequeue

Q12. What principle does a queue follow?
- FIFO

Q13. If a queue is empty, calling dequeue() will:
- Raise an error

Q14. In a deque, what does D.last() do?
- Returns the last element without removing it

Q15. What structure is most suitable to check for palindromes efficiently?
- Deque


# Quiz 3

Q1.  What is a singly linked list?
- A collection of nodes where each node points to the next node in sequence

Q2. What is the tail node in a singly linked list?
- The node whose next reference is None

Q3. What is the process of visiting each node in a linked list called?
- Traversal

Q4. What is required to insert an element at the head of a singly linked list?
- A new node that points to the current head, and the head is updated to this new node.

Q5. When listing at the tail of a singly linked list, the new node's next reference should be:
- None

Q6. Why is removing the last node in a singly linked list inefficient?
- Because the node before the last cannot be accessed directly

Q7.  Which node reference is essential for efficient tail insertion?
- A direct reference to the tail node.

Q8. What is a circularly linked list?
- A linked list where the tail node points back to the head mode.

Q9. What advantage does a linked list have over an array-based list?
- It can grow or shrink dynamically without reallocating memory

Q10. Which of the following is a disadvantage of linked lists compared to arrays?
- They require extra memory for storing references

Q11. Which of the following correctly describes the size attribute in a linked list?
- It tracks the current number of nodes in the list.





