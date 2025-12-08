## `upsert(key)` - Insert or update a node

1.  Start at the root of the binary search tree.
2.  Compare the **key** to the current node's key. If the key is **less**, go to the **left child**. If the key is **greater**, go to the **right child**. If the key is **equal**, **update the node's value**
3.  If the position to go (left or right) is **None**, create a **new node** with the key and the value, and set its **parent pointer** to the current node.
4. Recursively continue this process until the new node is inserted or an existing node is updated.
5. On recursion unwind, **reconnect the parent's left or right child** to the returned subtree.
6. Return the **current node** to maintain the tree structure.
```python
def upsert(self, key, value):
        """Insert or update a node with key/value"""
        def _upsert(node, key, value, parent=None):
            if node is None:
                return Position(key, value, parent)
            if key < node.key:
                node.left = _upsert(node.left, key, value, node)
            elif key > node.key:
                node.right = _upsert(node.right, key, value, node)
            else:
                node.value = value  # update existing
            return node

        self.root = _upsert(self.root, key, value)
```

## `first()` - Find the node with the smallest key

1. Start at the root.
2.  Check if the node has a **left child**. If yes, move to the **left child**. If no, this node is the **smallest** and we return it.
3.  Repeat step 2 **recursively** until the leftmost node is reached.
4. Return this node.
**Note**: The smallest node has no left child and is the first node in the inorder traversal.

```python
def first(self):
	if not self.root:
		return None
		
	def _first(node):
		if not node.left:
			return node
		return _first(node.left)
		
	return _first(self.root)
```

## `last()` - Find the node with the largest key

1. Start at the **root**.
2. Check if the node has a right child. If yes, move to the right child. If no, this node is the largest and we return it.
3. Repeat step 2 recursively until the rightmost node is reached.
4. Return this node.
**Note:** The largest node has no right child and is the last node in the inorder traversal.
```python
def last(self):
	if not self.root:
		return None
		
	def _last(node):
		if not node.right:
			return node
		return _last(node.right)
		
	return _last(self.root)
```

## `before(node)` - Find the inorder predecessor

1. Check if the node has a left child. If yes, go to the left child, then follow right children until reaching the rightmost node. This is the predecessor.
2. If there is no left child, we need to find an ancestor that is the last node we turned right from to reach the given node. Start from the root, and initialise `pred = None`. Walk down the tree: if node.key > current key -> update `pred = current`, then go right. If node.key < current.key -> go left. If node.key == current.key -> stop.
3. Return the `pred` node.
**Note:** This works because the predecessor is either the largest node in the left subtree or the nearest ancestor smaller than the node.

```python
def before(self, node):
	
	if not node:
		return None
		
	if node.left:
		return self.last(node.left)
		
	def _before(node):
		
		if not node or not node.parent:
			return None
			
		if node.parent.right == node:
			return node.parent
			
		return _before(node.parent)
		
	return _before
```


# Merge sort
```python
FUNCTION merge_sort(list):

	IF length of list <= 1:
		RETURN list
		
	mid = length of list // 2
	left = merge_sort(:mid)
	right = merge_sort(mid:)
	
	RETURN merge(left, right)
	
FUNCTION merge(left, right):
	result = empty list
	i = j = 0
	
	WHILE left[i] < length(left) and right[i] < length(right):
		IF left[i] <= right[j]:
			i += 1
		ELSE:
			append right [j] to result
			j = j + 1
			
	APPEND all remaining elements of left[i:] to result
	APPEND all remaining elements of right[j:] to result
```

# Quick sort
```python
DEFINE parition(list, low, high):
	pivot = list[high]
	i = low - 1
	
	for j in the range(low, high):
		INCREMENT i
		if list[j] <= pivot:
			REVERSE list[i] AND list[j]
	REVERSE list[i+1] AND list[high]
	RETURN i + 1
	
DEFINE quicksort(list, low=0, high=None):
	IF high is None:
		high = length of list - 1
		
	if low < high:
		pivot = partition(list, low, high)
		quicksort(list, low, pivot - 1)
		quicksort(list, pivot + 1, high)
		
	RETURN list
```

