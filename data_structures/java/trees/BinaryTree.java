package data_structures.java.trees;

import java.util.LinkedList;
import java.util.Queue;

public class BinaryTree {
    class Node {
        public int data;
        public Node left;
        public Node right;
        public Node parent;

        public Node(int value) {
            data = value;
            left = null;
            right = null;
            parent = null;
        }
    }

    private Node root;

    public BinaryTree() {
        root = null;
    }

    public Node find(int key) {
        Node current = root;
        while (current != null) {
            if (current.data == key) {
                return current;
            } else if (current.data > key) {
                current = current.left;
            } else {
                current = current.right;
            }
        }
        return null;
    }

    private Node findParent(int value) {
        Node current = root;
        while (current != null) {
            if (current.data == value) {
                // return current if exactly match.
                return current;
            } else if (current.data > value) {
                if (current.left == null) {
                    return current;
                }
                current = current.left;
            } else {
                if (current.right == null) {
                    return current;
                }
                current = current.right;
            }
        }
        return null;
    }

    public void put(int value) {
        Node newNode = new Node(value);
        if (root == null) {
            root = newNode;
        } else {
            Node parent = findParent(value);
            if (value < parent.data) {
                parent.left = newNode;
                parent.left.parent = parent;
                return;
            } else {
                parent.right = newNode;
                parent.right.parent = parent;
                return;
            }
        }
    }

    public Node getRoot() {
        return root;
    }

    public void inOrder(Node localRoot) {
        if (localRoot != null) {
            inOrder(localRoot.left);
            System.out.print(localRoot.data + " ");
            inOrder(localRoot.right);
        }
    }

    public void preOrder(Node localRoot) {
        if (localRoot != null) {
            System.out.print(localRoot.data + " ");
            preOrder(localRoot.left);
            preOrder(localRoot.right);
        }
    }

    public void postOrder(Node localRoot) {
        if (localRoot != null) {
            postOrder(localRoot.left);
            postOrder(localRoot.right);
            System.out.print(localRoot.data + " ");
        }
    }

    public void levelOrder(Node localRoot) {
        Queue<Node> queue = new LinkedList<Node>();
        queue.offer(localRoot);
        Node current = queue.poll();
        while (current != null) {
            System.out.println(current.data);
            System.out.println();
            if (current.left != null) {
                queue.offer(current.left);
            }
            if (current.right != null) {
                queue.offer(current.right);
            }
            current = queue.poll();
        }
    }

    public static void main(String[] args) {
        int[] array = { 4, 5, 6, 7, 1, 2, 3 };
        BinaryTree tree = new BinaryTree();
        for (int i = 0; i < array.length; i++) {
            tree.put(array[i]);
        }
        tree.levelOrder(tree.getRoot());
    }
}