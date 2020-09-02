package leetcode.java;

public class Flatten {
    public static void flatten(TreeNode root) {
        while (root != null) {
            if (root.left == null) {
                root = root.right;
            } else {
                TreeNode pre = root.left;
                while (pre.right != null) {
                    pre = pre.right;
                }
                pre.right = root.right;
                root.right = root.left;
                root.left = null;
                root = root.right;
            }
        }
    }

    public static void main(String[] args) {
        TreeNode root = new TreeNode(1);
        root.left = new TreeNode(2);
        root.right = new TreeNode(3);
        root.left.left = new TreeNode(4);
        root.print(root);
        flatten(root);
        root.print(root);
    }
}

class TreeNode {
    TreeNode left;
    TreeNode right;
    int value;

    public TreeNode(int value) {
        this.value = value;
    }

    public void print(TreeNode root) {
        if (root != null) {
            System.out.println(root.value);
            print(root.left);
            print(root.right);
        }
    }
}