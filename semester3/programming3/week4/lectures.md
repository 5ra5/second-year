# Stacks, Queues and Deques

**Stacks**
- Last-in, first-out (LIFO) principle
- We can insert as many object as we want into a stack, but we can only access or remove the most recently inserted object
- Most recently inserted object is located at the "top" of the stack

Add element e to the top of stack S
```
S.push(e)
```

Remove and return the top element of stack S (error if the stack is empty)
```
S.pop()
```

Return a reference to the top element of stack S (error if the stack is empty)
```
S.top()
```
Return True if stack S doesn't contain any elements
```
S.is_empty()
```
Return the number of elements in stack S (in Python we use special method ```__len__```)
```
len(S)
```
