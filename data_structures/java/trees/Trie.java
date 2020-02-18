package data_structures.java.trees;

public class Trie {
    public class TrieNode {
        TrieNode[] child;
        boolean end;

        public TrieNode() {
            child = new TrieNode[26];
            end = false;
        }
    }

    private final TrieNode root;

    public Trie() {
        root = new TrieNode();
    }

    public void insert(String word) {
        TrieNode currentNode = root;
        for (int i = 0; i < word.length(); i++) {
            TrieNode node = currentNode.child[word.charAt(i) - 'a'];
            if (node == null) {
                node = new TrieNode();
                currentNode.child[word.charAt(i) - 'a'] = node;
            }
            currentNode = node;
        }
        currentNode.end = true;
    }

    public boolean search(String word) {
        TrieNode currentNode = root;
        for (int i = 0; i < word.length(); i++) {
            char ch = word.charAt(i);
            TrieNode node = currentNode.child[ch - 'a'];
            if (node == null) {
                return false;
            }
            currentNode = node;
        }
        return currentNode.end;
    }

    public boolean startsWith(String prefix) {
        TrieNode currentNode = root;
        for (int i = 0; i < prefix.length(); i++) {
            char ch = prefix.charAt(i);
            TrieNode node = currentNode.child[ch - 'a'];
            if (node == null) {
                return false;
            }
            currentNode = node;
        }
        return true;
    }

    public boolean delete(String word) {
        TrieNode currentNode = root;
        for (int i = 0; i < word.length(); i++) {
            char ch = word.charAt(i);
            TrieNode node = currentNode.child[ch - 'a'];
            if (node == null) {
                return false;
            }
            currentNode = node;
        }
        if (currentNode.end == true) {
            currentNode.end = false;
            return true;
        }
        return false;
    }

    public static void sop(String print) {
        System.out.println(print);
    }

    public static void main(String[] args) {
        Trie trie = new Trie();
        String word1 = "cook";
        String word2 = "code";
        trie.insert(word1);
        trie.insert(word2);
        System.out.println(trie.search(word1));
        System.out.println(trie.search(word2));
        System.out.println(trie.search("coke"));
        System.out.println(trie.startsWith("co"));
    }
}