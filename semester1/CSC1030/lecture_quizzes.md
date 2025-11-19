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
- A new node that points to the current head, and the head is updated to this new node

Q5. When listing at the tail of a singly linked list, the new node's next reference should be:
- None

Q6. Why is removing the last node in a singly linked list inefficient?
- Because the node before the last cannot be accessed directly

Q7.  Which node reference is essential for efficient tail insertion?
- A direct reference to the tail node

Q8. What is a circularly linked list?
- A linked list where the tail node points back to the head mode

Q9. What advantage does a linked list have over an array-based list?
- It can grow or shrink dynamically without reallocating memory

Q10. Which of the following is a disadvantage of linked lists compared to arrays?
- They require extra memory for storing references

Q11. Which of the following correctly describes the size attribute in a linked list?
- It tracks the current number of nodes in the list

# Quiz 4

Q1. What is a tree in data structures?
-  A hierarchical structure consisting of nodes connected by edges

Q2. What do we call the topmost node of a tree? 
- The root

Q3. Nodes with no children are called: 
- Leaves (external nodes)

Q4. Two nodes that share the same parent are: 
- Siblings

Q5. What is an edge in a tree?
 - The connection (relationship) between a parent and a child node

Q6. The depth of a node p is defined as:
- The number of ancestors of p (root has depth 0)

Q7. The height of a node p is:
- The length (in edges) of the longest path from p down to a leaf in its subtree

Q8. The height of a tree T equals: 
- The height of its root (longest root-to-leaf path in edges)

Q9. The subtree rooted at a node v contains: 
- v and all of v's descendants

Q10. A path in a tree is: 
- A sequence of nodes where consecutive nodes are connected by an edge

Q11. A binary tree is an ordered tree in which: 
- Each node has at most two children (left and right)

Q12. A proper (full) binary tree is one where: 
- Every internal node has exactly two children

Q13. In any binary tree, the maximum number of nodes at level d is: 
- 2^d

Q14. In a binary tree of height h, the maximum total number of nodes is: 
- 2^(h + 1) - 1

Q15. The minimum height of a binary tree with n nodes (using edges) is: 
- ceil(log2(n+1)) - 1

Q16. Preorder traversal of a (general) tree visits nodes in the order: 
- Root -> children subtrees (left-to-right), recursively

Q17. Inorder traversal is defined for: 
- Binary trees (visit Left -> Root -> Right)

Q18. Breadth-first traversal of a tree is also known as: 
- Level-order traversal

Q19. The time complexity to traverse all nodes of a tree (any DFS/BFS) is: 
- O(n) where n is the number of nodes


# Quiz 5

Q1. In a Binary Search Tree (BST), which property must always hold true for every node? 
- Left child's key < parent's key < right child's key

Q2. Which traversal of a BST visits the nodes in ascending order of their keys? 
- Inorder

Q3, If nodes are inserted into a BST in strictly increasing order, the tree becomes:
- A degenerate tree (linked list)

Q4. The first() node in a BST can be found by:
- Traversing to the leftmost node

Q5. When deleting a node with two children in a BST, it is typically replaced by:
- Its inorder predecessor

Q6. The after(p) function in a BST returns: 
- The next higher node in the inorder traversal

Q7. Searching for a key in a BST of height h runs in: 
- O(h)

Q8. In the BST deletion case where the node has one child, the deleted node is: 
- Replaced directly by its single child

Q9. The correctness of BST operations depends on maintaining: 
- Inorder key ordering

Q10. In recursive insertion into a BST, the unlinking (descent) phase occurs when:
- The recursion descends down the tree following comparisons

Q11. The base case in a recursive BST insertion is reached when: 
- A None (empty) child reference is encountered

Q12. During the relinking (ascent) phase of recursive insertion: 
- Each ancestor reassigns its left or right child to the returned subtree

Q13. If relinking is omitted in recursive BST insertion: 
- The new node will not be connected into the original tree

Q14. Recursive insertion returns the (sub)tree at each step primarily to: 
- Update parent links correctly as recursion unwinds

Q15. An AVL tree satisfies the height-balance property, which requires: 
- The height difference between left and right subtrees of any node is at most 1

Q16. After inserting a node into an AVL tree, which positions can become unbalanced? 
- Only ancestors of the inserted node on the path to the root

Q17. Trinode restructuring for AVL rebalancing accounts for how many rotation patterns? 
- 4

Q18. A right-heavy imbalance in an AVL tree (due to insertion in the right subtree) is corrected using:
- A single left rotation or a right-left double rotation

Q19. The AVL height-balance property guarantees worst-case time for search, insert, and delete of: 
- O(log n)

Q20. Following a deletion in an AVL tree, rebalancing:
- May require checking and fixing multiple nodes up to the root

Q21. The built-in Python dict is an implementation of which abstract data type? 
- Map

Q22. For a well-designed hash table under typical conditions, lookup, insert, and delete run in: 
- O(1) on average

Q23. In a hash table, a collision occurs when: 
- Two keys are mapped to the same bucket index

Q24. A good hash function for a map should be: 
- Deterministic and distribute keys to minimize collisions

Q25. Using the division method, a hash code i is mapped into a table of size N by: 
- i mod N

Q26. Choosing a prime number for the table size N in the division method primarily helps to:
- Reduce systematic collisions from patterns in hash codes

Q27. Compared to simply summing character nodes, a polynomial hash for strings: 
- Accounts for both characters values and their positions

Q28. In a hash table, the compression function is responsible for: 
- Mapping an arbitrary integer hash code into a valid bucket index range

# Quiz 6

Q1. A sorting algorithm is described as in-place if: 
- It sorts data using only a constant amount of extra space

Q2. A stable algorithm ensures that: 
- Equal keys preserve their original relative order

Q3. Which sorting algorithm is stable but not in-place in its typical implementation: 
- Merge sort

Q4. Merge-sort follows which algorithmic paradigm? 
- Divide-and-conquer

Q5. During the divide step of merge-sort, the sequence is split: 
- Into two halves of roughly equal parts

Q6. The combine step in merge-sort requires: 
- O(n)

Q7. The height of the merge-sort recursion tree is approximately: 
- log(n)

Q8. The total running time of merge-sort is:
- O(n log n)

Q9. In quick-sort, the pivot is usually chosen as: 
- The last element

Q10. In the worst case, quick-sort runs in: 
- O(n^2)

Q11.  The best case for quick-sort occurs when: 
- The pivot divides the array evenly at each step

Q12. Insertion sort's worst case arises when: 
- The list is in descending order

Q13. Selection sort repeatedly: 
- Selects the smallest unsorted element and places it at the front

Q14. Bubble sort works by: 
- Swapping adjacent elements that are out of order repeatedly

Q15. Which of the following algorithms does NOT use divide-and-conquer? 
- Selection sort

# Quiz 7

Q1. Bubble sort repeatedly compares: 
- Adjacent elements

Q2. Bubble sort's worst case occurs when: 
- The array is sorted in descending order

Q3. The sorted region in bubble sort grows: 
- From right to left

Q4. Bubble sort is adaptive only if: 
- It uses a swap flag to stop when no swaps occur

Q5. Bucket sort works by: 
- Dividing elements into buckets and sorting each bucket

Q6. For float values in the range (0, 1), a typical bucket index is: 
- int(value * 10)

Q7. Bucket sort's running time depends strongly on: 
- The sorting algorithm used inside each bucket

Q8. Bucket sort performs poorly when: 
- Most values fall into one or two buckets

Q9. Counting sort works by:
- Counting how many times each distinct value occurs

Q10. Counting sort requires auxiliary space proportional to: 
- The number of elements plus the maximum value

Q11. In counting sort, the cumulative count array is used to: 
- Determine the final index for each value in the sorted array

Q12. Counting sort is efficient only when: 
- The maximum value of the same order as the number of elements

Q13. Radix sort typically relies on: 
- Counting sort as a stable subroutine on each digit position

Q14. Radix sort processes digits: 
- From the least significant to the most significant by default

Q15. If counting sort is O(n) and is applied to k digit positions, radix sort runs in: 
- O(n * k)





