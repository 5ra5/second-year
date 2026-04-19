import java.util.HashMap;
import java.util.Map;

class TrieNode {
    char value;
    Map<Character, TrieNode> children;
    boolean isLeaf;

    TrieNode(char value) {
        this.value = value;
        this.children = new HashMap<>();
        this.isLeaf = false;
    }

    void markAsLeaf() {
        isLeaf = true;
    }
}

public class PrefixTree {
    private TrieNode root;

    public PrefixTree() {
        root = new TrieNode('\0');
    }

    public void insert(String word) {
        TrieNode current = root;

        for (char ch : word.toCharArray()) {
            if (!current.children.containsKey(ch)) {
                current.children.put(ch, new TrieNode(ch));
            }
            current = current.children.get(ch);
        }

        current.markAsLeaf();
    }

    public boolean search(String word) {
        TrieNode node = findNode(word);
        return node != null && node.isLeaf;
    }

    public boolean startsWith(String prefix) {
        return findNode(prefix) != null;
    }

    private TrieNode findNode(String text) {
        TrieNode current = root;

        for (char ch : text.toCharArray()) {
            if (!current.children.containsKey(ch)) {
                return null;
            }
            current = current.children.get(ch);
        }

        return current;
    }

    public void traverse() {
        traverseRecursive(root, 1);
    }

    private void traverseRecursive(TrieNode node, int depth) {
        for (TrieNode child : node.children.values()) {
            for (int i = 0; i < depth; i++) {
                System.out.print("  ");
            }

            System.out.print("└── " + child.value);

            if (child.isLeaf) {
                System.out.print(" (end)");
            }

            System.out.println();

            traverseRecursive(child, depth + 1);
        }
    }
}