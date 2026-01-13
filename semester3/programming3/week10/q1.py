class TreeNode:

    def __init__(self, key, value, parent=None):
        self.key = key
        self.value = value
        self.left = None
        self.right = None
        self.parent = parent

    def __repr__(self):
        left_key = self.left.key if self.left else None
        right_key = self.right.key if self.right else None
        parent_key = self.parent.key if self.parent else None
        return f"key: {self.key}, value: {self.value}, left: {left_key}, right: {right_key}, parent: {parent_key}"

    def height(self):
        if self is None:
            return 0
        return 1 + max(self.left.height(), self.right.height())

    def is_balanced(self):
        lheight = self.left.height() if self.left else 0
        rheight = self.right.height() if self.right else 0

        if abs(lheight - rheight) > 1:
            return False

        

        return self.left.is_balanced() and self.right.is_balanced()


root = TreeNode(10, '10_val')
node20 = TreeNode(20, '20_val', root)
root.right = node20
node30 = TreeNode(30, '30_val', node20)
node20.right = node30

# Test is_balanced
print("\nIs the tree balanced (Initially)?")
print(root.is_balanced(), end="\n\n")